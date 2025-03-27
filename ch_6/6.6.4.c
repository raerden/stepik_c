#include <stdio.h>
/* 
Есть функция sort2 (скопируйте с предыдущей задачи).

Напишите функцию void sort3(int * x, int * y, int * z),
которая сортирует 3 числа по возрастанию.

Sample Input:
3 10 2

Sample Output:
2 3 10

*/

void sort2(int * a, int * b) {
    int t;
    if (*a > *b) {
        t = *a;
        *a = *b;
        *b = t;
    }
}

void sort3(int * x, int * y, int * z) {
    sort2(y,z);
    sort2(x,y);
    sort2(y,z);
}

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    sort3(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    return 0;
}

