#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define num_elements 10


int arr[num_elements];
int n = 0;

void printElements() {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


void keyboardInput() {
	printf(" n = ");
	scanf_s("%d", &n);


	printf(" введите %d значений ​​: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}


int findMin() {
	int a = 0;
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			a = i;
		}
	} return a;
}

int fandLastEver() {
	int a = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			a = i;
		}
	}return a;
}

int over10() {
	int a = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			a++;
		}
	}return a;
}

void deleteElement(int delIndex) {
	for (int i = delIndex; i < n - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void insertElement(int insIndex, int value) {
	for (int i = n; i > insIndex;--i) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[insIndex] = value;
}

void Laod(){
	int i;

	FILE* fin = fopen("C:\\Users\\User\\Desktop\\in.txt", "rt");
	if (fin == NULL) {
		printf("not open\n");
		return;
	}
	fscanf(fin, "%d", &n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &arr[i]);
	}
	fclose(fin);

}

void Save() {
	int i;

	FILE* fout;
	fout = fopen("C:\\Users\\User\\Desktop\\out.txt", "wt");
	if (fout == NULL) {
		printf("not open\n");
		return;
	}

	fprintf(fout, "%d\n", n);

	for (i = 0; i < n; i++) {
		fprintf(fout, "%d ", arr[i]);
	}
	fclose(fout);

}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("-------------------------------\n");
		printf("Cодержимое массива:\n");
		printElements();
		printf("\n");
		printf("Выберите нужную вам операцию: \n");
		printf("1: Ввести с клавиатуры массив \n");
		printf("2: x10 для всех нечётных элементов \n");
		printf("3: найти минимальный элемент \n");
		printf("4: сколько элементов больше 10 \n");
		printf("5: увеличеть в 2 раза последний чётный\n");
		printf("6: сколько левее min чётных элементов\n");
		printf("7: все чётные элементы массива *-1\n");
		printf("8: если <4 заменить на 4\n");
		printf("11: удалить заданный элемент\n");
		printf("12: вставить элемент в задонное место\n");
		printf("13: удалить минимальный элемент\n");
		printf("14: перед минимальным элементом вставить 0\n");
		printf("15: ввести массив из файла\n");
		printf("16: сохранить массив в файл\n");
		printf("файл должен быть в формате:\nn(кол-во элементов)\na[1] a[2] a[3] ... a[n]\n");
		printf("\n");
		printf("0: Выйти из праграммы \n");
		printf("Выбраная операция »»»»»»»>\n");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int a = findMin();
			printf("min=%d\n", arr[a]);
		}
		break;

		case 4:
		{
			int t = over10();
			printf("больше 10 %d элементов\n", t);
			break;
		}

		case 5:
		{
			int index = fandLastEver();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;

		case 6:
		{
			int index = findMin();


			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("левее min %d чётных элементов", cnt);
		}
		break;
		case 7:
		{
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 == 0) {
					arr[i] *= -1;
				}
			}
			break;
		}
		case 8:
		{
			for (int i = 0; i < n; i++) {
				if (arr[i] < 4) {
					arr[i] = 4;
				}
			}
		}
			break;
		case 11:
		{
			printf(" Индекс удаляемого лемента = ");
			int index;
			scanf_s("%d", &index);

			deleteElement(index);
		}
		break;

		case 12:
		{
			printf(" пepед каким элементом нужно вставить новый ? индекс = ");
			int index;
			scanf_s("%d", &index);

			printf(" 3начение , которое нужно вставить = ");
			int value;
			scanf_s("%d", &value);

			insertElement(index, value);
		}
		break;

		case 13:
		{
			int a = findMin();
			deleteElement(a);
			break;
		}
		case 14:
		{
			int a = findMin();
			insertElement(a, 0);
		}
		break;

		case 15:
			Laod();
		break;

		case 16:
			Save();
		break;

		}
	} while (item != 0);
}