#define _CRT_SECURE_NO_WARNINGS 
#include < stdio.h >
#include < Windows.h >
#include<ctype.h>


int isDigitMy(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int toUpperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c == '�')
		new_c = '�';
	return new_c;
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	char s[80];
	printf(" ������� ������ : ");
	fgets(s, 79, stdin);
	printf("\n�� ����� ������ s = \%s\" ", s);
	
	//for (int i = 0; s[i] != '\0'; i++) {
	//	if (isdigit(s[i]))
	//		s[i] = 's';
	//}

	//for (int i = 0; s[i] != '\0'; i++) {
	//	if (isDigitMy(s[i]))
	//		s[i] = 's';
	//}


	//for (int i = 0; s[i] != '\0'; i++) {
	//	s[i] = toupper(s[i]);
	//}
	//
	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toUpperAll(s[i]);
	}

	printf("%s", s);
}