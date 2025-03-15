#include <stdio.h>
/*
center Центр прямоугольника
Прямоугольник со сторонами параллельными осям Х и Y задан координатами 
верхней левой (xlt,ylt) и правой нижней точки (xrb, yrb).

Найти координаты центра прямоугольника. 
Гарантируется, что это будет точка в целых координатах.

Написать и использовать функцию, которая по координатам левой верхней и 
правой нижней точки находит координаты центра.

void center(int xlt, int ylt, int xrb, int yrb, int *pxc, int *pyc);

Input format: 4 целых числа через пробел - xlt ylt xrb yrb - координаты вершин прямоугольника.

Output format: 2 целых числа через пробел - x y - координаты центра прямоугольника.

Sample Input:
0 8 10 4

Sample Output:
5 6

*/

void center(int xlt, int ylt, int xrb, int yrb, int *pxc, int *pyc) {
    *pxc = xlt + (xrb - xlt) / 2;
    *pyc = ylt + (yrb - ylt) / 2;
}

int main()
{
    int xlt, ylt, xrb, yrb;
    int xc, yc;

    scanf("%d%d%d%d", &xlt, &ylt, &xrb, &yrb);

    center(xlt, ylt, xrb, yrb, &xc, &yc);

    printf("%d %d\n", xc, yc);

    return 0;
}