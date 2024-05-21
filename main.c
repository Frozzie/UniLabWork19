#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include "matrix.h"

#define MAX_BUFFER_SIZE    5000001

#define TIME_TEST(testCode, time) \
{ \
    clock_t start_time = clock(); \
    testCode \
    clock_t end_time = clock();\
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

typedef struct SortFunc 
{
    void    (*sort)(int *a, size_t n);  // ��������� �� ������� ����������
    char    name[64];                   // ��� ����������, ������������ ��� ������
} SortFunc;

typedef struct SortFuncNComp
{
    long long    (*sort)(int *a, size_t n);  // ��������� �� ������� ����������
    char    name[64];                   // ��� ����������, ������������ ��� ������
} SortFuncNComp;

typedef struct GeneratingFunc 
{
    void (*generate)(int *a, size_t n); // ��������� �� ������� ��������� ����������.
    char name[64];                      // ��� ����������, ������������ ��� ������
} GeneratingFunc;

uint8_t digit(int a, uint8_t n)
{
    uint8_t shift = n * 8;
    return (uint8_t)(a >> shift);
}

double getTime() 
{
    clock_t start_time = clock(); 
        // �������� ����
        // ����� �������� ����������
    clock_t end_time = clock(); 
    clock_t sort_time = end_time - start_time;
    return (double) sort_time / CLOCKS_PER_SEC;
}

bool isOrdered(int *a, size_t n)
{
    bool answ = true;
    int prev = a[0];

    for(size_t i = 1; i < n; i++)
    {
        if(prev > a[i])
        {
            answ = false;
            break;
        }
        prev = a[i];
    }

    return answ;
}

void outputArray_(int *a, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void outputArrayHex(int *a, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        printf("%08X ", a[i]);
    }
    printf("\n");
}

void generateOrderedArray (int *a, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        *a++ = i;
    }
}

void generateOrderedBackwards (int *a, size_t n)
{
    for(size_t i = n; i > 0; i--)
    {
        *a++ = i;
    }
}

void generateRandomArray (int *a, size_t n)
{
    srand(0);

    for(size_t i = 0; i < n; i++)
    {
        *a++ = rand();
    }
}

void bubbleSort (int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        int min = a[i];
        for (size_t j = i + 1; j < n; j++)
        {
            int *a_j = &a[j];

            if (min < *a_j)
            {
                min = *a_j;
            }

            int temp = min;
            min = *a_j;
            *a_j = temp;
        }
    }
}

void mySort (int *a, size_t n)
{
    int *start = &a[0];
    int *end = &a[n];
    int *min;
    int *start1;

    while (start < end)
    {
        // find min value in range start1 - end
        min = start;
        int *start1 = start;
        while (start1 < end)
        {
            if (*min > *start1)
            {
                min = start1;
            }
            start1++;
        }
        // swap min to start
        if (min > start)
        {
            int temp = *min;
            *min = *start;
            *start = temp;
        }
        start++;
    }
}

void selectionSort (int *a, size_t n)
{
    for (int i = 1; i < n; i++)
    {
        int newElement = a[i];
        int location = i - 1;

        while(location >= 0 && a[location] > newElement)
        {
            a[location + 1] = a[location];
            location = location - 1;
        }

        a[location + 1] = newElement;
    }
}

void insertionSort (int *a, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        int minPosition = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[minPosition] > a[j])
            {
                minPosition = j;
            }
        }

        int *a_min = &a[minPosition];
        int *a_cur = &a[i];

        int tmp = *a_min;
        *a_min = *a_cur;
        *a_cur = tmp;
    }
}

void brushSort (int *a, size_t n)
{
    float factor = 1.05;
	size_t step = n - 1;
    
	while (step >= 1)
	{
		for (size_t i = 0; i + step < n; i++)
		{
            int *a_i = &a[i];
            int *a_i_step = &a[i + step];
			if (*a_i > *a_i_step)
			{
				int temp = *a_i;
                *a_i = *a_i_step;
                *a_i_step = temp;
			}
		}

	    step = (size_t)((float)step/factor);
	}
}

void shellSort (int *a, size_t n)
{
    for (int s = n / 2; s > 0; s /= 2) 
    {
        for (int i = s; i < n; ++i) 
        {
            for (int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s) 
            {
                int temp = a[j];
                a[j] = a[j + s];
                a[j + s] = temp;
            }
        }
    }
}

void radixSort (int *a, size_t n)
{
    const size_t len = sizeof(int);     // ����� �����
    const size_t radix = 256;           // ���������� ����� � ������� 2^8 // ��������� ������� ���������
    size_t basket_len = n;
    uint8_t d;

    if (basket_len > 1500000)
    {
        basket_len = 1500000;
    }

    int *b = malloc(sizeof(int) * radix),       // ����� ����� � �������
        *c = malloc(sizeof(int) * radix * basket_len);   // ������� ��� ���������� radix

    for (size_t i = 0; i < len; i++)  // ���������� ��� �������, ������� � ��������
    {   
        memset (b, 0, sizeof(int) * radix); // ������ ������ ������ b = 0  

        for (size_t j = 0; j < n; j++)
        {
            int val = a[i];
            d = digit(val, i);              // �������� �����, ������� �� ������� ������� � ������ ����� �������
            int index = (d * basket_len) + b[d];     // ������ ������
            c[index] = val;                 // ���������� ����� � ������������� ������ � �������, ������� ��������� �� ��������� ���� �����
            b[d]++;                         // ��������� ����� ����� � �������
        }

        size_t count = 0;
        
        // ������ ������� ����� �� ������ � ������ a
        for (size_t j = 0; j < radix; j++)
        {
            int k = 0;
            int bj = b[j];
            while (k < bj)
            {
                a[count++] = c[(j * basket_len) + k];
                k++;
            }
        }
    }
    free(b);
    free(c);
}

void task1()
{
    char file[] = {"task1.txt"};
    char file_res[] = {"task1_a.txt"};
    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task1 error open original file\n");
        return;
    }
    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task1 error open result file\n");
        return;
    }
    int size;
    //input matrix from file

    int input;
    input = fscanf (f_orig, "%d", &size);

    while(input > 0)
    {
        int *arr = malloc(sizeof(int) * size * size);
        
        for(int i = 0; i < size * size; i++)
        {
            fscanf(f_orig, "%d", &arr[i]);
        }

        matrix mat = createMatrixFromArray(arr, size, size);
        
        //transposeMatrix(&mat);

        //output matrix to new file

        fprintf(f_res,"%d\n", size);

        for(int col = 0; col < size; col++)
        {
            for(int row = 0; row < size; row++)
            {
                fprintf(f_res,"%d ", getElementMatrix(&mat, row, col));
            }
            fprintf(f_res,"\n");
        }
        
        input = fscanf (f_orig, "%d", &size);
    }

    fclose(f_orig);
    fclose(f_res);

    remove(file);
    rename(file_res, file);
}

void task2()
{
    // char *file = malloc(strlen()); // first argument is file name in
    // strcpy(file, );

    // int size = atoi(); // second argument is max num

    // FILE *f = fopen(file, "r");

    // int *arr = malloc(sizeof(int) * size * size); 

    // matrix mat = createMatrixFromArray(arr, size, size);
    
}
int main(int argc, char **argv) 
{
    task1();
    
    //timeExperiment();
    //timeExperimentNComp();

    return 0;
}