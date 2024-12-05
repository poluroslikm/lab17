#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
double delete_k(double* ptr_arr, int size, int k);
double* full_elements(double* ptr_array, int n);
double* insert(int* ptr_arr, int* size, int index, int num);
double* rand_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double put_elements(double* ptr_array, int n);
double rand15d(double dm);
double* rand_double15(int n, double dm);
double* sheyker(double* ptr_arr, int size);
double* puzir(double* ptr_arr, int size);
double* puzir_flag(double* ptr_arr, int size);
double lab17task1();
double main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "RUS");
	char c;
	printf("Введите номер задания лабораторной ");
	scanf("%c", &c);
	switch (c)
	{
		case '1':
			lab17task1();
			break;
		//case '2':
		//	lab16task2();
		//	break;
		//case '3':
		//	lab16task3();
		//	break;
	default:
		printf("Неизвестная операция.\n");
	}
}
double delete_k(double* ptr_arr, int size, int k) {
	int n = size - 1;
	for (int i = k; i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];
	return n;
}
double* full_elements(double* ptr_array, int n)
{
	double z, y = 0;
	z = 2.1 / n;
	for (int i = 0; i < n; i++)
	{
		y += z;
		ptr_array[i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return ptr_array;
}
double* insert(double* ptr_arr, int* size, int index, int num)
{
	//double* ptr_array2 = NULL;
	//ptr_array2 = (double*)malloc(*size * sizeof(double));
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	int* ptr_arr_n = (int*)realloc(ptr_arr, size_n * sizeof(int));
	if (ptr_arr_n == NULL) return ptr_arr_n;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_arr[i] = ptr_arr[i - 1];
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
}
double* puzir(double* ptr_arr, int size)
{
	double z;
	//double* ptr_arr_n = (double*)realloc(ptr_arr, size * sizeof(double));
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (ptr_arr[j] < ptr_arr[j + 1])
				{
					z = ptr_arr[j];
					ptr_arr[j] = ptr_arr[j + 1];
					ptr_arr[j + 1] = z;
				}
		}
	}
	return ptr_arr;
}
double* puzir_flag(double* ptr_arr, int size)
{
	short int y;
	double z;
	//double* ptr_arr_n = (double*)realloc(ptr_arr, size * sizeof(double));
	for (int i = 0; i < size - 1; i++)
	{
		y = 0;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (ptr_arr[j] < ptr_arr[j + 1])
			{
				z = ptr_arr[j];
				ptr_arr[j] = ptr_arr[j + 1];
				ptr_arr[j + 1] = z;
				y = 1;
			}
		}
		if (y == 0) break;
	}
	return ptr_arr;
}
double* sheyker(double* ptr_arr, int size)
{
	int ileft = 0, iright = size-1;
	double z;
	//double* ptr_arr_n = (double*)realloc(ptr_arr, size * sizeof(double));
	while (ileft <= iright)
	{
		for (int j = ileft; j < iright; j++)
		{
			if (ptr_arr[j] < ptr_arr[j + 1])
			{
				z = ptr_arr[j];
				ptr_arr[j] = ptr_arr[j + 1];
				ptr_arr[j + 1] = z;
			}
		}
		iright--;
		for (int j = iright; j > ileft; j--)
		{
			if (ptr_arr[j] > ptr_arr[j - 1])
			{
				z = ptr_arr[j];
				ptr_arr[j] = ptr_arr[j - 1];
				ptr_arr[j - 1] = z;
			}
		}
		ileft++;
	}
	return ptr_arr;
}
double* rand_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		double x = (rand() % 20001);
		ptr_array[i] = (x - 10000) / 10000;
	}
	return ptr_array;
}
double* calc_elements(double* ptr_array, int n)
{
	double* ptr_array2 = NULL;
	ptr_array2 = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
		if (ptr_array[i] < 0)
			ptr_array2[i] = 0;
		else
			ptr_array2[i] = ptr_array[i];
	return ptr_array2;
}
double put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
		printf("%+lf \n", ptr_array[i]);
	return 0;
}
double rand15d(double dm)
{
	//int z = -dm * 10000000, y = dm * 10000000;
	double m = (-dm + 1.f * (dm + dm) * rand() / RAND_MAX);
	//m /= 10000000;
	return m;
}
double* rand_double15(int n, double dm)
{
	double* array2 = NULL;
	array2 = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		array2[i] = rand15d(dm);
	}
	return array2;
}
double lab17task1()
{
	clock_t t = clock();
	double time;
	getchar();
	double* ptr_array = NULL;
	double* ptr_array2 = NULL;
	double dm = 50;
	int size = 50000;
	ptr_array = (double*)malloc(size * sizeof(double));
	ptr_array2 = (double*)realloc(rand_double15(size, dm), size * sizeof(double));
	full_elements(ptr_array, size);
	//put_elements(ptr_array, size);
	printf("\n");
	//put_elements(ptr_array2, size);
	printf("\n");
	char h;
	printf("Введите вид сортировки ");
	scanf("%c", &h);
	switch (h)
	{
		case '1':
			puzir(ptr_array, size);
			//ptr_array = (double*)realloc(puzir(ptr_array, size), size * sizeof(double));
			time = (clock() - t) * 1. / CLOCKS_PER_SEC;
			printf("\n\n\n\n\n\n\n\n\n\n%lf\n\n\n\n\n\n\n\n\n\n", time);
			ptr_array2 = (double*)realloc(puzir(ptr_array2, size), size * sizeof(double));
			puzir(ptr_array2, size);
			time = (clock() - t) * 1. / CLOCKS_PER_SEC;
			printf("\n\n\n\n\n\n\n\n\n\n%lf\n\n\n\n\n\n\n\n\n\n", time);
			//put_elements(ptr_array, size);
			printf("\n");
			//put_elements(ptr_array2, size);
			break;
		case '2':
			puzir_flag(ptr_array, size);
			//ptr_array = (double*)realloc(puzir_flag(ptr_array, size), size * sizeof(double));
			time = (clock() - t) * 1. / CLOCKS_PER_SEC;
			printf("\n\n\n\n\n\n\n\n\n\n%lf\n\n\n\n\n\n\n\n\n\n", time);
			//ptr_array2 = (double*)realloc(puzir_flag(ptr_array2, size), size * sizeof(double));
			puzir_flag(ptr_array2, size);
			time = (clock() - t) * 1. / CLOCKS_PER_SEC;
			printf("\n\n\n\n\n\n\n\n\n\n%lf\n\n\n\n\n\n\n\n\n\n", time);
			//put_elements(ptr_array, size);
			printf("\n");
			//put_elements(ptr_array2, size);
			break;
		case '3':
			sheyker(ptr_array, size);
			//ptr_array = (double*)realloc(sheyker(ptr_array, size), size * sizeof(double));
			time = (clock() - t) * 1. / CLOCKS_PER_SEC;
			printf("\n\n\n\n\n\n\n\n\n\n%lf\n\n\n\n\n\n\n\n\n\n", time);
			sheyker(ptr_array2, size);
			//ptr_array2 = (double*)realloc(sheyker(ptr_array2, size), size * sizeof(double));
			time = (clock() - t) * 1. / CLOCKS_PER_SEC;
			printf("\n\n\n\n\n\n\n\n\n\n%lf\n\n\n\n\n\n\n\n\n\n", time);
			//put_elements(ptr_array, size);
			printf("\n");
			//put_elements(ptr_array2, size);
			break;
	default:
		printf("Неизвестная операция.\n");
	}
}