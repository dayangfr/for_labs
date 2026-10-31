#include <windows.h>

// Объявления функций для каждой задачи лабораторной работы
void n_9_1_1(HDC hdc, int x, int y);   // Рисунок дома (из линий)[span_1](start_span)[span_1](end_span)
void n_9_1_2(HDC hdc, int x, int y);   // Ёлочка[span_2](start_span)[span_2](end_span)
void n_9_1_3(HDC hdc, int x, int y);   // Автомобиль[span_3](start_span)[span_3](end_span)
void n_9_1_4(HDC hdc, int x, int y);   // Снежная баба[span_4](start_span)[span_4](end_span)
void n_9_1_5(HDC hdc, int x, int y);   // Дерево[span_5](start_span)[span_5](end_span)
void n_9_1_6(HDC hdc, int x, int y);   // Сооружение (мост/сарай)[span_6](start_span)[span_6](end_span)
void n_9_1_7(HDC hdc, int x, int y);   // Что-то состоящее из линий[span_7](start_span)[span_7](end_span)
void n_9_1_8(HDC hdc, int x, int y);   // Транспортное средство с колесами[span_8](start_span)[span_8](end_span)
void n_9_1_9(HDC hdc, int x, int y);   // Закрашенные прямоугольники[span_9](start_span)[span_9](end_span)
void n_9_1_10(HDC hdc, int x, int y);  // Множество эллипсов[span_10](start_span)[span_10](end_span)
void n_9_1_11(HDC hdc, int x, int y);  // Дуги и другие элементы[span_11](start_span)[span_11](end_span)

// Оконная процедура
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Вызовы функций с задачами в соответствии с требованиями
            n_9_1_1(hdc, 50, 40);     // Задача 9.1.1: Дом
            n_9_1_2(hdc, 200, 40);    // Задача 9.1.2: Ёлочка
            n_9_1_3(hdc, 350, 40);    // Задача 9.1.3: Автомобиль
            n_9_1_4(hdc, 550, 40);    // Задача 9.1.4*: Снежная баба
            n_9_1_5(hdc, 750, 40);    // Задача 9.1.5: Дерево
            
            n_9_1_6(hdc, 50, 220);    // Задача 9.1.6*: Сооружение (мост)
            n_9_1_7(hdc, 220, 220);   // Задача 9.1.7**: Узор из линий
            n_9_1_8(hdc, 400, 220);   // Задача 9.1.8: Велосипед с колесами
            n_9_1_9(hdc, 600, 220);   // Задача 9.1.9*: Закрашенные прямоугольники
            
            n_9_1_10(hdc, 50, 400);   // Задача 9.1.10*: Множество эллипсов
            n_9_1_11(hdc, 250, 400);  // Задача 9.1.11**: Дуги и элементы

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Главная функция программы
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Lab9_1_WindowClass";

    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Лабораторная работа №9.1 - Графические примитивы",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 950, 600,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Реализация функций для каждой задачи

// 9.1.1. Рисунок дома (из линий)
void n_9_1_1(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 20, y + 60, NULL); LineTo(hdc, x + 20, y + 120);
    LineTo(hdc, x + 100, y + 120); LineTo(hdc, x + 100, y + 60);
    LineTo(hdc, x + 20, y + 60); // Основа
    MoveToEx(hdc, x + 20, y + 60, NULL); LineTo(hdc, x + 60, y + 20);
    LineTo(hdc, x + 100, y + 60); // Крыша
    MoveToEx(hdc, x + 50, y + 120, NULL); LineTo(hdc, x + 50, y + 90);
    LineTo(hdc, x + 70, y + 90); LineTo(hdc, x + 70, y + 120); // Дверь
}

// 9.1.2. Добавить ёлочку
void n_9_1_2(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 45, y + 100, NULL); LineTo(hdc, x + 45, y + 120); // Ствол
    MoveToEx(hdc, x + 20, y + 100, NULL); LineTo(hdc, x + 70, y + 100);
    LineTo(hdc, x + 45, y + 70); LineTo(hdc, x + 20, y + 100); // Нижний ярус
    MoveToEx(hdc, x + 25, y + 75, NULL); LineTo(hdc, x + 65, y + 75);
    LineTo(hdc, x + 45, y + 45); LineTo(hdc, x + 25, y + 75); // Средний ярус
    MoveToEx(hdc, x + 30, y + 50, NULL); LineTo(hdc, x + 60, y + 50);
    LineTo(hdc, x + 45, y + 25); LineTo(hdc, x + 30, y + 50); // Верхний ярус
}

// 9.1.3. Нарисовать автомобиль
void n_9_1_3(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 10, y + 80, NULL); LineTo(hdc, x + 120, y + 80);
    LineTo(hdc, x + 120, y + 100); LineTo(hdc, x + 10, y + 100);
    LineTo(hdc, x + 10, y + 80); // Кузов
    MoveToEx(hdc, x + 40, y + 80, NULL); LineTo(hdc, x + 60, y + 50);
    LineTo(hdc, x + 90, y + 50); LineTo(hdc, x + 100, y + 80); // Кабина
    Ellipse(hdc, x + 25, y + 95, x + 45, y + 115); // Колесо 1
    Ellipse(hdc, x + 85, y + 95, x + 105, y + 115); // Колесо 2
}

// 9.1.4*. Нарисовать снежную бабу
void n_9_1_4(HDC hdc, int x, int y) {
    Ellipse(hdc, x + 25, y + 75, x + 75, y + 125); // Нижний ком
    Ellipse(hdc, x + 33, y + 45, x + 67, y + 80);  // Средний ком
    Ellipse(hdc, x + 40, y + 20, x + 60, y + 48);  // Голова
}

// 9.1.5. Добавить дерево
void n_9_1_5(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 42, y + 80, NULL); LineTo(hdc, x + 42, y + 120);
    MoveToEx(hdc, x + 48, y + 80, NULL); LineTo(hdc, x + 48, y + 120); // Ствол
    Ellipse(hdc, x + 15, y + 40, x + 75, y + 90);
    Ellipse(hdc, x + 5, y + 20, x + 55, y + 70);
    Ellipse(hdc, x + 35, y + 20, x + 85, y + 70); // Крона
}

// 9.1.6*. Добавить сооружение (мост)
void n_9_1_6(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 10, y + 80, NULL); LineTo(hdc, x + 140, y + 80);
    MoveToEx(hdc, x + 10, y + 100, NULL); LineTo(hdc, x + 140, y + 100);
    Arc(hdc, x + 20, y + 80, x + 70, y + 120, x + 20, y + 100, x + 70, y + 100);
    Arc(hdc, x + 80, y + 80, x + 130, y + 120, x + 80, y + 100, x + 130, y + 100);
}

// 9.1.7**. Добавить что-то состоящее из линий (Звезда)
void n_9_1_7(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 50, y + 20, NULL); LineTo(hdc, x + 80, y + 100);
    LineTo(hdc, x + 10, y + 50); LineTo(hdc, x + 90, y + 50);
    LineTo(hdc, x + 20, y + 100); LineTo(hdc, x + 50, y + 20);
}

// 9.1.8. Добавить рисунок транспортного средства с колесами (Велосипед)
void n_9_1_8(HDC hdc, int x, int y) {
    Ellipse(hdc, x + 10, y + 80, x + 50, y + 120);
    Ellipse(hdc, x + 90, y + 80, x + 130, y + 120);
    MoveToEx(hdc, x + 30, y + 100, NULL); LineTo(hdc, x + 70, y + 60);
    LineTo(hdc, x + 110, y + 100); LineTo(hdc, x + 30, y + 100);
    MoveToEx(hdc, x + 70, y + 60, NULL); LineTo(hdc, x + 65, y + 35);
}

// 9.1.9*. Добавить закрашенные прямоугольники
void n_9_1_9(HDC hdc, int x, int y) {
    HBRUSH br1 = CreateSolidBrush(RGB(0, 100, 200));
    HBRUSH br2 = CreateSolidBrush(RGB(220, 80, 40));
    HBRUSH old = (HBRUSH)SelectObject(hdc, br1);

    RECT r1 = { x + 10, y + 30, x + 60, y + 110 };
    FillRect(hdc, &r1, br1);

    SelectObject(hdc, br2);
    RECT r2 = { x + 70, y + 60, x + 120, y + 110 };
    FillRect(hdc, &r2, br2);

    SelectObject(hdc, old);
    DeleteObject(br1);
    DeleteObject(br2);
}

// 9.1.10*. Добавить множество эллипсов (Цветок)
void n_9_1_10(HDC hdc, int x, int y) {
    Ellipse(hdc, x + 40, y + 20, x + 80, y + 60);
    Ellipse(hdc, x + 40, y + 60, x + 80, y + 100);
    Ellipse(hdc, x + 20, y + 40, x + 60, y + 80);
    Ellipse(hdc, x + 60, y + 40, x + 100, y + 80);
    
    HBRUSH br = CreateSolidBrush(RGB(255, 215, 0));
    HBRUSH old = (HBRUSH)SelectObject(hdc, br);
    Ellipse(hdc, x + 45, y + 45, x + 75, y + 75);
    SelectObject(hdc, old);
    DeleteObject(br);
}

// 9.1.11**. Добавить дуги и другие элементы (Смайлик)
void n_9_1_11(HDC hdc, int x, int y) {
    Ellipse(hdc, x + 10, y + 10, x + 110, y + 110); // Контур лица
    Arc(hdc, x + 30, y + 50, x + 90, y + 90, x + 35, y + 70, x + 85, y + 70); // Улыбка
    Ellipse(hdc, x + 30, y + 35, x + 45, y + 50); // Глаз 1
    Ellipse(hdc, x + 75, y + 35, x + 90, y + 50); // Глаз 2
}
