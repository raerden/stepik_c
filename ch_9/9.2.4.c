#include <stdio.h>
/*
Сумма столбца
Напишите функцию

int sum_col(int a[3][3], int icol);
которая в матрице 3х3 возвращает сумму элементов столбца с номером icol

С её помощью напишите программу, которая читает матрицу 3х3 и печатает сумму элементов последнего столбца.

Sample Input:
8 1 6
3 5 7
4 9 2

Sample Output:
15

*/

#define ROWS 3
#define COLUMNS 3

int sum_row(int a[ROWS][COLUMNS], int irow) {
    int sum = 0;
    for (int i = 0; i < COLUMNS; i++)
        sum += a[irow][i];
    return sum;
}

int sum_col(int a[ROWS][COLUMNS], int icol) 
{
    int sum = 0;
    for (int i = 0; i < ROWS; i++)
        sum += a[i][icol];
    return sum;
}

int main()
{
    int a[ROWS][COLUMNS];
    
    // чтение массива
    for(int i = 0; i < ROWS; i++) {
        // чтение одной строки a[i]
        for(int j = 0; j < COLUMNS; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sum = sum_col(a, 2);
    printf("%d\n", sum);

    return 0;
}