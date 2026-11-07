#include <stdio.h>
#include <Windows.h>
#include <math.h>

void Task1() {
    printf("Task1() START\n");
    int n, m;
    scanf_s("%d", &n);
    scanf_s("%d", &m);
    int i = 1;
    int j = 1;
    
    while (i <= n) {
        j = 1;
        while (j <= m) {
            printf("%d ", i * 10 + j);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("Task1() FINISH\n");
}

void Task2() {
    printf("Task2() START\n");
    int i = 1;
    int j = 1;

    while (i<=10) {
        j = 1;
        while (j <= 10) {
            if (i*j<10){printf("%d  ", i * j);}
            else{printf("%d ", i* j);}
            j++;
        }
        printf("\n");
        i++;
    }
    printf("Task2() FINISH\n");
}

void Task3() {
    printf("Task3() START\n");
    int i = 1;
    int j = 0;
    printf("5\n");
    do {
        do {
            printf("5");
            j++;
        } while (j <= i);
        printf("\n");
        i++;
        j = 0;
    } while (i < 5);
    printf("Task3() FINISH\n");
}
/*
void main() {
    SetConsoleOutputCP(65001);
    int n = -1;
    do {
        printf("\n");
        printf("\n");
        printf("Выберите нужную вам операцию:\n\n");
        printf("1: Задача 1 (i * 10 + j) \n");
        printf("2: Задача 2 (Таблица Пифагора)\n");
        printf("3: Задача 3 (Рисунок по варианту)\n");
        printf("\n");
        printf("0: Выйти из программы\n\n");

        scanf_s("%d", &n);

        switch (n) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 0:
            printf("Завершение работы...\n");
            break;
        default:
            printf("Данные некорректны. Попробуйте еще раз.\n");
            break;
        }

    } while (n != 0);
}
*/