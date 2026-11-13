
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define MAX_N 20
#define MAX_M 20

int arr[MAX_N][MAX_M] = {
	{ 0,  1,  222,  3},
	{10, 11,  12,  13},
	{20, 21,  22,  23}
};
int n = 3;
int m = 4;

#define TXT_FILE "arr1.txt"
#define BIN_FILE "arr1.bin"



int isEven(int x) { 
	return x % 2 == 0; 
}


int findMinIdx(int* pi, int* pj) {
	int min = arr[0][0];
	*pi = 0; *pj = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (arr[i][j] < min) { min = arr[i][j]; *pi = i; *pj = j; }
		}
	return min;
}

int findMaxIdx(int* pi, int* pj) {
	int max = arr[0][0];
	*pi = 0; *pj = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] > max) { max = arr[i][j]; *pi = i; *pj = j; }
	return max;
}

int colMax(int j) {
	int max = arr[0][j];
	for (int i = 1; i < n; i++) 
		if (arr[i][j] > max) max = arr[i][j];
	return max;
}
int colMin(int j) {
	int min = arr[0][j];
	for (int i = 1; i < n; i++) 
		if (arr[i][j] < min) min = arr[i][j];
	return min;
}
int rowMax(int i) {
	int max = arr[i][0];
	for (int j = 1; j < m; j++) 
		if (arr[i][j] > max) max = arr[i][j];
	return max;
}


int colHasEqual(int j) {
	for (int a = 0; a < n; a++)
		for (int b = a + 1; b < n; b++)
			if (arr[a][j] == arr[b][j]) return 1;
	return 0;
}

int rowHasEqual(int i) {
	for (int a = 0; a < m; a++)
		for (int b = a + 1; b < m; b++)
			if (arr[i][a] == arr[i][b]) return 1;
	return 0;
}
int colHasEven(int j) {
	for (int i = 0; i < n; i++) 
		if (isEven(arr[i][j])) return 1;
	return 0;
}
int rowHasEven(int i) {
	for (int j = 0; j < m; j++) 
		if (isEven(arr[i][j])) return 1;
	return 0;
}
int rowHasZero(int i) {
	for (int j = 0; j < m; j++) 
		if (arr[i][j] == 0) return 1;
	return 0;
}
int rowZeroCount(int i) {
	int c = 0;
	for (int j = 0; j < m; j++) 
		if (arr[i][j] == 0) c++;
	return c;
}



void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%4d ", arr[i][j]);
		printf("\n");
	}
}



void fillIx10() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = i * 10 + j;
}

void fillZero() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 0;
}

void randFill0_9() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % 10;
}



void oddTimes10() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] % 2 != 0)      
				arr[i][j] *= 10;
}

void multiples10Div10() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] % 10 == 0)
				arr[i][j] /= 10;
}



void inputArr() {
	int nn, mm;
	printf("Количество строк (1..%d): ", MAX_N);

	if (scanf("%d", &nn) != 1 || nn < 1 || nn > MAX_N) { 
		printf("Неверное значение\n"); while (getchar() != '\n'); 
		return; 
	}
	printf("Количество столбцов (1..%d): ", MAX_M);
	if (scanf("%d", &mm) != 1 || mm < 1 || mm > MAX_M) { printf("Неверное значение\n"); while (getchar() != '\n'); return; }
	n = nn;
	m = mm;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			printf("arr[%d][%d] = ", i, j);
			if (scanf("%d", &arr[i][j]) != 1) { arr[i][j] = 0; while (getchar() != '\n'); }
		}
}



void saveText() {
	FILE* fout = fopen(TXT_FILE, "wt");
	if (fout == NULL) { printf("Выходной файл не создался\n"); return; }
	fprintf(fout, "%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			fprintf(fout, "%d ", arr[i][j]);
		fprintf(fout, "\n");
	}
	fclose(fout);
	printf("Сохранено в %s\n", TXT_FILE);
}

void loadText() {
	FILE* fin = fopen(TXT_FILE, "rt");
	if (fin == NULL) { printf("Входной файл %s не найден\n", TXT_FILE); return; }
	int nn, mm;
	if (fscanf(fin, "%d %d", &nn, &mm) != 2 || nn < 1 || nn > MAX_N || mm < 1 || mm > MAX_M) {
		printf("Неверный формат файла\n");
		fclose(fin);
		return;
	}
	n = nn;
	m = mm;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (fscanf(fin, "%d", &arr[i][j]) != 1) arr[i][j] = 0;
	fclose(fin);
	printf("Загружено из %s\n", TXT_FILE);
}



void saveBin() {
	FILE* fout = fopen(BIN_FILE, "wb");
	if (fout == NULL) { printf("Выходной файл не создался\n"); return; }
	fwrite(&n, sizeof(n), 1, fout);
	fwrite(&m, sizeof(m), 1, fout);
	fwrite(arr, sizeof(arr), 1, fout);       
	fclose(fout);
	printf("Сохранено в %s\n", BIN_FILE);
}

void loadBin() {
	FILE* fin = fopen(BIN_FILE, "rb");
	if (fin == NULL) { printf("Входной файл %s не найден\n", BIN_FILE); return; }
	int nn, mm;
	static int tmp[MAX_N][MAX_M];
	if (fread(&nn, sizeof(nn), 1, fin) != 1 ||
		fread(&mm, sizeof(mm), 1, fin) != 1 ||
		fread(tmp, sizeof(tmp), 1, fin) != 1 ||
		nn < 1 || nn > MAX_N || mm < 1 || mm > MAX_M) {
		printf("Неверный формат файла\n");
		fclose(fin);
		return;
	}
	n = nn;
	m = mm;
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_M; j++)
			arr[i][j] = tmp[i][j];
	fclose(fin);
	printf("Загружено из %s\n", BIN_FILE);
}



void deleteRow(int delRow) {
	if (delRow < 0 || delRow >= n) { printf("Нет такой строки\n"); return; }
	for (int i = delRow; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = arr[i + 1][j];
	n--;
}

void deleteColumn(int delCol) {
	if (delCol < 0 || delCol >= m) { printf("Нет такого столбца\n"); return; }
	for (int i = 0; i < n; i++)
		for (int j = delCol; j < m - 1; j++)
			arr[i][j] = arr[i][j + 1];
	m--;
}


void duplicateRow(int r) {
	if (r < 0 || r >= n) { printf("Нет такой строки\n"); return; }
	if (n >= MAX_N) { printf("Нет места для новой строки\n"); return; }
	for (int i = n; i > r + 1; i--)
		for (int j = 0; j < m; j++)
			arr[i][j] = arr[i - 1][j];
	for (int j = 0; j < m; j++)
		arr[r + 1][j] = arr[r][j];
	n++;
}


void duplicateColumn(int c) {
	if (c < 0 || c >= m) { printf("Нет такого столбца\n"); return; }
	if (m >= MAX_M) { printf("Нет места для нового столбца\n"); return; }
	for (int i = 0; i < n; i++) {
		for (int j = m; j > c + 1; j--)
			arr[i][j] = arr[i][j - 1];
		arr[i][c + 1] = arr[i][c];
	}
	m++;
}

void variantA() {
	int iMin, jMin, iMax, jMax;
	int min = findMinIdx(&iMin, &jMin);
	int max = findMaxIdx(&iMax, &jMax);

	for (int i = 0; i < iMin; i++) {
		int rm = rowMax(i);
		for (int j = 0; j < m; j++) {
			if (!isEven(arr[i][j])) arr[i][j] = rm;
		}
	}
	
}


void deleteMarkedColumns(const int* flag) {
	for (int j = m - 1; j >= 0; j--)
		if (flag[j]) deleteColumn(j);
}
void deleteMarkedRows(const int* flag) {
	for (int i = n - 1; i >= 0; i--)
		if (flag[i]) deleteRow(i);
}
void duplicateMarkedRows(const int* flag) {
	for (int i = n - 1; i >= 0; i--)
		if (flag[i]) duplicateRow(i);
}

void variantB() {
	int rowFlag[MAX_N] = { 0 };
	int colFlag[MAX_M] = { 0 };

	for (int j = 0; j < m; j++) {
		int ordered = 1;
		for (int i = 0; i + 1 < n; i++)
			if (arr[i][j] >= arr[i + 1][j]) { ordered = 0; break; }
		colFlag[j] = ordered;
	}

	
	if (n == 0 || m == 0)
		printf("Внимание: массив стал пустым (%d x %d)\n", n, m);
}






int main() {
	SetConsoleOutputCP(65001);
	srand((unsigned)time(NULL));
	int cmd = -1;
	int stroka;
	do {
		print();
		printf("\n---------------- МЕНЮ ----------------\n");
		printf(" 1  - заполнить значениями i*10+j\n");
		printf(" 2  - заполнить нулями\n");
		printf(" 3  - заполнить случайными значениями\n");
		printf(" 4  - все нечетные увеличить в 10 раз\n");
		printf(" 5  - все кратные 10 уменьшить в 10 раз\n");
		printf(" 6  - ввести массив с клавиатуры\n");
		printf(" 7  - сохранить в текстовый файл\n");
		printf(" 8  - загрузить из текстового файла\n");
		printf(" 9  - сохранить в бинарный файл\n");
		printf(" 10 - загрузить из бинарного файла\n");
		printf(" 11 - удалить строку\n");
		printf(" 12 - продублировать столбец\n");
		printf(" 13 - задание по варианту A\n");
		printf(" 14 - удалить столбцы, упорядоченные по возрастанию\n");
		printf(" 0  - выход\n");
		printf("Выберите команду: ");

		scanf_s("%d", &cmd);
		

		switch (cmd) {
		case 1:
			fillIx10(); break;
		case 2:
			fillZero(); break;
		case 3:
			randFill0_9(); break;
		case 4:
			oddTimes10(); break;
		case 5:
			multiples10Div10(); break;
		case 6:
			inputArr(); break;
		case 7:
			saveText(); break;
		case 8:
			loadText(); break;
		case 9:
			saveBin(); break;
		case 10:
			loadBin(); break;
		case 11:
			scanf_s("%d", &stroka);
			deleteRow(stroka);
			break;
		case 12:
			scanf_s("%d", &stroka); 
			duplicateColumn(stroka);
			break;
		case 13:
			variantA(); break;
		case 14:
			variantB();
			break;
		case 0:
			break;
		default:
			printf("Неизвестная команда\n");
		}
	} while (cmd != 0);

	return 0;
}