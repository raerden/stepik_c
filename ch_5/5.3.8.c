#include <stdio.h>
/*
ППлощадь прямоугольника - 1.
Прямоугольник на плоскости XY со сторонами, параллельным осям, 
задан x и y координатами левой верхней точки и его размерами. 

Напишите функцию, которая возвращает площадь прямоугольника a.

int area(struct Rect a);

Sample Input:
-7 5 12 8

Sample Output:
-7 5 12 8 96

*/
struct Rect {
    int x;      // х координата левой верхней вершины
    int y;      // y координата левой верхней вершины
    int width;  // ширина
    int height; // высота
};


int area(struct Rect a) {
    return a.width * a.height;
}



int main()
{
    struct Rect a;
    int s;
    scanf("%d %d %d %d", &a.x, &a.y, &a.width, &a.height);

    s = area(a);

    printf("%d %d %d %d %d\n", a.x, a.y, a.width, a.height, s);
    return 0;
}