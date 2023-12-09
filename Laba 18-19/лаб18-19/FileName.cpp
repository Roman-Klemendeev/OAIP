#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item;
	printf("��� ������ 1 ������� 1\n");
	printf("��� ������ 2 ������� 2\n");
	printf("��� ������ 3 ������� 3\n");
	printf("��� ������ 4 ������� 4\n");
	printf("��� ������ 5 ������� 5\n");
	printf("��� ������ 6 ������� 6\n");

	scanf_s("%d", &item);

	switch (item) {
	case 1:
	{
		int a, b, c;
		int p;

		FILE* fout;
		fout = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\num1.txt", "wt");
		if (fout == NULL) {
			printf("not open\n");
			return;
		}

		printf("������� �����\n");
		scanf_s("%d%d%d", &a, &b, &c);
		printf("�����: %d %d %d\n", a, b, c);
		p = a * b * c;
		printf("p =  %d\n", p);


		fprintf(fout, "p=%d", p);
		fclose(fout);
	}
	break;
	
	case 2:
	{
		int a=0, b=0, c=0;
		int p;

		FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\in2.txt", "rt");
		if (fin == NULL) {
			printf("not open\n");
			return;
		}
		
		fscanf(fin, "%d%d%d", a, b, c);
		fclose(fin);

		printf("a= %d,b= %d,c= %d\n", a, b, c);
		p = a * b * c;
		printf("p =  %d\n", p);
		
		FILE* fout;
		fout = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\out2.txt", "wt");
		if (fout == NULL) {
			printf("not open\n");
			return;
		}

		fprintf(fout, "p=%d", p);
		fclose(fout);

	}
	break;

	case 3:
	{
		int a, b, c, d, e;
		int p;

		printf("������� �����\n");
		scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
		printf("�����: %d %d %d %d %d\n", a, b, c, d, e);
		p = a + b + c + d + e;
		printf("p =  %d\n", p);
	}
	break;

	case 4:
	{
		int a, b, c, d, e;
		int p;

		FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\in4.txt", "rt");
		if (fin == NULL) {
			printf("not open\n");
			return;
		}

		fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
		fclose(fin);

		printf("a= %d,b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);
		p = a + b + c + d + e;
		printf("p =  %d\n", p);

		FILE* fout;
		fout = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\out4.txt", "wt");
		if (fout == NULL) {
			printf("not open\n");
			return;
		}

		fprintf(fout, "p=%d", p);
		fclose(fout);
	}
	break;

	case 5:
	{
		int a[10];
		int n;
		int i;

		FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\in5.txt", "rt");
		if (fin == NULL) {
			printf("not open\n");
			return;
		}
		fscanf(fin, "%d", &n);

		for (i = 0; i < n; i++) {
			fscanf(fin, "%d", &a[i]);
		}
		fclose(fin);

		printf("\na[%d] = ", n);
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}

		int s = 0;
		for (i = 0; i < n; i++) {
			s += a[i];
		}

		float sa = (float)s / n;

		printf("\nsa = %f\n", sa);

		for (i = 0; i < n; i++) {
			if (a[i] > sa) {
				a[i] *= 10;
			}
		}

		printf("\na[%d] = ", n);
		for (i = 0; i < n; i++) {
			printf("  %d ", a[i]);
		}

		FILE* fout;
		fout = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\out5.txt", "wt");
		if (fout == NULL) {
			printf("not open\n");
			return;
		}
		
		fprintf(fout, "%d\n", n);

		for (i = 0; i < n; i++) {
			fprintf(fout, "%d ", a[i]);
		}
		fclose(fout);

	}
	break;

	case 6:
	{
		int a[10];
		int n;
		int i;

		FILE* fin = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\in6.txt", "rt");
		if (fin == NULL) {
			printf("not open\n");
			return;
		}
		fscanf(fin, "%d", &n);

		for (i = 0; i < n; i++) {
			fscanf(fin, "%d", &a[i]);
		}
		fclose(fin);

		printf("a[%d] = ", n);
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}

		int s = 0;
		for (i = 0; i < n; i++) {
			s += a[i];
		}

		float sa = (float)s / n;

		printf("\nsa = %f", sa);

		for (i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				if (a[i] < sa) {
					a[i] /=2 ;
				}
			}
		}

		printf("a[%d] = ", n);
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}

		FILE* fout;
		fout = fopen("C:\\Users\\rklem\\OneDrive\\������� ����\\out6.txt", "wt");
		if (fout == NULL) {
			printf("not open\n");
			return;
		}

		fprintf(fout, "%d\n", n);

		for (i = 0; i < n; i++) {
			fprintf(fout, "%d ", a[i]);
		}
		fclose(fout);

	}
	break;

	}while (item != 0);
}