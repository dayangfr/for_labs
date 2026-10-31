#include <windows.h>

void n_9_2_1(HDC hdc, int x, int y);
void n_9_2_2(HDC hdc, int x, int y);
void n_9_2_3(HDC hdc, int x, int y);
void n_9_2_4(HDC hdc, int x, int y);
void n_9_2_4_1(HDC hdc, int x, int y);
void n_9_2_5(HDC hdc, int x, int y);
void n_9_2_6_1(HDC hdc, int x, int y);
void n_9_2_6_2(HDC hdc, int x, int y);
void n_9_2_6_3(HDC hdc, int x, int y);
void n_9_2_6_4(HDC hdc, int x, int y);

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            n_9_2_1(hdc, 0, 0);
            n_9_2_2(hdc, 0, 0);
            n_9_2_3(hdc, 0, 0);
            n_9_2_4(hdc, 0, 0);
            n_9_2_4_1(hdc, 0, 0);
            n_9_2_5(hdc, 0, 0);
            
            n_9_2_6_1(hdc, 50, 500);
            n_9_2_6_2(hdc, 200, 500);
            n_9_2_6_3(hdc, 350, 500);
            n_9_2_6_4(hdc, 500, 500);

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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Lab9_2_WindowClass";

    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Лабораторная работа №9.2",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 700,
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

void n_9_2_1(HDC hdc, int x, int y) {
    int x1 = 400 + x, y1 = 150 + y;
    int x2 = 500 + x, y2 = 250 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 25;
    } while (x1 <= 600);
}

void n_9_2_2(HDC hdc, int x, int y) {
    int x1 = 0 + x, y1 = 250 + y;
    int x2 = 100 + x, y2 = 250 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 25;
        y1 -= 50;
    } while (x1 <= 100);

    x1 = 100 + x;
    y1 = 50 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 25;
        y1 += 50;
    } while (x1 <= 200);
}

void n_9_2_3(HDC hdc, int x, int y) {
    int x1 = 400 + x, y1 = 150 + y;
    int x2 = 500 + x, y2 = 250 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
    } while (x1 <= 600);
}

void n_9_2_4(HDC hdc, int x, int y) {
    int x1 = 150 + x, y1 = 0 + y;
    int x2 = 150 + x, y2 = 100 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 25;
        x2 += 25;
    } while (x1 <= 450);
}

void n_9_2_4_1(HDC hdc, int x, int y) {
    int x1 = 50 + x, y1 = 0 + y;
    int x2 = 50 + x, y2 = 100 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        x2 += 5;
    } while (x1 <= 150);
}

void n_9_2_5(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(34, 139, 34));
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

    int x1 = 200 + x, y1 = 450 + y;
    int x2 = 300 + x, y2 = 550 + y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 10;
    } while (x1 <= 400);

    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);
}

void n_9_2_6_1(HDC hdc, int x, int y) {
    int x1 = x, y1 = y + 50;
    int x2 = x + 100, y2 = y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 += 10;
        x2 -= 10;
    } while (y1 <= y + 100);
}

void n_9_2_6_2(HDC hdc, int x, int y) {
    int x1 = x, y1 = y;
    int x2 = x + 100, y2 = y + 100;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 10;
        y2 -= 10;
    } while (x1 <= x + 100);
}

void n_9_2_6_3(HDC hdc, int x, int y) {
    int x1 = x, y1 = y + 50;
    int x2 = x + 50, y2 = y;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 += 10;
        y2 += 10;
    } while (y1 <= y + 100);
}

void n_9_2_6_4(HDC hdc, int x, int y) {
    int x1 = x + 50, y1 = y;
    int x2 = x, y2 = y + 100;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 10;
        x2 += 10;
    } while (x1 <= x + 100);
}
