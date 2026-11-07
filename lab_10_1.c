#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

// Задача 10.1.1 — Вычисление факториала
int faktorial_10_1_1(int n) {
    if (n == 0) return 1;
    long r = faktorial_10_1_1(n - 1) * n;
    return r;
}

// Задачи 10.1.2 и 10.1.3 — Простейшие рекурсивные функции
void rec1(int n) {
    printf(" %d", n);
    if (n > 1) {
        rec1(n - 2);
    }
}

void rec2(int n) {
    if (n > 1) {
        rec2(n - 2);
    }
    printf(" %d", n);
}

void rec3(int n) {
    printf(" %d", n);
    if (n > 1) {
        rec3(n - 2);
    }
    printf(" %d", n);
}

// Задача 10.1.4 — Пример по мотивам ЕГЭ №1
void recEGE1(int n) {
    if (n >= 1) {
        printf(" %d", n);
        recEGE1(n - 1);
        recEGE1(n - 1);
    }
}

// Задача 10.1.5 — Пример по мотивам ЕГЭ №2 (Демо 2017)
void F1(int n) {
    if (n > 2) {
        printf("%d\n", n);
        F1(n - 3);
        F1(n - 4);
    }
}

// Задача 10.1.6* — Пример по мотивам ЕГЭ №3 (Демо 2015)
void F2(int n) {
    printf("%d\n", n);
    if (n < 5) {
        F2(n + 1);
        F2(n + 3);
    }
}

// Задача 10.1.7 — Пример по мотивам ЕГЭ №4 (Демо 2016)
void G3(int n); // Объявление функции G3 для косвенной рекурсии

void F3(int n) {
    if (n > 0) {
        G3(n - 1);
    }
}

void G3(int n) {
    printf("*");
    if (n > 1) {
        F3(n - 3);
    }
}


void f_variant1(int n) {
    printf("<*%d*", n);
    if (n > 1) {
        f_variant1(n - 1);
    }
    printf("%d*>", n);
}
long long fast_power(int base, int exp) {
    if (exp == 0) return 1;

    if (exp % 2 == 0) {
        long long half = fast_power(base, exp / 2);
        return half * half;
    }
    else {
        return base * fast_power(base, exp - 1);
    }
}

void main() {
    SetConsoleOutputCP(65001);
    int item;
    int n, k;

    do {
        printf("\nВыберите пункт меню: ");
        if (scanf_s("%d", &item) != 1) {
            break;
        }

        switch (item) {
        case 1:
            printf("Результат факториала для n=4: %d\n", faktorial_10_1_1(4));
            break;

        case 2:
            rec1(11); printf(" rec1 FINISH\n");
            rec2(11); printf(" rec2 FINISH\n");
            rec3(11); printf(" rec3 FINISH\n");
            break; 

        case 3:
            rec1(7); printf(" rec1 FINISH\n");
            rec2(7); printf(" rec2 FINISH\n");
            rec3(7); printf(" rec3 FINISH\n");
            break; 

        case 4:

            recEGE1(3);
            printf("\n");
            break;

        case 5:

            F1(10);
            break;

        case 6:

            F2(1);
            break;

        case 7:

            F3(11);
            printf("\n");
            break;

        case 8:

            f_variant1(5);
            printf("\n");
            break;
        case 10:
            
            scanf_s("%d", &n);
            scanf_s("%d", &k);
            fast_power(n, k);
        default:

            exit(0);
        }
    } while (item != 0);
}
