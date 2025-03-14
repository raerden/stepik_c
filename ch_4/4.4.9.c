#include <stdio.h>
/*
Дано целое шестизначное число (6 цифр). Написать функцию

void print_revers(int x);
Она печатает 6 цифр числа x в обратном порядке.

Sample Input:
123456

Sample Output:
654321

*/

void print_revers(int x);

int main()
{
    int x;

    scanf("%d", &x);       // прочитали числа
    
    print_revers(x);
     
    return 0;
}

void print_revers(int x) {
    printf("%d", x % 10);
    x = x / 10;
    printf("%d", x % 10);
    x = x / 10;
    printf("%d", x % 10);
    x = x / 10;
    printf("%d", x % 10);
    x = x / 10;
    printf("%d", x % 10);
    x = x / 10;
    printf("%d", x % 10);
    printf("\n");

    // Интересное чужое решение в одну строку
    // printf("%d%d%d%d%d%d\n", x%10, x/10%10, x/100%10, x/1000%10, x/10000%10, x/100000);
}