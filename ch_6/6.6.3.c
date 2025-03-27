#include <stdio.h>
/* 

числа по возрастанию
Напишите функцию, которая сортирует 2 числа по возрастанию.

Sample Input:
5 1

Sample Output:
1 5
*/

void sort2(int * a, int * b) {
    int t;
    if (*a > *b) {
        t = *a;
        *a = *b;
        *b = t;
    }
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    sort2(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}

