#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian");

	int i, j, n, m, k = 0, k1 = 0, x;
	printf("Пожалуйста,введите матрицу размером n на m: ");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	if (n <= 1 || m <= 1) {
		printf("Невозможно создать матрицу");
		return 1;
	}
	// Ввод элементов массива

	int** a;
	a = (int**)malloc(n * sizeof(int*)); // Выделение памяти на элементы строки
	for (i = 0; i < n; i++) {

		a[i] = (int*)malloc(m * sizeof(int)); // Выделение памяти под хранение строки состощей из элементов
		for (j = 0; j < m; j++) {
			printf("a[%d][%d] = ", i, j);
			fflush(stdin);
			scanf_s("%d", &a[i][j]);
		}
	}

	int** a1;
	a1 = (int**)malloc(n * sizeof(int*)); // Выделение памяти на элементы строки
	for (i = 0; i < n; i++) {

		a1[i] = (int*)malloc(m * sizeof(int)); // Выделение памяти под хранение строки состощей из элементов
	}

	printf("\n");
	// Вывод массива
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//Ввод и вывод k и k1
	if (1 <= k || k <= n) {
		printf("Исходный номер k :");
		scanf_s("%d", &k);
		k = k - 1; //Так как счет начинается с 1 ,а не с 0,как надо для массивов,то отнимаем 1
	}
	else printf("Несоответствие условию");

	if (1 <= k1 || k1 <= n) {
		printf("Исходный номер k1 :");
		scanf_s("%d", &k1);
		k1 = k1 - 1;
	}
	else printf("Несоответствие условию");

	printf("\n");


	if (k == k1 + 1) //Если всё и так правильно
		printf("Строки стоят на правильном месте");

	else {
		int temp = -1;
		int indA1 = 0, indA = 0;
		for (int i = 0; i < n + 1; i++) {
			if (i != k) {
				if (i == k1 + 1) {
					for (int j = 0; j < m; j++) {
						a1[indA1][j] = a[k][j];
						indA = indA1;
					}
				}
				else {
					for (int j = 0; j < m; j++) {
						a1[indA1][j] = a[indA][j];
					}

				}
				indA1++;
			}
			indA++;
		}

	}

	for (i = 0; i < n; i++)                                           //Выводим получившуюся матрицу
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t ", a1[i][j]);
		}
		printf("\n");
	}

	free(a);
	free(a1);

	return 0;


}