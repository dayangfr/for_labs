#include <stdio.h>
#include <Windows.h>
#include <math.h> 


void n_2_2_1() {
	int i=1;
	int n;
	printf("n = ");
	scanf_s("%d", &n);
	do { 
		printf("%d", i);
		i++; 
	} while (i <= n);
}

void n_2_2_2() {
	int i = 0; 
	do { 
		printf("2^%d = %.0f\n", i, pow(2, i));
		i++; 
	} while (i < 6);
}

/*
void n_2_2_3() {
	int r; printf("введите сумму вклада:");
	scanf_s("%d", &r);
	printf("\n");
	double n; printf("введите процент:");
	scanf_s("%lf", &n);
	n *= 0.01;
	int t = 1;


	do {
		printf("\n%d год: %.2f руб.\n", t, r*pow(1 + n, t));
		t++;
	} while (t <= 10);
}
*/

void n_2_2_4() {
	int n;
	printf("n = ");
	scanf_s("%d", &n);
	int i = 1;
	int num = 2;
	

	do {
		printf("%d ", num); num += 2;
		i++;
	} while (i <= n);
}


void n_2_2_5() {
	int n;
	int a;
	int i = 1;
	int k = 2;
	printf("n = ");
	scanf_s("%d", &n);
	printf("a = ");
	scanf_s("%d", &a);
	
	do {
		if (k % a == 0) {
			printf("%d ", k);
			i++;
		}
		k++;
	} while (i <= n);
}


void treugolnik() {
	int n;
	scanf_s("%d", &n);
	int i = 1;
	int j = 0;
	printf("*\n");
	do {
		do {
			printf("*");
			j++;
		}while (j <= i);
		printf("\n");
		i++; 
		j = 0;
	} while (i < n);
}
/*
void main() { // спросить про int main
	SetConsoleOutputCP(65001);
	//n_2_2_1();
	//n_2_2_2();
	//n_2_2_3();
	//n_2_2_4();
	//n_2_2_5();
	treugolnik();
}*/

