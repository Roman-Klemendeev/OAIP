#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int a[1000];
int *pa;
int n;

void Load(){

	FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\in19.txt", "rt");
	if (fin == NULL) {
		printf("not open\n");
		return;
	}
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]);
	}
	fclose(fin);
}

void SaveResult() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > sa) {
			m++;
		}
	}

	FILE* fout;
	fout = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\out19.txt", "wt");
	if (fout == NULL) {
		printf("not open\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (a[i] > sa) {
			fprintf(fout, "%d ", a[i]);
		}
	}
	fclose(fout);

}

void load() {

	FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\in20.txt", "rt");
	if (fin == NULL) {
		printf("not open\n");
		return;
	}
	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void saveresult() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			m++;
		}
	}

	FILE* fout;
	fout = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\out20.txt", "wt");
	if (fout == NULL) {
		printf("not open\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
}

void LOad() {
	FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\in21.txt", "rt");
	if (fin == NULL) {
		printf("not open\n");
		return;
	}
	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void Saveresult() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] < sa) {
			if (pa[i] > 0) {
				m++;
			}
		}
	}

	FILE* fout;
	fout = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\out21.txt", "wt");
	if (fout == NULL) {
		printf("not open\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] < sa) {
			if (pa[i] > 0) {
				fprintf(fout, "%d ", pa[i]);
			}
		}
	}
	fclose(fout);
}

void LOAd() {
	FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\in22.txt", "rt");
	if (fin == NULL) {
		printf("not open\n");
		return;
	}
	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void SAveresult() {
	float sa = 0;
	float s = 0;

	int max = pa[0];
	for (int i = 1; i < n; i++) {
		if (max < pa[i]) {
			max = pa[i];
		}
	}
	int max23 = max * 2 / 3;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] >= max23) {
			m++;
		}
	}

	FILE* fout;
	fout = fopen("C:\\Users\\rklem\\OneDrive\\Рабочий стол\\out22.txt", "wt");
	if (fout == NULL) {
		printf("not open\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] >= max23) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//#1
	Load();
	SaveResult();

	//#2
	load();
	saveresult();

	free(pa);

	//#3
	LOad();
	Saveresult();
	
	free(pa);

	//#4
	LOAd();
	SAveresult();

	free(pa);
}