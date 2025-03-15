#include <stdio.h>
/*
mirror_seg Отобразить отрезок
Написать и использовать функцию

void mirror_seg(int *px1, int *py1, int *px2, int *py2);
которая зеркально отображает отрезок с концами (x1,y1) и (x2,y2) относительно оси X.

Sample Input:
3 2 7 -1

Sample Output:
3 -2 7 1
*/

void mirror_seg(int *px1, int *py1, int *px2, int *py2) {
    *py1 *= -1;
    *py2 *= -1;
}

int main()
{
    int x1, y1, x2, y2;

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    mirror_seg(&x1, &y1, &x2, &y2);

    printf("%d %d %d %d\n", x1, y1, x2, y2);

    return 0;
}