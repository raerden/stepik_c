#include <stdio.h>
/*
mirror Отобразить точку
Написать и использовать функцию

void mirror(int *px, int *py);

которая зеркально отображает точку с координатами (x,y) относительно оси Y.

Sample Input:
3 2

Sample Output:
-3 2
*/

void mirror(int *px, int *py) {
    *px = *px * -1;
}

int main()
{
    int x, y;

    scanf("%d%d", &x, &y);

    mirror(&x, &y);

    printf("%d %d\n", x, y);

    return 0;
}