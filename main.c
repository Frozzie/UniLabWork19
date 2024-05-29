#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "matrix.h"

typedef struct _sportsman
{
    char surname[20];
    char name[20];
    char patreos[20];
    int  max_point;
} sportsman;

typedef struct _best_sportsman
{
    char surname[20];
    char name[20];
    char patreos[20];
} best_sportsman;

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

void file_gen_task1(int max_lines) 
{
    FILE *file = fopen("task1.txt", "w");
    
    if (file == NULL)
    {
        printf ("Task1 error open original file\n");
        return;
    }

    srand((unsigned int) time(NULL));

    fprintf(file, "%d\n", max_lines);

    for (int i = 0; i < max_lines; i++) 
    {
        for (int j = 0; j < max_lines; j++) 
        {
            int number = rand() % 1000;

            fprintf(file, "%d ", number);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void file_gen_task2(int max_lines)
{
    FILE *file = fopen("task2.txt", "w");
    
    if (file == NULL)
    {
        printf ("Task2 error open original file\n");
        return;
    }

    for (int i = 0; i < max_lines; i++) 
    {
        int number = 1 + rand() % 999;
        fprintf(file, "%d.", number);
        number = 1 + rand() % 999;
        fprintf(file, "%d", number);

        fprintf(file, "\n");
    }

    fclose(file);
}

void file_gen_task3()
{
    FILE *file = fopen("task3.txt", "w");
    
    if (file == NULL)
    {
        printf ("Task3 error open original file\n");
        return;
    }

    int op_amount = rand() % 2, number;
    for(int i = 0; i <= op_amount; i++)
    {
        number = 1 + rand() % 9;
        fprintf(file, "%d ", number);

        int sym = 1 + rand() % 4;
        if(sym == 1)
        {
            fprintf(file,"/ ");
        }
        else if(sym == 2)
        {
            fprintf(file,"* ");
        }
        else if(sym == 3)
        {
            fprintf(file,"- ");
        }
        else if(sym == 4)
        {
            fprintf(file,"+ ");
        }
    }

    number = 1 + rand() % 9;
    fprintf(file, "%d =", number);    

    fclose(file);
}

char generate_random_letter() 
{
    int is_upper = rand() % 2;  // Randomly choose between uppercase and lowercase
    if (is_upper) {
        return 'A' + rand() % 26;  // Random uppercase letter
    } else {
        return 'a' + rand() % 26;  // Random lowercase letter
    }
}

void file_gen_task4(int max_lines, int max_letters_per_line)
{
    FILE *file = fopen("task4.txt", "w");

    if (file == NULL)
    {
        printf ("Task4 error open original file\n");
        return;
    }

    for (int i = 0; i < max_lines; i++) 
    {
        int letters_in_line = rand() % max_letters_per_line + 1; // Ensure at least 1 letter per line
        for (int j = 0; j < letters_in_line; j++) 
        {
            char letter = generate_random_letter();
            fprintf(file, "%c", letter);

            if(rand() % 2)
            {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void file_gen_task5(int max_lines, int max_letters_per_line)
{
    FILE *file = fopen("task5.txt", "w");

    if (file == NULL)
    {
        printf ("Task5 error open original file\n");
        return;
    }

    for (int i = 0; i < max_lines; i++) 
    {
        int letters_in_line = rand() % max_letters_per_line + 1; // Ensure at least 1 letter per line
        for (int j = 0; j < letters_in_line; j++) 
        {
            char letter = generate_random_letter();
            fprintf(file, "%c", letter);

            if(rand() % 2)
            {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void file_gen_task6_()
{
    FILE *file = fopen("task6.bin", "w");

    if (file == NULL)
    {
        printf ("Task6 error open original file\n");
        return;
    }

    // int count = 1 + rand() % 10;
    // for (int j = 0; j < count; j++)
    // {
        int num = 1 + rand() % 10, power;
        power = num;
        for(int i = 0; i <= num; i++)
        {
            fwrite (&power, sizeof(int), 1, file);
            power--;

            float num2 = ((float)rand() / (float)RAND_MAX) * (float)(rand() % 1000);
            fwrite(&num2, sizeof(float), 1, file);
        }
    // }

    fclose(file);
}

void file_gen_task6(float x)
{
    FILE *file = fopen("task6.bin", "w");

    if (file == NULL)
    {
        printf ("Task6 error open original file\n");
        return;
    }
    int count = 1 + rand() % 5;

    for (int j = 0; j < count; j++)
    {
        int num = 1 + rand() % 5, power;
        power = num;
        double math = 0.0;

        for(int i = 0; i <= num; i++)
        {
            double num1 = ((double)rand() / (double)RAND_MAX) * (double)(rand() % 100);
            
            fwrite (&power, sizeof(int), 1, file);

            if(power == 0)
            {
                num1 = 0.0 - math;
            }
            else
            {
                math += num1 * pow(x, power);
            }
            float temp = (float)num1;
            fwrite(&temp, sizeof(float), 1, file);

            power--;
        }
    }
    

    fclose(file);
}

void file_gen_task7()
{
    FILE *file = fopen("task7.bin", "w");

    if (file == NULL)
    {
        printf ("Task7 error open original file\n");
        return;
    }

    int count = 1 + rand() % 100, num;

    for(int i = 0; i < count; i++)
    {
        num = 1 + rand() % 1000;
        fwrite(&num, sizeof(int), 1, file);

        num = 1 + rand() % 1000;
        num = -num;
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);
}

void file_gen_task8(size_t size)
{
    FILE *file = fopen("task8.bin", "w");

    if (file == NULL)
    {
        printf ("Task8 error open original file\n");
        return;
    }

    int count = 1 + rand() % 100, num;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            num = 1 + rand() % 1000;
            fwrite(&num, sizeof(int), 1, file);
        }
    }

    fclose(file);
}

void file_gen_task9()
{
    FILE *file = fopen("task9.bin", "w");

    if (file == NULL)
    {
        printf ("Task9 error open original file\n");
        return;
    }

    sportsman arr[5] = {
        {
            .name = "Ivan",
            .surname = "Ivanov",
            .patreos = "Ivanovich"
        },
        {
            .name = "Yakov",
            .surname = "Ivanov",
            .patreos = "Ivanovich"
        },
        {
            .name = "Marina",
            .surname = "Ivanova",
            .patreos = "Ivanovna"
        },
        {
            .name = "Nicolay",
            .surname = "Ivanov",
            .patreos = "Ivanovich"
        },
        {
            .name = "Konstantin",
            .surname = "Sokolov",
            .patreos = "Ivanovich"
        },
    };

    int amount = 5;

    for(int i = 0; i < amount; i++)
    {
        int num = 1 + rand() % 100;
        arr[i].max_point = num;

        fwrite(&arr[i], sizeof(sportsman), 1, file);
    }

    fclose(file);
}

void file_gen_task10()
{
    FILE *file = fopen("task10.bin", "w");

    if (file == NULL)
    {
        printf ("Task9 error open original file\n");
        return;
    }

    storage arr[5] = {
        {
           .name = "Cabbage", 
        },
        {
           .name = "Onions", 
        },
        {
           .name = "Carrots", 
        },
        {
           .name = "Apples", 
        },
        {
           .name = "Oranges", 
        },
    };

    int amount = 5;

    for(int i = 0; i < amount; i++)
    {
        int num1 = 1 + rand() % 100;
        arr[i].price = num1;

        int num2 = 1 + rand() % 100;
        arr[i].amount = num2;

        arr[i].total_price = num1 * num2;
        
        fwrite(&arr[i], sizeof(storage), 1, file);
    }

    fclose(file);
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

    fflush(f_orig);
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
        fprintf(f_res, "%.2e\n", num_res);
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

            n_read = fread (&power, sizeof(int), 1, f_orig);
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
        n_read = fread (&power, sizeof(power), 1, f_orig);
        fread (&operand, sizeof(operand), 1, f_orig);
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

void filePrint_txt (char *file_name)
{
    FILE *f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf ("error open storage file\n");
        return;
    }

    fflush(f);
    char storage;

    int num = fread(&storage, sizeof(char), 1, f);
    while(num > 0)
    {
        printf("%c", storage);

        num = fread(&storage, sizeof(char), 1, f);
    }
}

void filePrint_bin_int (char *file_name, int num_in_line)
{
    FILE *f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf ("error open storage file\n");
        return;
    }

    fflush(f);
    int storage, count = 0;

    int num = fread(&storage, sizeof(int), 1, f);

    while(num > 0)
    {
        printf("%d, ", storage);

        if(++count >= num_in_line)
        {
            count = 0;
            printf("\n");
        }

        num = fread(&storage, sizeof(int), 1, f);
    }
}

void filePrint_bin_float (char *file_name, int num_in_line)
{
    FILE *f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf ("error open storage file\n");
        return;
    }

    fflush(f);
    float storage;

    int num = fread(&storage, sizeof(float), 1, f), count = 0;

    while(num > 0)
    {
        printf("%f, ", storage);

        if(++count >= num_in_line)
        {
            count = 0;
            printf("\n");
        }

        num = fread(&storage, sizeof(float), 1, f), count = 0;
    }
}

int main(int argc, char **argv) 
{
    char task_4[] = {"a"};
    float x = 2.0f;

    printf(" Task 1 source: \n");
    file_gen_task1(4);
    filePrint_txt("task1.txt");
    task1();
    printf(" Task 1 result: \n");
    filePrint_txt("task1.txt");

    printf("\n Task 2 source: \n");
    file_gen_task2(10);
    filePrint_txt("task2.txt");
    task2();
    printf("\n Task 2 result: \n");
    filePrint_txt("task2.txt");

    printf("\n Task 3 source: \n");
    file_gen_task3();
    filePrint_txt("task3.txt");
    task3();
    printf("\n Task 3 result: \n");
    filePrint_txt("task3.txt");

    printf("\n\n Task 4 source: \n");
    file_gen_task4(10, 10);
    filePrint_txt("task4.txt");
    task4(task_4);
    printf("\n Task 4 result: \n");
    filePrint_txt("task4.txt");

    printf("\n Task 5 source: \n");
    file_gen_task5(10, 10);
    filePrint_txt("task5.txt");
    task5();
    printf("\n Task 5 result:\n");
    filePrint_txt("task5.txt");

    printf("\n Task 6 source: \n");
    file_gen_task6(x);
    filePrint_bin_int("task6.bin", 10);
    task6(x);
    printf("\n Task 6 result:\n");
    filePrint_bin_int("task6.bin", 10);

    printf("\n\n Task 7 source: \n");
    file_gen_task7();
    filePrint_bin_int("task7.bin", 10);
    task7();
    printf("\n\n Task 7 result:\n");
    filePrint_bin_int("task7.bin", 10);

    printf("\n\n Task 8 source: \n");
    file_gen_task8(3);
    filePrint_bin_int("task8.bin", 10);
    task8(3);
    printf("\n\n Task 8 result:\n");
    filePrint_bin_int("task8.bin", 10);

    printf("\n\n Task 9 source: \n");
    file_gen_task9();
    filePrint_bin_int("task9.bin", 10);
    task9(3);
    printf("\n Task 9 result:\n");
    filePrint_bin_int("task9.bin", 10);

    printf("\n\n Task 10 source: \n");
    file_gen_task10();
    filePrint_bin_int("task10.bin", 10);
    task10();
    printf("\n Task 10 result:\n");
    filePrint_bin_int("task10.bin", 10);


    return 0;
}