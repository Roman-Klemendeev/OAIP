#define _CRT_SECURE_NO_WARNINGS 
#include < stdio.h >
#include < Windows.h >


void main() {


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char name[12];
	printf(" ������� ���� ��� : ");
	fgets(name, 11, stdin);
	printf(" ����������� ����, %s\n ", name);
	printf("\n\n\n");


	printf(" ������� ������ = ");
	int ch = getchar();
	for (int c = ch; c <= ch + 19; c++) {
		printf("%c (%d)\n ", c, c);
	}
	printf("\n\n\n");

	printf(" ������� ������ = ");
	int ch2 = getchar();
	for (int c = ch2; c >= ch2 - 29; c--) {
		printf("%c (%d)\n ", c, c);
	}
	printf("\n\n\n");


	char s[80];
	printf(" ������� ������ : ");
	fgets(s, 79, stdin);
	printf("\n�� ����� ������ s = \%s\"", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')cnt++;
	}
	printf("\nB ��� %d �������� \n ", cnt);


	char s2[80];
	printf(" ������� ������ : ");
	fgets(s2, 79, stdin);
	printf("\n�� ����� ������ s = \%s\"", s2);

	for (int i = 0; i < strlen(s2); i++) {
		if (s2[i] == ' ') {
			s2[i] = '#';
		}
	}
	printf("\n %s \n ", s2);
}
