// la4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <time.h>
#include <locale.h>
#include <iostream>

void rand_Zap(int* mat, int n) 
{
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			if (i == j) 
			{
				mat[i * n + j] = 0;
			}
			if (i < j) {
				mat[i * n + j] = rand() % 2;
				mat[j * n + i] = mat[i * n + j];
			}
		}
}

void print_G(int* mat, int n) 
{
	printf("  ");
	for (int i = 0; i < n; i++)
		printf("%3d", i + 1);
	printf("\n\n");
	for (int i = 0; i < n; i++) 
	{
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) 
		{

			printf("%3d", mat[i * n + j]);
		}
		printf("\n");
	}
	printf("\n");


}
void DFS(int s, int* G, int n, int* vis) 
{
	vis[s] = 1;
	printf("%d\t", s + 1);
	for (int i = 0; i < n; i++) 
	{
		if (G[s * n + i] == 1 && vis[i] == 0)
			DFS(i, G, n, &vis[0]);
	}
}



int main()
{
	setlocale(LC_ALL, "Rus");
	
	int N = 1;
	scanf("%d", &N);
	int** G = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		G[i] = (int*)malloc(N * sizeof(int));
	}
	
	int* vis;
	vis = (int*)malloc(N * sizeof(int));

	int s, i = 0;
	rand_Zap(&G[0][0], N);
	print_G(&G[0][0], N);
	for (int i = 0; i < N; i++)
	{
		vis[i] = 0;
	}
	printf("Введите вершину для начала обхода\n");
	scanf("%d", &s);
	while ((s < 1) || (s > N))
	{
		printf("Ошибка.\n");
		scanf("%d", &s);
	}
	printf("\n");
	s--;
	printf("Результат:\n");
	DFS(s, &G[0][0], N, &vis[0]);
	getchar();
	getchar();
}


