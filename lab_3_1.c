#include <stdio.h>
#include <Windows.h>
#include <math.h>

void n1() {
	int i = 1;
	do {
		printf("%d ", i);
		i++;
	} while (i <= 10);
}

void n2() {
	int i = 10;
	do {
		printf("%d ", i);
		i--;
	} while (i >= 1);
}


void n3() {
	int i = 0;
	int n = 1;
	do {
		printf("%d ", n);
		n+=2;
		i++;
	} while (i <= 4);
}

void n4() {
	int a = 100;
	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
}

void n5() {
	int a = 1000;
	while (a >= 100) {
		printf("%d ", a);
		a -= 100;
	}
}

void n_2_2_3() {
	int r; printf("введите сумму вклада:");
	scanf_s("%d", &r);
	printf("\n");
	double n; printf("введите процент:");
	scanf_s("%lf", &n);
	n *= 0.01;
	int t = 1;


	do {
		printf("\n%d год: %.2f руб.\n", t, r * pow(1 + n, t));
		t++;
	} while (t <= 10);
}


void n21() {
	int n;
	int k = 1;
	int i=1;
	scanf_s("%d", &n);
	while (i <= n) {
		printf("%d ", k);
		k *= i;
		i++;
	}
}


void n31() {
	int n; scanf_s("%d", &n);
	int a = 0;
	int b = 1;
	int next = a + b;

	
	if (n < 0) {
		goto end;
	}
	printf("%d ", a);
	if (b > n) {
		goto end;
	}
	printf("%d ", b);

	while (next <= n) {
		printf("%d ", next);
		a = b;
		b = next;
		next = a + b;
	}
	end:
		printf("\n");
}

/*
void main() {
	SetConsoleOutputCP(65001);
	int n=99;

	do {
		printf("\n\n");
		printf("Выберете действие:\n");
		printf("1: Вывести числа от 1 до 10\n");
		printf("2: Вывести числа от 10 до 1\n");
		printf("3: Вывести 5 первых нечётных чисел начиная с 1\n");
		printf("11: Вывести 100 90 80... 10(через WHILE)\n");
		printf("12: Вывести 1000 900 800... 100(через WHILE)\n");
		printf("13: Cумма вклада\n");
		printf("21: Факториалы чисел\n");
		printf("31: Числа фибоначи\n\n");
		printf("0: Выход\n\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			n1();
			break;
		case 2:
			n2();
			break;
		case 3:
			n3();
			break;
		case 11:
			n4();
			break;
		case 12:
			n5();
			break;
		case 13:
			n_2_2_3();
			break;
		case 21:
			n21();
			break;
		case 31:
			n31();
			break;
		case 0:
			printf("Завершение работы...\n");
			break;
		default:
			printf("Данные некорректны. Попробуйте еще раз.\n");
			break;
		}
	} while (n != 0);
}*/