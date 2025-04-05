#include <stdio.h>
/*
L_arr_1 revers
Дано натуральное число 
n<1000, далее n целых чисел.

Напечатать числа в обратном порядке.

Тестовые данные
Sample Input:
5
2 17 18 -4 9

Sample Output:
9 -4 18 17 2

*/

#define N 1000
int main(){
    int a[N];           // массив для N чисел
    int i;              // номер текущей ячейки
    int n;              // сколько чисел дано

    scanf("%d", &n);
    // читаем n чисел в массив a
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    // печатаем числа
    for(i= n-1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}