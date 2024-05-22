#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include "matrix.h"

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
    char file[] = {"task2.txt"};
    char file_res[] = {"task2_a.txt"};

    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task2 error open original file\n");
        return;
    }

    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task2 error open result file\n");
        return;
    }

    //code here
    int range;
    char num[20];
    float num_integer, num_fraction, num_res;

    while(fscanf (f_orig, "%s", num) > 0)
    {
        num_res = atof(num);
        fprintf(f_res, "%.2f\n", num_res);
    }

    fclose(f_orig);
    fclose(f_res);

    remove(file);
    rename(file_res, file);
}

float subTask3 (float num1, float num2, char c)
{
    float answ;
    switch (c)
    {
        case '*':
            answ = num1 * num2;
        break;

        case '/':
            answ = num1 / num2;
        break;

        case '+':
            answ = num1 + num2;
        break;

        case '-':
            answ = num1 - num2;
        break;

        default:
        break;
    }

    return answ;
}

void task3()
{
    char file[] = {"task3.txt"};

    FILE *f = fopen(file, "r+t");
    if (f == NULL)
    {
        printf ("Task3 error open original file\n");
        return;
    }

    char sym1[2], sym2[2];
    bool two_operations = false;
    float num1, num2, num3, answ;

    fscanf (f, "%f", &num1);
    fscanf (f, "%s", sym1);
    fscanf (f, "%f", &num2);
    
    if(fscanf (f, "%s", sym2) > 0)
    {
        fscanf (f, "%f", &num3);
        two_operations = true;
    }

    if(two_operations)
    {
        if((sym1[0] == '+' || sym1[0] == '-') && (sym2[0] == '*' || sym2[0] == '/')) //reverse order
        {
            answ = subTask3(num2, num3, sym2[0]);
            answ = subTask3(num1, answ, sym1[0]);
        }
        else
        {
            answ = subTask3(num1, num2, sym1[0]);
            answ = subTask3(answ, num3, sym2[0]);
        }
    }
    else
    {
        answ = subTask3(num1, num2, sym1[0]);
    }

    fprintf(f, "= %f", answ);

    fclose(f);
}

void task4(char *str)
{
    char file[] = {"task4.txt"};
    char file_res[] = {"task4_a.txt"};

    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task4 error open original file\n");
        return;
    }

    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task4 error open result file\n");
        return;
    }

    int input;
    char word[50];
    input = fscanf (f_orig, "%s", word);

    while(input > 0)
    {   
        char *ret;
        ret = strstr(word, str);

        if(ret != NULL)
        {
            fprintf(f_res, "%s ", ret);
        }

        input = fscanf (f_orig, "%s", word);
    }

    fclose(f_orig);
    fclose(f_res);

    remove(file);
    rename(file_res, file);
}

void task5()
{
    char file[] = {"task5.txt"};
    char file_res[] = {"task5_a.txt"};

    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task5 error open original file\n");
        return;
    }

    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task5 error open result file\n");
        return;
    }

    char *fstr;
    int size, read;
    int max_size;
    char str[100];
    char word[100];
    char max_word[100];

    fstr = fgets(str, 100, f_orig);

    while (fstr != NULL)
    {
        char *str_read = str;
        read = sscanf(str_read, "%s", word);
        max_size = 0;

        while (read > 0)
        {
            size = strlen (word);
            if(max_size < size)
            {
                max_size = size;
                strcpy(max_word, word);
            }
            str_read += size + 1;
            read = sscanf(str_read, "%s ", word);
        }
        
        fprintf (f_res, "%s\n", max_word);
        fstr = fgets (str, 100, f_orig);
    }


    fclose (f_orig);
    fclose (f_res);

    remove (file);
    rename (file_res, file);
}

int main(int argc, char **argv) 
{
    char task_4[2] = {"a"};
    task1();
    task2();    
    task3();
    task4(task_4);
    task5();

    return 0;
}