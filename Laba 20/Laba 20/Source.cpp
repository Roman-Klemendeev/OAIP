#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


#define N 8
#define M 10

int arr[N][M] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int n = 3;
int m = 3;
int num = 0;
int iMax = 0;
int jMax = 0;

void print() {
	printf("\n\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fillIx10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}

void fillZero() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

void randFill0_9() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void NeChetDel10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 != 0) {
				arr[i][j] *= 10;
			}
		}
	}
}

void Krat10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}

void vvesteSkeyboard() {
	int a;
	printf("введите кол-во строк\n");
	scanf_s("%d", &n);
	printf("введите кол-во столбцов\n");
	scanf_s("%d", &m);
	printf("введите по одному чису\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &a);
			arr[i][j] = a;
		}
	}
}

void save() {
	FILE* fout = fopen("C:\\Users\\user\\Desktop\\in1.txt", "wt");
	if (fout == NULL) {
		printf("not open");
		return;
	}
	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
}

void load() {
	FILE* fin = fopen("C:\\Users\\user\\Desktop\\in1.txt", "rt");
	if (fin == NULL) {
		printf("not open");
		return;
	}
	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}
	fclose(fin);
}

void deleteRow(int delRow) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}

void copyRow(int copyRow) {

	n++;

	for (int i = n; i > num; i--) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
}

void findMax() {
	int max = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				iMax = i;
				jMax = j;
			}
		}
	}
}

int findMaxColumn(int columnNum) {
	int maxI = arr[0][columnNum];
	for (int i = 0; i < n; i++) {
		if (maxI < arr[i][columnNum]) {
			maxI = arr[i][columnNum];
		}
	}
	return maxI;
}

void A5() {
	findMax();
	for (int i = iMax + 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = findMaxColumn(j);
		}
	}
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int index = -1;

	do {
		print();
		printf("-------------------\n");
		printf("Выберите нужную операцию\n");
		printf("1: заполнить значениями i*10+j\n");
		printf("2: заполнить нулями\n");
		printf("3: заполнить случайными числами\n");
		printf("4: все нечётные увеличить на 10\n");
		printf("5: все крадные 10 уменьшить на 10\n");
		printf("6: ввести массив с клавиятуры\n");
		printf("7: сохранить массив в файл\n");
		printf("8: загрузить массив из файла\n");
		printf("9: удалить заданную строку из массива\n");
		printf("10: продублировать задданую строку\n");
		printf("11: А5\n");

		printf("\n0: Выйти из программы\n");
		printf("Выбранная операция\n");

		scanf_s("%d", &index);

		switch (index) {
		case 1:
			fillIx10();
			break;

		case 2:
			fillZero();
			break;
		case 3:
			randFill0_9();
			break;
		case 4:
			NeChetDel10();
			break;
		case 5:
			Krat10();
			break;
		case 6:
			vvesteSkeyboard();
			break;
		case 7:
			save();
			break;
		case 8:
			load();
			break;
		case 9:
			printf("какую строку удалить?");
			scanf_s("%d", &num);
			deleteRow(num);
			break;
		case 10:
			printf("какую строку дублировать?");
			scanf_s("%d", &num);
			copyRow(num);
			break;
		case 11:
			A5();
			break;
		}
	} while (index != 0);
}