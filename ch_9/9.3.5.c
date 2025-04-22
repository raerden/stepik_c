#include <stdio.h>
/*

Сумма матриц
Даны натуральные 
n, m < 10, целочисленные матрицы 
Anm Anm​  и Bnm Bnm
​
 . Напечатайте сумму этих матриц.

Sample Input:
2 3
2 -3 1
5 4 -2

4 2 -5
-4 1 3
Sample Output:
6 -1 -4
1 5 1

*/

void number_mult(int k, int rows, int cols, int a[][cols]) {
    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            a[i][j] *= k;
}

void printmatrix(int rows, int cols, int a[][cols]) {
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            if (j > 0) printf(" ");
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

void sum(int rows, int cols, int a[][cols], int b[][cols], int c[][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    int rows, cols;
    scanf("%d%d", &rows, &cols);
    
    int a[rows][cols];
    int b[rows][cols];
    int c[rows][cols];
    
    // чтение массива a
    for(int i = 0; i < rows; i++) {
        // чтение одной строки a[i]
        for(int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    //чтение массива b
    for(int i = 0; i < rows; i++) {
        // чтение одной строки a[i]
        for(int j = 0; j < cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    sum(rows, cols, a, b, c);
    printmatrix(rows, cols, c);

    return 0;
}

