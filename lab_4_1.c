#include <stdio.h>
#include <Windows.h>
#include <math.h>


int visokos(int year) {
	if (year % 400 == 0) return 1;
	if (year % 100 == 0) return 0;
	if (year % 4 == 0) return 1;
	return 0;
}

void visokos_start() {
	int n, k, num;
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	num = n;
	do {
		if (visokos(num))
			printf("%d\t", num);
		num++;
	} while (num <= k);
	printf("\n\n");
}


int is_prime(int n) {
	if (n < 2) return 0;

	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) return 0;
		i++;
	}

	return 1;
}

void is_prime_start() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	
	int i = a;
	do {
		if (is_prime(i)) {
			printf("%d ", i);
		}
		i++;
	} while (i <= b);
	printf("\n\n");

}
int sumDigits(int num) {
	int sum = 0;
	num = abs(num); 

	while (num > 0) {
		sum += num % 10;
		num /= 10;       
	}

	return sum;
}

void masumDigitsin_start() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	int i = a;
	while (i <= b) {
		printf("Сумма цифр(%d) = %d\n", i, sumDigits(i));
		i++;
	}
}
int speedlimit_greece(int cur_sp, int lim) {
	int dif = cur_sp - lim;
	if (dif >= 1 && dif <= 20) {
		return 40;
	} 
	else if (dif >= 21 && dif <= 30) {
		return 100;
	} 
	else if (dif >= 31) {
		return 350;
	}
	return 0;
}

void speedlimit_greece_start() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	int shtraf = speedlimit_greece(a, b);
	if (shtraf == 40) {
		printf("штраф 40€");
	} 
	else if (shtraf == 100) {
		printf("штраф 100€");
	}
	else if (shtraf == 350) {
		printf("штраф 350€ + лишение водительских прав");
	}
	else {printf("всё ок");}
	printf("\n\n");
}

int find_nod(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b; 
		a = temp;
	}
	return a; 
}

void find_nod_start() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	int nod = find_nod(a, b);

	printf("НОД чисел %d и %d равен: %d\n", a, b, nod);
	printf("\n\n");
}

int calculate_tax(double money) {
	double tax = 0.0;
	if (money <= 84120) {
		tax += money * 0.10;
		return tax;
	}
	else {
		tax += 84120 * 0.10;
	}

	if (money <= 120720) {
		tax += (money - 84120) * 0.14;
		return tax;
	}
	else {
		tax += (120720 - 84120) * 0.14;
	}

	if (money <= 228000) {
		tax += (money - 120720) * 0.20;
		return tax;
	}
	else {
		tax += (228000 - 120720) * 0.20;
	}

	if (money <= 301200) {
		tax += (money - 228000) * 0.31;
		return tax;
	}
	else {
		tax += (301200 - 228000) * 0.31;
	}

	if (money <= 560280) {
		tax += (money - 301200) * 0.35;
		return tax;
	}
	else {
		tax += (560280 - 301200) * 0.35;
	}

	if (money <= 721560) {
		tax += (money - 560280) * 0.47;
		return tax;
	}
	else {
		tax += (721560 - 560280) * 0.47;
	}

	tax += (money - 721560) * 0.50;

	return tax;
}


void calculate_tax_start() {
	double m;
	double raw_tax, final_tax;
	double tax_credit = 2.25 * 2904.0;
	printf("Введите годовой доход (в шекелях): ");
	scanf_s("%lf", &m);
	raw_tax = calculate_tax(m);
	final_tax = raw_tax - tax_credit;
	if (final_tax < 0) {
		final_tax = 0; 
	}
	printf("Итоговый подоходный налог к уплате в год: %.2f шек.\n", final_tax);
	printf("Приблизительно в месяц: %.2f шек.\n", final_tax / 12.0);
}

/*
void main() {
	SetConsoleOutputCP(65001);
	visokos_start();
	is_prime_start();
	masumDigitsin_start();
	speedlimit_greece_start();
	calculate_tax_start();
}
*/