// la4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <time.h>
#include <locale.h>
#include <iostream>

void rand_Zap(int** mat, int n) 
{
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			if (i == j) 
			{
				mat[i][j] = 0;
			}
			if (i < j) {
				mat[i][j] = rand() % 2;
				mat[j][i] = mat[i][j];
			}
		}
}

void print_G(int** mat, int n) 
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

			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void DFS(int s, int** G, int n, int* vis) 
{
	vis[s] = 1;
	printf("%d\t", s + 1);
	for (int i = 0; i < n; i++) 
	{
		if (G[s][i] == 1 && vis[i] == 0)
			DFS(i, G, n, &vis[0]);
	}
}

struct stack {
	int elem[N];
	int top;
};

typedef struct Spisok {
	int value;
	struct Spisok* next;
}smej;

smej* create(int num) {
	// Выделение памяти под корень списка
	smej* tmp = new smej;
	// Присваивание имя вершине
	tmp->value = num;
	// Присваивание указателю на следующий элемент значения NULL
	tmp->next = NULL;
	return(tmp);
}

void addElem(int data, smej* head) {
	// Выделение памяти под корень списка
	smej* tmp = new smej;
	// Присваивание значения узлу
	tmp->value = data;
	// Присваивание указателю на следующий элемент значения NULL
	tmp->next = NULL;
	// Присваивание новому указателю указателя head. 
	// Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
	smej* p = head;
	// Сдвиг указателя p в самый конец первоначального списка
	while (p->next != NULL)
		p = p->next;
	// Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
	p->next = tmp;
}
void print(smej* head) {
	smej* s = head;
	if (s != NULL) {					//номер вершины
		printf("%d:  ", s->value + 1);
		s = s->next;
	}
	while (s != NULL)					//номера узлов
	{
		// Вывод значения узла
		printf("%d ", s->value + 1);
		// Сдвиг указателя к следующему узлу
		s = s->next;
	}
}

void spisokSmej(int **Matrix, smej* G_S[N]) {
	for (int i = 0; i < N; i++) {
		Spisok* tmp = create(i);
		for (int j = 0; j < N; j++) 
		{
			if (Matrix[i][j] == 1)
				addElem(j, tmp);
		}
		G_S[i] = tmp;
	}
	for (int i = 0; i < N; i++) 
	{
		print(G_S[i]);
		printf("\n");
	}
	printf("\n");
}

void DFSsp(smej* (&P)[N], int ver, int* num) {
	num[ver] = 1;
	printf("%d ", ver + 1);
	smej* s = P[ver];
	s = s->next;
	while (s != NULL) {
		if (num[s->value] == 0) {
			DFSsp(P, s->value, &num[0]);
		}
		s = s->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	/*int N = 1;
	scanf("%d", &N);*/
	int** G = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		G[i] = (int*)malloc(N * sizeof(int));
	}
	
	int* vis, num[N], s;
	vis = (int*)malloc(N * sizeof(int));
	struct stack* stk;
	stk = new stack;
	Spisok* G_S[N];

	rand_Zap(G, N);
	print_G(G, N);
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
	DFS(s, G, N, &vis[0]);

	for (int i = 0; i < N; i++) {
		num[i] = 0;
	}

	printf("\n");
	printf("Представление графа в виде списка смежности: \n");
	spisokSmej(G, G_S);

	printf("Введите номер вершины для начала обхода: ");
	scanf("%d", &s);
	s--;
	DFSsp(G_S, s, &num[0]);



	getchar();
	getchar();
}
