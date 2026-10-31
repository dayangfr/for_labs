#include <windows.h>


void StClausAuto(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 25, y + 40, NULL); LineTo(hdc, x + 25, y + 60);
    MoveToEx(hdc, x + 10, y + 40, NULL); LineTo(hdc, x + 40, y + 40);
    LineTo(hdc, x + 25, y + 20); LineTo(hdc, x + 10, y + 40);
    MoveToEx(hdc, x + 13, y + 25, NULL); LineTo(hdc, x + 37, y + 25);
    LineTo(hdc, x + 25, y + 10); LineTo(hdc, x + 13, y + 25);
}

void drawTruck(HDC hdc, int x, int y) {
    MoveToEx(hdc, x, y + 20, NULL); LineTo(hdc, x + 60, y + 20);
    LineTo(hdc, x + 60, y + 40); LineTo(hdc, x, y + 40);
    LineTo(hdc, x, y + 20);
    MoveToEx(hdc, x + 60, y + 25, NULL); LineTo(hdc, x + 80, y + 25);
    LineTo(hdc, x + 90, y + 40); LineTo(hdc, x + 60, y + 40);
    LineTo(hdc, x + 60, y + 25);
    Ellipse(hdc, x + 15, y + 35, x + 30, y + 50);
    Ellipse(hdc, x + 70, y + 35, x + 85, y + 50);
}

void drawSnowman(HDC hdc, int x, int y) {
    Ellipse(hdc, x + 15, y + 30, x + 45, y + 60);
    Ellipse(hdc, x + 20, y + 15, x + 40, y + 33);
    Ellipse(hdc, x + 24, y + 5, x + 36, y + 18);

    MoveToEx(hdc, x + 20, y + 22, NULL); LineTo(hdc, x + 7, y + 15);
    MoveToEx(hdc, x + 40, y + 22, NULL); LineTo(hdc, x + 53, y + 15);

    SetPixel(hdc, x + 28, y + 10, RGB(0, 0, 0));
    SetPixel(hdc, x + 32, y + 10, RGB(0, 0, 0));
    MoveToEx(hdc, x + 29, y + 13, NULL); LineTo(hdc, x + 31, y + 13);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            StClausAuto(hdc, 50, 50);
            drawTruck(hdc, 50, 200);
            drawSnowman(hdc, 50, 350);

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
    const wchar_t CLASS_NAME[] = L"Lab9_3_WindowClass";

    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Лабораторная работа №9.3",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
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
