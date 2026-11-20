#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#define MAX_N 10

int* input_arr(int* n) {
    printf("Введите N (1..%d): ", MAX_N);
    if (scanf("%d", n) != 1 || *n < 1 || *n > MAX_N) {
        printf("Ошибка ввода N\n");
        while (getchar() != '\n');
        return NULL;
    }

    int* arr = (int*)malloc(*n * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    printf("Введите %d элементов: ", *n);
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            arr[i] = 0;
            while (getchar() != '\n');
        }
    }
    return arr;
}

void print_arr(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void task_12_1_1() {
    int n;
    int* a = input_arr(&n);
    if (!a) return;

    print_arr(a, n);
    bubble_sort(a, n);
    print_arr(a, n);

    free(a);
}

void task_12_1_2() {
    int n;
    int* a = input_arr(&n);
    if (!a) return;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) cnt++;
    }

    int* b = NULL;
    if (cnt > 0) {
        b = (int*)malloc(cnt * sizeof(int));
        if (!b) {
            printf("Ошибка выделения памяти\n");
            free(a);
            return;
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                b[j++] = a[i];
            }
        }
    }

    print_arr(a, n);
    print_arr(b, cnt);

    free(a);
    free(b);
}

int get_min_idx(const int* a, int n) {
    int min_i = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[min_i]) min_i = i;
    }
    return min_i;
}

int get_max_idx(const int* a, int n) {
    int max_i = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[max_i]) max_i = i;
    }
    return max_i;
}

int check_cond(int var, const int* a, int n, int i) {
    int imin = get_min_idx(a, n);
    int imax = get_max_idx(a, n);
    int left = imin < imax ? imin : imax;
    int right = imin < imax ? imax : imin;

    if (var == 1) return i > left && i < right;
    if (var == 2) return i > imin && a[i] % 2 != 0;
    if (var == 3) return i > imin && a[i] % 2 == 0;
    if (var == 4) return i < imax && a[i] % 2 == 0;
    if (var == 5) return i < imax && a[i] % 2 != 0;

    if (var == 6) {
        int f = -1, l = -1;
        for (int k = 0; k < n; k++) {
            if (a[k] % 2 == 0) {
                if (f == -1) f = k;
                l = k;
            }
        }
        return f != -1 && i > f && i < l;
    }
    if (var == 7) {
        int f = -1, l = -1;
        for (int k = 0; k < n; k++) {
            if (a[k] % 2 != 0) {
                if (f == -1) f = k;
                l = k;
            }
        }
        return f != -1 && i > f && i < l;
    }
    if (var == 8) return i > 0 && i < n - 1 && a[i - 1] % 2 != 0 && a[i + 1] % 2 != 0;
    if (var == 9) return i > 0 && i < n - 1 && a[i - 1] % 2 == 0 && a[i + 1] % 2 == 0;
    if (var == 10) return i <= left || i >= right;

    return 0;
}

void task_12_1_3() {
    int var;
    printf("Номер варианта (1..10): ");
    if (scanf("%d", &var) != 1 || var < 1 || var > 10) {
        printf("Неверный вариант\n");
        while (getchar() != '\n');
        return;
    }

    int n;
    int* a = input_arr(&n);
    if (!a) return;

    int n2 = 0;
    for (int i = 0; i < n; i++) {
        if (check_cond(var, a, n, i)) n2++;
    }

    int* b = NULL;
    if (n2 > 0) {
        b = (int*)malloc(n2 * sizeof(int));
        if (!b) {
            printf("Ошибка выделения памяти\n");
            free(a);
            return;
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (check_cond(var, a, n, i)) {
                b[k++] = a[i];
            }
        }
    }

    printf("n = %d, arr  = ", n);
    print_arr(a, n);
    printf("n2 = %d, arr2 = ", n2);
    print_arr(b, n2);

    free(a);
    free(b);
}

/* Односвязный список */

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push_front(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    node->data = val;
    node->next = head;
    head = node;
}

void print_list() {
    struct Node* cur = head;
    while (cur != NULL) {
        printf("(%d) -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int pop_front() {
    if (!head) {
        printf("Список пуст\n");
        return 0;
    }
    int val = head->data;
    struct Node* tmp = head;
    head = head->next;
    free(tmp);
    return val;
}

int find_val(int val) {
    struct Node* cur = head;
    while (cur) {
        if (cur->data == val) return 1;
        cur = cur->next;
    }
    return 0;
}

void clear_list() {
    while (head) {
        struct Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int list_sum() {
    int s = 0;
    for (struct Node* cur = head; cur != NULL; cur = cur->next) {
        s += cur->data;
    }
    return s;
}

int count_even() {
    int c = 0;
    for (struct Node* cur = head; cur != NULL; cur = cur->next) {
        if (cur->data % 2 == 0) c++;
    }
    return c;
}

void mult_odd_10() {
    for (struct Node* cur = head; cur != NULL; cur = cur->next) {
        if (cur->data % 2 != 0) cur->data *= 10;
    }
}

int mult_ith_100(int idx) {
    if (idx < 0) return 0;
    struct Node* cur = head;
    int i = 0;
    while (cur && i < idx) {
        cur = cur->next;
        i++;
    }
    if (!cur) return 0;
    cur->data *= 100;
    return 1;
}

void mult_left_10(int idx) {
    struct Node* cur = head;
    int i = 0;
    while (cur && i < idx) {
        cur->data *= 10;
        cur = cur->next;
        i++;
    }
}

void mult_right_10(int idx) {
    if (idx < 0) return;
    struct Node* cur = head;
    int i = 0;
    while (cur) {
        if (i > idx) cur->data *= 10;
        cur = cur->next;
        i++;
    }
}

int remove_at(int idx) {
    if (idx < 0 || !head) return 0;
    if (idx == 0) {
        pop_front();
        return 1;
    }

    struct Node* prev = head;
    for (int i = 0; i < idx - 1 && prev; i++) {
        prev = prev->next;
    }
    if (!prev || !prev->next) return 0;

    struct Node* del = prev->next;
    prev->next = del->next;
    free(del);
    return 1;
}

void print_rev(struct Node* node) {
    if (!node) return;
    print_rev(node->next);
    printf("(%d) -> ", node->data);
}

int check_dups() {
    for (struct Node* p1 = head; p1 != NULL; p1 = p1->next) {
        for (struct Node* p2 = p1->next; p2 != NULL; p2 = p2->next) {
            if (p1->data == p2->data) return 1;
        }
    }
    return 0;
}

void menu_list() {
    int op = -1, x;
    while (op != 0) {
        printf("\nСписок: ");
        print_list();
        printf("\n--- МЕНЮ: СВЯЗАННЫЙ СПИСОК ---\n");
        printf(" 1  - добавить в голову\n");
        printf(" 2  - удалить из головы\n");
        printf(" 3  - найти значение\n");
        printf(" 4  - очистить список\n");
        printf(" 5  - сумма всех элементов\n");
        printf(" 6  - количество четных элементов\n");
        printf(" 7  - все нечетные увеличить в 10 раз\n");
        printf(" 8  - i-ый элемент увеличить в 100 раз\n");
        printf(" 9  - все элементы левее i-го увеличить в 10 раз\n");
        printf(" 10 - все элементы правее i-го увеличить в 10 раз\n");
        printf(" 11 - удалить i-ый элемент\n");
        printf(" 12 - вывести список в обратную сторону\n");
        printf(" 13 - есть ли повторяющиеся элементы\n");
        printf(" 0  - назад\n");
        printf("Выберите команду: ");

        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            op = -1;
        }

        switch (op) {
        case 1:
            printf("Значение: ");
            if (scanf("%d", &x) == 1) push_front(x);
            else { printf("Ошибка ввода\n"); while (getchar() != '\n'); }
            break;
        case 2:
            if (head) printf("Удалено: %d\n", pop_front());
            else printf("Список пуст\n");
            break;
        case 3:
            printf("Искать значение: ");
            if (scanf("%d", &x) == 1) printf(find_val(x) ? "Найдено\n" : "Не найдено\n");
            else { printf("Ошибка ввода\n"); while (getchar() != '\n'); }
            break;
        case 4:
            clear_list();
            break;
        case 5:
            printf("Сумма = %d\n", list_sum());
            break;
        case 6:
            printf("Четных элементов: %d\n", count_even());
            break;
        case 7:
            mult_odd_10();
            break;
        case 8:
            printf("Индекс i (с нуля): ");
            if (scanf("%d", &x) == 1) {
                if (!mult_ith_100(x)) printf("Нет элемента с таким индексом\n");
            }
            else { printf("Ошибка ввода\n"); while (getchar() != '\n'); }
            break;
        case 9:
            printf("Индекс i (с нуля): ");
            if (scanf("%d", &x) == 1) mult_left_10(x);
            else { printf("Ошибка ввода\n"); while (getchar() != '\n'); }
            break;
        case 10:
            printf("Индекс i (с нуля): ");
            if (scanf("%d", &x) == 1) mult_right_10(x);
            else { printf("Ошибка ввода\n"); while (getchar() != '\n'); }
            break;
        case 11:
            printf("Индекс i (с нуля): ");
            if (scanf("%d", &x) == 1) {
                if (!remove_at(x)) printf("Нет элемента с таким индексом\n");
            }
            else { printf("Ошибка ввода\n"); while (getchar() != '\n'); }
            break;
        case 12:
            print_rev(head);
            printf("NULL\n");
            break;
        case 13:
            printf(check_dups() ? "Повторы есть\n" : "Повторов нет\n");
            break;
        case 0:
            break;
        default:
            printf("Неизвестная команда\n");
        }
    }
    clear_list();
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    int cmd = -1;
    while (cmd != 0) {
        printf("\n--- ЛР12 ---\n");
        printf(" 1 - задача 12.1.1: ввод, вывод, сортировка\n");
        printf(" 2 - задача 12.1.2: второй массив из четных\n");
        printf(" 3 - задача 12.1.3: задание по варианту\n");
        printf(" 4 - 12.2: односвязный список\n");
        printf(" 0 - выход\n");
        printf("Выберите команду: ");

        if (scanf("%d", &cmd) != 1) {
            while (getchar() != '\n');
            cmd = -1;
        }

        switch (cmd) {
        case 1: task_12_1_1(); break;
        case 2: task_12_1_2(); break;
        case 3: task_12_1_3(); break;
        case 4: menu_list(); break;
        case 0: break;
        default: printf("Неизвестная команда\n");
        }
    }
    return 0;
}
