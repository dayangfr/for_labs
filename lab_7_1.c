#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int isDigitMyOwnFunctionSukaBlyat(char c) {
	if (c >= '0' && c <= '9') return 1;
	return 0;	
}



void n_7_1_1() {
	printf("ВВедите символ: ");
	int ch = getchar();
	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}

void n_7_1_2() {
	printf("Введите символ =");
	int ch = getchar();
	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}

void n_7_1_3() {
	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') cnt++;
	}

	printf("\nВ ней %d пробелов\n", cnt);

	{
		int x;
		scanf("%d", &x);
	}
}
void n_7_1_4() {
	
	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			s[i] = '#';
		}
	}
	printf("Изменённая строчка: %s\n\n\n", s);
}
void n_7_1_5_1() {

	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i])) s[i] = '$';
	}
	printf("Изменённая строчка: %s\n\n\n", s);
}

void n_7_1_5_2() {

	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (isDigitMyOwnFunctionSukaBlyat(s[i])) s[i] = '$';
	}
	printf("Изменённая строчка: %s\n\n\n", s);
}
void n_7_1_6() {

	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);
	for (int i = 0; s[i] != '\0'; i++) s[i] = toupper(s[i]);
	printf("Изменённая строчка: %s\n\n\n", s);
}

void n_7_1_7() {

	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i])==0) s[i] = 'X';
	}
	printf("Изменённая строчка: %s\n\n\n", s);
}
/*
void main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	//n_7_1_1();
	//n_7_1_2();
	//n_7_1_3();
	//n_7_1_4();
	//n_7_1_5_1();
	//n_7_1_5_2();
	//n_7_1_6();
	//n_7_1_7();

}*/