#include <stdio.h>
/*
Магический квадрат
Квадрат называют "магическим", если у него одинаковая сумма 
элементов по всем столбцам, строкам и диагоналям.

Sample Input:
8 1 6
3 5 7
4 9 2

Sample Output:
MAGIC

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

int sum_diag(int a[ROWS][COLUMNS]) {
    int sum = 0;
    for (int i=0; i < ROWS; i++)
        sum += a[i][i];
    return sum;
}

int sum_diag2(int a[ROWS][COLUMNS]) {
    int sum = 0;
    int i,j;
    for (i=0,j=COLUMNS-1; i < ROWS; i++, j--)
        sum += a[i][j];
    return sum;
}

int is_magic(int a[ROWS][COLUMNS]) {
    int sum = sum_diag(a);

    if (sum != sum_diag2(a))
        return 0;

    for (int i=0; i < ROWS; i++)
        if (sum != sum_row(a,i)) 
            return 0;

    for (int i=0; i < COLUMNS; i++)
        if (sum != sum_col(a,i)) 
            return 0;

    return 1;
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

    printf("%s\n", is_magic(a) ? "MAGIC" : "NO");

    return 0;
}