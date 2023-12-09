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
	if (c >= 'а' && c <= 'п')
		new_c = 'А' + (c - 'а');
	if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	char s[80];
	printf(" Введите строку : ");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку s = \%s\" ", s);
	
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