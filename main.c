#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "matrix.h"


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

    FILE *f = fopen(file, "r");
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
    fclose(f);
    fopen(file, "a");

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


void task6(float x)
{
    char file[] = {"task6.bin"};
    char file_res[] = {"task6_a.bin"};

    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task6 error open original file\n");
        return;
    }

    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task6 error open result file\n");
        return;
    }

    #define MAX_LEN_FORMULA  10
    double result = 0.0;
    int power, n_read;
    float operand;
    int pow_save[MAX_LEN_FORMULA];
    float oper_save[MAX_LEN_FORMULA];
    int save_counter = 0;

    n_read = fread (&power, sizeof(power), 1, f_orig);
    fread (&operand, sizeof(operand), 1, f_orig);

    while (n_read > 0)
    {
        result = 0.0;
        save_counter = 0;

        while (power > 0)
        {
            result += operand * (pow (x, power));
            pow_save[save_counter] = power;
            oper_save[save_counter] = operand;
            save_counter++;

            fread (&power, sizeof(int), 1, f_orig);
            fread (&operand, sizeof(float), 1, f_orig);
        }
        // free operand
        result += operand;
        pow_save[save_counter] = power;
        oper_save[save_counter] = operand;
        save_counter++;

        if (result > 0.0001 && result < -0.0001) // not a root
        {
            // save to new file
            for(int i = 0;  i < save_counter; i++)
            {
                fwrite(&pow_save[i], sizeof(int), 1, f_res);
                fwrite(&oper_save[i], sizeof(float), 1, f_res);
            }
        }
    }

    fclose(f_orig);
    fclose(f_res);

    remove(file);
    rename(file_res, file);
}

void task7()
{
    char file[] = {"task7.bin"};
    char file_pos[] = {"task7_pos.bin"};
    char file_neg[] = {"task7_neg.bin"};

    FILE *f = fopen(file, "r");
    if (f == NULL)
    {
        printf ("Task7 error open original file\n");
        return;
    }

    FILE *f_pos = fopen(file_pos, "w");
    if (f_pos == NULL)
    {
        printf ("Task7 error open result file\n");
        return;
    }

    FILE *f_neg = fopen(file_neg, "w");
    if (f_neg == NULL)
    {
        printf ("Task7 error open result file\n");
        return;
    }

    int read;
    int temp;

    read = fread(&temp, sizeof(int), 1, f);

    while(read > 0)
    {
        if(temp >= 0)
        {
            fwrite(&temp, sizeof(int), 1, f_pos);
        }
        else
        {
            fwrite(&temp, sizeof(int), 1, f_neg);
        }

        read = fread(&temp, sizeof(int), 1, f);
    }

    fclose(f);
    fclose(f_neg);

    f_neg = fopen(file_neg, "r");
    if (f_neg == NULL)
    {
        printf ("Task7 error open result file\n");
        return;
    }

    read = fread(&temp, sizeof(int), 1, f_neg);

    while(read > 0)
    {
        fwrite(&temp, sizeof(int), 1, f_pos);
        read = fread(&temp, sizeof(int), 1, f_neg);
    }

    fclose(f_pos);
    fclose(f_neg);
    remove(file);
    remove(file_neg);
    rename(file_pos, file);
}

void task8(size_t size)
{
    char file[] = {"task8.bin"};
    char file_res[] = {"task8_temp.bin"};

    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task8 error open original file\n");
        return;
    }

    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task8 error open result file\n");
        return;
    }

    int *arr = malloc(sizeof(int) * size * size);

    int read = fread(&arr[0], sizeof(int), 1, f_orig);

    matrix mat;
    while(read > 0)
    {
        for(size_t i = 1; i < size * size; i++)
        {
            fread(&arr[i], sizeof(int), 1, f_orig);
        }

        mat = createMatrixFromArray(arr, size, size);

        if(!isSquareMatrix(&mat))
        {
            transposeMatrix(&mat);
        }

        for(int row = 0; row < size; row++)
        {
            for(int col = 0; col < size; col++)
            {
                int temp = getElementMatrix(&mat, row, col);
                fwrite(&temp, sizeof(int), 1, f_res);
            }
        }

        read = fread(&arr[0], sizeof(int), 1, f_orig);
    }

    fclose(f_orig);
    fclose(f_res);

    remove(file);
    rename(file_res, file);
}

typedef struct _sportsman
{
    char surname[20];
    char name[20];
    char patreos[20];
    int max_point;
} sportsman;

typedef struct _best_sportsman
{
    char surname[20];
    char name[20];
    char patreos[20];
} best_sportsman;

void sportSort (sportsman *a, size_t n)
{
    for (int i = 1; i < n; i++)
    {
        sportsman newElement = a[i];
        int location = i - 1;

        while(location >= 0 && a[location].max_point > newElement.max_point)
        {
            a[location + 1] = a[location];
            location = location - 1;
        }

        a[location + 1] = newElement;
    }
}

void task9(size_t n)
{
    char file[] = {"task9.bin"};

    FILE *f_orig = fopen(file, "r");
    if (f_orig == NULL)
    {
        printf ("Task9 error open original file\n");
        return;
    }

    sportsman arr[20];  

    int read = fread(&arr[0], sizeof(sportsman), 1, f_orig);
    int count = 0;
    while(read > 0)
    {
        count++;
        read = fread(&arr[count], sizeof(sportsman), 1, f_orig);
    }

    sportSort(arr, count);

    if(n > count)
    {
        n = count;
    }

    fclose(f_orig);

    f_orig = fopen(file, "w");
    if (f_orig == NULL)
    {
        printf ("Task9 error open original file\n");
        return;
    }

    for(size_t i = 0; i < n; i++)
    {
        best_sportsman temp;
        memcpy(temp.name, arr[i].name, 20);
        memcpy(temp.surname, arr[i].surname, 20);
        memcpy(temp.patreos, arr[i].patreos, 20);
        
        fwrite(&temp, sizeof(best_sportsman), 1, f_orig);
    }

    fclose(f_orig);
}

typedef struct _storage
{
    char name[20];
    float price;
    float total_price;
    float amount;
} storage;

typedef struct _sell
{
    char name[20];
    float amount;
} sell;

void task10()
{
    char file[] = {"task10_storage.bin"};
    char file_res[] = {"task10_temp.bin"};
    char file_sell[] = {"task10_sell.bin"};

    FILE *f = fopen(file, "r");
    if (f == NULL)
    {
        printf ("Task10 error open storage file\n");
        return;
    }

    FILE *g = fopen(file_sell, "r");
    if (g == NULL)
    {
        printf ("Task10 error open sell file\n");
        return;
    }

    FILE *f_res = fopen(file_res, "w");
    if (f_res == NULL)
    {
        printf ("Task10 error open temp file\n");
        return;
    }

    storage str_arr[20];

    int read = fread(&str_arr[0], sizeof(storage), 1, f);
    int count_str = 0;

    while(read > 0)
    {
        read = fread(&str_arr[++count_str], sizeof(storage), 1, f);
    }

    sell sel;
    read = fread(&sel, sizeof(sell), 1, g);
    
    while(read > 0)
    {
        // search in storage

        for(int i = 0; i < count_str; i++)
        {
            if(strcmp(str_arr[i].name, sel.name) == 0)
            {
                str_arr[i].amount -= sel.amount;
                str_arr[i].total_price = str_arr[i].amount * str_arr[i].price;
            }
        }

        read = fread(&sel, sizeof(sell), 1, g);
    }

    for(int i = 0; i < count_str; i++)
    {
        if(str_arr[i].amount > 0)
        {
            fwrite(&str_arr[i], sizeof(storage), i, f_res);
        }
    }

    fclose(f);
    fclose(g);
    fclose(f_res);

    remove(file);
    
    rename(file_res, file);
}

int main(int argc, char **argv) 
{
    char task_4[2] = {"a"};
    float x = 4.0f;
    task1();
    task2();    
    task3();
    task4(task_4);
    task5();
    task6(x);
    task7();
    task8(3);
    task9(3);
    task10();

    return 0;
}