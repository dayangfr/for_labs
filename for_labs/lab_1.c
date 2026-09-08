#include <stdio.h>
#include <math.h>
#include <Windows.h>


void cube_114() {
	printf("****************************\n");
	printf("*                          *\n");
	printf("*   _____          _____   *\n");
	printf("*     *       /      *     *\n");
	printf("*    ***     /      ***    *\n");
	printf("*     *     /        *     *\n");
	printf("*          /____           *\n");
	printf("*                          *\n");
	printf("*       __________/        *\n");
	printf("*                          *\n");
	printf("****************************\n");
	printf("\n");
	printf("\n");
}


void height_122() {
	float h;
	float g = 9.8;
	float t;

	printf("Введите высоту: ");
	scanf_s("%f", &h);
	printf("\n");

	t = sqrt(2 * h / g);

	printf("Скорость падения предмета равна %f\n", t);
	printf("\n");
	printf("\n");
}

void kvartira_124() {
	float s;
	int kv_m_price;
	float zp;
	float price;
	float time;

	printf("Введите площадь квартиры(м^2): ");
	scanf_s("%f", &s);
	printf("\n");
	printf("Введите стоимость квадратного метра данной квартиры(руб.): ");
	scanf_s("%d", &kv_m_price);
	printf("\n");
	printf("Введите свою заработную плату в месяц(руб.): ");
	scanf_s("%f", &zp);
	printf("\n");

	price = s * kv_m_price;
	printf("Стоимость данной квартиры равна: %.2f\n", price);
	printf("\n");

	time = price / (zp / 2);
	printf("На эту квартиру вам необходимо копить %.0f месяцев\n", time);
	printf("\n");
	printf("\n");
}

void vector_125() {
	float x1, y1, z1;
	float x2, y2, z2;

	float lenght;

	printf("Введите координаты начальной точки(каждая на новой строке в порядке x y z): \n");
	scanf_s("%f", &x1);
	scanf_s("%f", &y1);
	scanf_s("%f", &z1);
	printf("\n");

	printf("Введите координаты конечной точки(каждая на новой строке в порядке x y z): \n");
	scanf_s("%f", &x2);
	scanf_s("%f", &y2);
	scanf_s("%f", &z2);
	printf("\n");

	lenght = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
	printf("Длинна даного вектора равна: %.2f\n", lenght);
	printf("\n");
	printf("\n");
}

void kol_vo_teploty_126() {
	float q, c, m, del_t;
	printf("Введите удельную теплоемкость объекта(Дж/кг*°C): ");
	scanf_s("%f", &c);
	printf("\n");

	printf("Введите массу объекта(кг): ");
	scanf_s("%f", &m);
	printf("\n");

	printf("изменение температуры объекта(°C): ");
	scanf_s("%f", &del_t);
	printf("\n");

	q = c * m * del_t;

	printf("Количество теплоты которое получит объект равно %.2f\n", q);
	printf("\n");
	printf("\n");
}

void ipoteka_127() {
	float monthly_payment, loan_term, loan_amount, overpayment;
	printf("Введите ежемесячный платёж(руб.): ");
	scanf_s("%f", &monthly_payment);
	printf("\n");

	printf("Введите срок кредита(в месяцах): ");
	scanf_s("%f", &loan_term);
	printf("\n");

	printf("Введите сумму кредита(руб.): ");
	scanf_s("%f", &loan_amount);
	printf("\n");

	overpayment = (monthly_payment * loan_term) - loan_amount;

	printf("Переплата за данный кредит составит: %.2f\n", overpayment);
}

/*void main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cube_114();
	height_122();
	kvartira_124();
	vector_125();
	kol_vo_teploty_126();
	ipoteka_127();
}*/