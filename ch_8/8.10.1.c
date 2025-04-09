#include <stdio.h>
/*
R_arr_12 Размен
В банкомате монеты имеют цену 1, 2, 5, 10, 50, 100, 500, 1000, 5000 рублей.

Надо выдать банкоматом X рублей так, чтобы количество монет было наименьшим.

Дано натуральное число Х.

Напечатать сколько каких монет надо выдавать. Печатать цену монеты и 
количество таких монет через пробел, по паре чисел на строку, 
от самой большой монеты к меньшей.

Sample Input:
123

Sample Output:
5000 0
1000 0
500 0
100 1
50 0
10 2
5 0
2 1
1 1

*/

void printarr(int *a, int *b, int n) {
    for (int i=0; i<n; i++)
        printf("%d %d\n", a[i], b[i]);
    printf("\n");
}

int main(){

    int a[9] = {5000,1000,500,100,50,10,5,2,1};
    int b[9] = {};
    int sum;

    scanf("%d", &sum);
    // sum = 123;
    for (int i = 0; i < 9; i++) {
        b[i] = sum / a[i];
        sum = sum % a[i];
    }

    printarr(a, b, 9);


    return 0;
} 