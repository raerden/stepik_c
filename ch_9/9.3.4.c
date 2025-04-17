#include <stdio.h>
/*
Умножение матрицы на число
Даны натуральные 
n n, m m, целочисленная матрица 
An mA nm​   и целое число k k.

Напечатайте результат умножения матрицы 
AnmA nm​  на kk.

Матрица B=k⋅A
B=k⋅A, когда bij=k⋅aijb ij =k⋅a ij
​

Рекомендуем написать функцию

void number_mult(int k, int rows, int cols, int a[][cols]);

Sample Input:

3 4
1 2 3 4
11 12 13 14
21 22 23 24
10
Sample Output:

10 20 30 40
110 120 130 140
210 220 230 240

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

int main()
{
    int rows, cols;
    scanf("%d%d", &rows, &cols);
    
    int a[rows][cols];
    // чтение массива
    for(int i = 0; i < rows; i++) {
        // чтение одной строки a[i]
        for(int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    printf("\n");

    number_mult(k, rows, cols, a);

    printmatrix(rows, cols, a);

    return 0;
}