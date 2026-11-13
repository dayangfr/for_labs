#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tchar.h>

#define N 10
#define M 15

#define WIDTH 30
#define HEIGHT 20


/*кнопки
* L - стена слева от игрока
* R - золото справа от игрока
* U - создать/разрушить стену выше игрока
* D - создать/убрать золото (или стену) ниже игрока
* Z - уничтожить стены справа от игрока до правой границы
* A - уничтожить стены вокруг на 1 клетку
* O - уничтожить стены вокруг на 2 клетки
* G - добавить золото в 5 случайных свободных клеток
* M - Рука Мидаса (код из лекции)
* S - сохранить в бинарный файл
* F5 - сохранить в текстовый файл
* F6 - загрузить из текстового файла
* F9 - сохранить в бинарный файл
* F10 - загрузить из бинарного файла
*/
int map[N][M] = {
	{0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
	{0, 0, 0, 3, 3,   3, 3, 0, 0, 0,   3, 3, 0, 0, 0},
	{0, 0, 0, 0, 0,   0, 3, 0, 0, 0,   3, 3, 0, 0, 0},
	{0, 0, 0, 0, 0,   0, 3, 3, 3, 0,   0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0,   0, 0, 0, 3, 0,   2, 0, 0, 2, 0},
	{0, 0, 0, 0, 0,   0, 0, 2, 0, 0,   2, 0, 0, 2, 0},
	{0, 0, 0, 0, 0,   0, 2, 2, 2, 2,   2, 2, 2, 2, 0},
	{0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0}
};

int steps = 0;
int gold = 0;



void drawMap(HDC hdc) {
	// кисть для пустого поля
	HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // серый
	// кисть для поля с золотом
	HBRUSH hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // желтый
	// кисть для стены
	HBRUSH hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // черный
	// кисть для игрока
	HBRUSH hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // синий

	// Коды ячеек:
	// 0 - свободна
	// 1 - игрок
	// 2 - препятствие
	// 3 - золото
	HBRUSH brush[4] = { hBrushEmptyCell, hBrushMan, hBrushWall, hBrushGold };

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int x1 = j * WIDTH;
			int x2 = (j + 1) * WIDTH;
			int y1 = i * HEIGHT;
			int y2 = (i + 1) * HEIGHT;

			RECT r = { x1, y1, x2, y2 };
			FillRect(hdc, &r, brush[map[i][j]]);
		}
	}

	// Все кисти удаляем!!!
	for (i = 0; i < 4; i++)
		DeleteObject(brush[i]);

	
	char strC[80];
	sprintf(strC, "steps=%d  gold=%d", steps, gold);

	TCHAR strWin[80];
	OemToChar(strC, strWin);

	HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
	SelectObject(hdc, hFont);
	SetTextColor(hdc, RGB(0, 0, 128));

	TextOut(hdc, 10, HEIGHT * N, (LPCWSTR)strWin, _tcslen(strWin));
	DeleteObject(hFont);
}



void Left() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (map[i][j] == 1) { 
				if (map[i][j - 1] == 0) { 
					map[i][j - 1] = 1;
					map[i][j] = 0;
					steps++;
				} else if (map[i][j - 1] == 3) { 
					map[i][j - 1] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}

void Right() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = M - 2; j >= 0; j--) {
			if (map[i][j] == 1) { 
				if (map[i][j + 1] == 0) {
					map[i][j + 1] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i][j + 1] == 3) {
					map[i][j + 1] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}

void Up() {
	int i, j;
	for (i = 1; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) { 
				if (map[i - 1][j] == 0) {
					map[i - 1][j] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i - 1][j] == 3) {
					map[i - 1][j] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}


void Down() {
	int i, j;
	for (i = N - 2; i >= 0; i--) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) { 
				if (map[i + 1][j] == 0) {
					map[i + 1][j] = 1;
					map[i][j] = 0;
					steps++;
				}
				else if (map[i + 1][j] == 3) {
					map[i + 1][j] = 1;
					map[i][j] = 0;
					steps++;
					gold++;
				}
			}
		}
	}
}




void wallLeft() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (map[i][j] == 1) {
				if (map[i][j - 1] == 0) {
					map[i][j - 1] = 2;
				}
			}
		}
	}
}


void goldRight() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M - 1; j++) {
			if (map[i][j] == 1) {
				if (map[i][j + 1] == 0) {
					map[i][j + 1] = 3;
				}
			}
		}
	}
}


void toggleWallUp() {
	int i, j;
	for (i = 1; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (map[i - 1][j] == 0) {
					map[i - 1][j] = 2;
				}
				else if (map[i - 1][j] == 2) {
					map[i - 1][j] = 0;
				}
			}
		}
	}
}


void actionDown() {
	int i, j;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (map[i + 1][j] == 0) {
					map[i + 1][j] = 3;
				}
				else if (map[i + 1][j] == 3 || map[i + 1][j] == 2) {
					map[i + 1][j] = 0;
				}
			}
		}
	}
}


void destroyRightWalls() {
	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				for (k = j + 1; k < M; k++) {
					if (map[i][k] == 2) {
						map[i][k] = 0;
					}
				}
			}
		}
	}
}


void destroyWallsAround(int r) {
	int i, j, di, dj;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				for (di = -r; di <= r; di++) {
					for (dj = -r; dj <= r; dj++) {
						int ni = i + di;
						int nj = j + dj;
						if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
							if (map[ni][nj] == 2) { 
								map[ni][nj] = 0;
							}
						}
					}
				}
			}
		}
	}
}


void sprinkleGold() {
	int k, attempts = 0;
	for (k = 0; k < 5 && attempts < 200; attempts++) {
		int ri = rand() % N;
		int rj = rand() % M;
		if (map[ri][rj] == 0) {
			map[ri][rj] = 3;
			k++;
		}
	}
}



void doMidasHand(int i, int j) {
	if (map[i][j] == 2) { 
		map[i][j] = 3;    
		if (i > 0) doMidasHand(i - 1, j);
		if (i < N - 1) doMidasHand(i + 1, j);
		if (j > 0) doMidasHand(i, j - 1);
		if (j < M - 1) doMidasHand(i, j + 1);
	}
}

void midasHandToRight() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			if (map[i][j] == 1) { 
				if (map[i][j + 1] == 2) { 
					doMidasHand(i, j + 1);
				}
			}
		}
	}
}




void Save() {
	FILE* fout;
	fout = fopen("C:\\Users\\user\\source\\repos\\lab_11_2\\lab_11_2\\text_save\\game.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d ", N);
	fprintf(fout, "%d\n", M);
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			fprintf(fout, "%d ", map[i][j]);
		}
		fprintf(fout, "\n");
	}

	fprintf(fout, "%d ", steps);
	fprintf(fout, "%d", gold);

	fclose(fout);
}


void Load() {
	FILE* fin;
	fin = fopen("C:\\Users\\user\\source\\repos\\lab_11_2\\lab_11_2\\text_save\\game.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не создался");
		return;
	}

	int n, m;
	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(fin, "%d", &map[i][j]);
		}
	}

	fscanf(fin, "%d ", &steps);
	fscanf(fin, "%d", &gold);

	fclose(fin);
}


void SaveBinary() {
	FILE* fout;
	fout = fopen("C:\\Users\\user\\source\\repos\\lab_11_2\\lab_11_2\\bin_save\\game_bin.bin", "wb");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	int n = N, m = M;

	fwrite(&n, sizeof(n), 1, fout);
	fwrite(&m, sizeof(n), 1, fout);
	fwrite(map, sizeof(map), 1, fout);
	fwrite(&steps, sizeof(steps), 1, fout);
	fwrite(&gold, sizeof(gold), 1, fout);

	fclose(fout);
}


void LoadBinary() {
	FILE* fin;
	fin = fopen("C:\\Users\\user\\source\\repos\\lab_11_2\\lab_11_2\\bin_save\\game_bin.bin", "rb");
	if (fin == NULL) {
		printf("Входной файл не создался");
		return;
	}

	int n, m;
	fread(&n, sizeof(n), 1, fin);
	fread(&m, sizeof(n), 1, fin);
	fread(map, sizeof(map), 1, fin);
	fread(&steps, sizeof(steps), 1, fin);
	fread(&gold, sizeof(gold), 1, fin);

	fclose(fin);
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_DOWN:
			Down();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_LEFT:
			Left();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_UP:
			Up();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			Right();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_F5:
			Save();
			break;
		case VK_F6: 
			Load();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_F9: 
			SaveBinary();
			break;
		case VK_F10: 
			LoadBinary();
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 0x4c: 
			wallLeft();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x52: 
			goldRight();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x55: 
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x44: 
			actionDown();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x5a: 
			destroyRightWalls();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x41: 
			destroyWallsAround(1);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x4f: 
			destroyWallsAround(2);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x47: 
			sprinkleGold();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x4d: 
			midasHandToRight();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		drawMap(hdc);
		EndPaint(hWnd, &ps);
	}
				 break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
	srand((unsigned int)time(NULL));

	WNDCLASSEXW wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = L"Lab19_Win";
	RegisterClassExW(&wcex);

	HWND hWnd = CreateWindowW(L"Lab19_Win", L"Lab19_Win", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 600, 350, NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}