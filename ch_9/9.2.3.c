#include <stdio.h>
/*
Сумма строки
Напишите функцию

int sum_row(int a[3][3], int irow);
которая в матрице 3х3 возвращает сумму элементов строки с номером irow

С её помощью напишите программу, которая читает матрицу 3х3 и 
печатает сумму элементов средней строки.
*/

#define ROWS 3
#define COLUMNS 3

int sum_row(int a[ROWS][COLUMNS], int irow) {
    int sum = 0;
    for (int i = 0; i < COLUMNS; i++)
        sum += a[irow][i];
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

    int sum = sum_row(a, 1);
    printf("%d\n", sum);
    
    return 0;
}