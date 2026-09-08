#include <stdio.h>
#include <Windows.h>


void n2_1_1() {
	int fn, sn;
	printf("Введите первое число: ");
	scanf_s("%d", &fn);
	printf("Введите второе число: ");
	scanf_s("%d", &sn);
	printf("\n");

	if (fn > sn) {
		printf("Большее число: %d \n", fn);
		printf("Меньшее число: %d \n", sn);
	}
	else {
		printf("Большее число: %d \n", sn);
		printf("Меньшее число: %d \n", fn);
	}
	printf("\n");printf("\n");
}


void n2_1_2() {
	int fn, sn, tn;
	printf("Введите три числа: ");
	scanf_s("%d%d%d", &fn, &sn, &tn);
	printf("\n");

	if (fn >= sn && fn >= tn) { printf("Большее число: %d \n", fn); }
	else if (sn >= fn && sn >= tn) { printf("Большее число: %d \n", sn); }
	else { printf("Большее число: %d \n", tn); }
	printf("\n");printf("\n");
}


void n2_1_3() {
	float temp;
	printf("Введите температуру: ");
	scanf_s("%f", &temp);
	printf("\n");
	
	if (temp < 18) { printf("холодно"); }
	else if (temp > 18 && temp <22) { printf("прохладно"); }
	else if (temp > 22 && temp < 26) { printf("тепло"); }
	else { printf("жарко"); }
	printf("\n");
	printf("\n");
	printf("\n");
}


void n2_1_4() {
	int fn, sn, tn, fort_n, fift_n;
	printf("Введите пять чисел: ");
	scanf_s("%d%d%d%d%d", &fn, &sn, &tn, &fort_n, &fift_n);
	printf("\n");

	if (fn >= sn && fn >= tn && fn >= fort_n && fn >= fift_n) { printf("Большее число: %d \n", fn); }
	else if (sn >= fn && sn >= tn && sn >= fort_n && sn >= fift_n) { printf("Большее число: %d \n", sn); }
	else if (tn >= fn && tn >= sn && tn >= fort_n && tn >= fift_n) { printf("Большее число: %d \n", tn); }
	else if (fort_n >= fn && fort_n >= tn && fort_n >= sn && fort_n >= fift_n) { printf("Большее число: %d \n", fort_n); }
	else { printf("Большее число: %d \n", fift_n); }
	printf("\n");
	printf("\n");
}


void mountains_2_1_5() {
	float temp;
	printf("Введите температуру в горах: ");
	scanf_s("%f", &temp);
	printf("\n");

	if (temp <= -30) {
		printf("мороз, высокий уровень опасности обморожения");
	}
	else if (temp > -30 && temp <= -15) {
		printf("холодно, приемлемо для продвижения");
	}
	else if (temp > -15 && temp <= -5) {
		printf("тепло, идеальная температура для восхождения");
	}
	else {
		printf("жарко, высокий риск схода лавины");
	}

	printf("\n\n\n");
}


void pivko_2_1_6() {
	float price;
	printf("Введите цену на пиво(руб): ");
	scanf_s("%f", &price);
	printf("\n");

	if (price <= 150 && price >= 110) {
		printf("дорого богато");
	}
	else if (price >= 30 && price <= 60) {
		printf("дёшево бедняво");
	}
	else if (price > 60 && price < 110) {
		printf("нормально");
	}
	else {
		printf("не верю, покажи *_*");
	}

	printf("\n\n\n");
}


void main() {
	SetConsoleOutputCP(65001);
	//n2_1_1();
	//n2_1_2();
	//n2_1_3();
	//n2_1_4();
	//mountains_2_1_5();
	//pivko_2_1_6();
}
