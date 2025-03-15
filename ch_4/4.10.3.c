#include <stdio.h>
/*
move Сдвиг точки
Написать и использовать функцию

void move(int *px, int *py, int dx, int dy);
которая сдвигает точку с координатами (x,y) на dx и dy.

Sample Input:
10 5 3 4

Sample Output:
13 9

*/

void move(int *px, int *py, int dx, int dy) {
    *px += dx;
    *py += dy;
}

int main()
{
    int x, y, dx, dy;

    scanf("%d%d%d%d", &x, &y, &dx, &dy);

    move(&x, &y, dx, dy);

    printf("%d %d\n", x, y);

    return 0;
}