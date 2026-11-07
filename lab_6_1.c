#include <stdio.h>
#include <Windows.h>
#include <math.h>


#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
    printf("< ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf(">\n");
}

void keyboardInput() {
    printf("n = ");
    scanf_s("%d", &n);

    printf("input %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
}

void oddsX10() {
    for (int i = 0; i < n;i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = arr[i] * 10;
        }
    }
}

void oddsX10_left(int n) {
    for (int i = 0; i < n;i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = arr[i] * 10;
        }
    }
}

int findMin() {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMaxIndex() {
    int max = arr[0];
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] >  max) {
            max = arr[i];
            ind = i;
        }
    }
    return ind;
}

int findMinIndex() {
    int min = arr[0];
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            ind = i;
        }
    }
    return ind;
}

int count_elements() {
    int c = 1;
    for (int i = 0; i < n;i++) {
        if (arr[i] > 10) { c++; }
    }
    return c;
}

int find_last_even() {
    int le = 0;
    for (int i = 0; i < n;i++) {
        if (arr[i] % 2 == 0) { le = arr[i]; }
    }
    return le;

}

void multiplyEvenElements() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] *= -1;
        }
    }
}
void replaceLessThanFour() {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 4) {
            arr[i] = 4;
        }
    }
}

/*
void main() {
    SetConsoleOutputCP(65001);
    int item;
    do {
        printf("\n------------------------------\n");
        printf("Содержимое массива: ");
        printElements();
        printf("Выберите нужную вам операцию:\n");
        printf("1: Ввести с клавиатуры массив\n");
        printf("2: x10 для всех нечетных элементов\n");
        printf("3: Найти минимальный элемент\n");
        printf("4: Количество элементов > 10\n");
        printf("5: Найти последний четный элемент и умножить на 2\n");
        printf("6: Количество четных элементов левее минимального\n");
        printf("7: x10 для всех нечетных элементов левее минимального\n");
        printf("8: Переставить местами минимальный и максимальный элементы\n");
        printf("9: Умножить все четные элементы на -1\n");
        printf("10: Заменить все элементы меньше 4 на цифру 4\n");
        printf("0: Выйти из программы\n");
        printf("Выбранная операция >>>>>> ");

        scanf_s("%d", &item);


        switch (item) {
        case 1:
            keyboardInput();
            break;

        case 2:
            oddsX10();
            break;

        case 3:
        {
            int min = findMin();
            printf("min = %d\n", min);
            break;
        }
        case 4:
        {
            int c = count_elements();
            printf("amount of elements that > 10 = %d\n", c);
            break;
        }
        case 5:
        {
            int ind = find_last_even();
            if (ind >= 0) { 
                ind *= 2; 
                printf("last even element *2 = %d\n", ind);
            }
            else{ printf("no even elements found\n"); }
            break;
        }
        case 6:
        {
            int ind = findMinIndex();
            printf("Индекс минимального = %d\n", ind);
            int c = 0;
            for (int i = 0; i < ind; i++) {
                if (arr[i] % 2 == 0) {
                    c++;
                }
            }
            printf("Левее min элемента %d чётных элементов\n", c);
            break;
        }
        case 7:
        {
            int ind = findMinIndex();
            printf("Индекс минимального = %d", ind);
            oddsX10_left(ind);
            break;
        }
        // переставить местами min и max
        case 8:
        {
            int indexMin = findMinIndex();
            printf("Индекс минимального элемента = %d\n", indexMin);
            int indexMax = findMaxIndex();
            printf("Индекс максимального элемента = %d\n", indexMax);

            int tmp = arr[indexMin];
            arr[indexMin] = arr[indexMax];
            arr[indexMax] = tmp;
            break;
        }
        case 9:
        {
            multiplyEvenElements();
            break;
        }
        case 10:
        {
            replaceLessThanFour();
            break;
        }
        case 0:
        {
            exit(0);
        }
        break;

        }

    } while (item != 0);
}
*/