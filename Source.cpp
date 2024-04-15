#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;

int main() {
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

	setlocale(0, ".1251");
	srand(time(0));

	int N = 10, M = 32;
	
	int seed = 0;

	for (int i = N; i > 0; i--) {
		for (int j = rand() % M; j > 0; j--); { // заполняем
			seed = seed | (1 << rand() % M);
		}
		for (int j = 0; j < M; j++){ // выводим
			printf("%s", (seed & (1 << j)) ? "\033[7m \033[0m" : " ");
		}
		printf("\n");
	}
}