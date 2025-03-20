#include <stdio.h>
/*
Сдвиг прямоугольника на dx
Прямоугольник на плоскости XY со сторонами, параллельным осям, 
задан x и y координатами левой верхней точк и и его размерами. 
Для его хранения объявлена структура struct Rect

Напишите функцию, которая двигает прямоугольник на dx. 
В функцию передается указатель на этот прямоугольник p.

void move(struct Rect * p, int dx);

Sample Input:
-7 5 12 8
-6

Sample Output:
-7 5 12 8 + -6 = -13 5 12 8

*/
struct Rect {
    int x;      // х координата левой верхней вершины
    int y;      // y координата левой верхней вершины
    int width;  // ширина
    int height; // высота
};


void move(struct Rect * p, int dx) {
    p->x = p->x + dx;
}



int main()
{
    struct Rect a;
    int dx;
    scanf("%d %d %d %d", &a.x, &a.y, &a.width, &a.height);
    scanf("%d", &dx);

    printf("%d %d %d %d + %d = ", a.x, a.y, a.width, a.height, dx);

    move(&a, dx);

    printf("%d %d %d %d\n", a.x, a.y, a.width, a.height);
    return 0;
}