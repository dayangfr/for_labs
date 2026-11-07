#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
int main() {
    const char* filename = "data.txt";
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("File is not created");
        return 1;
    }

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));

    // Генерируем N1: количество элементов от 1 до 20
    int N1 = (rand() % 20) + 1;

    // Записываем N1 в файл
    fprintf(file, "%d\n", N1);

    // Генерируем и записываем N1 элементов в диапазоне [-1000, 1000]
    for (int i = 0; i < N1; ++i) {
        int value = (rand() % 2001) - 1000;  // от 0..2000 минус 1000 => [-1000, 1000]
        fprintf(file, "%d ", value);
    }

    fclose(file);
    printf("File %s has been created", filename);
    return 0;
}
*/