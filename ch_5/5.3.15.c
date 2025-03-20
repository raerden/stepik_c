#include <stdio.h>
/*
Площадь прямоугольника - 2.
Прямоугольник на плоскости XY со сторонами, параллельным осям, 
задан x и y координатами левой верхней и правой нижней вершин.

Напишите функцию, которая двигает прямоугольник на dx. 
В функцию передается указатель на этот прямоугольник p.

Sample Input:
-7 5 12 8
-6

Sample Output:
-7 5 12 8 + -6 = -13 5 12 8

*/
struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt;    // координаты левой верхней вершины
    struct Point rb;    // координаты правой нижней вершины
};


void move(struct Rect * p, int dx) {
    p->lt.x = p->lt.x + dx;
    p->rb.x = p->rb.x + dx;
    //Или через разыменование.
    // Разыменование в скобках потому, что приоритет у точки выше операции разыменования
    // (*p).lt.x += dx;
    // (*p).rb.x += dx;
}



int main()
{
    struct Rect a;
    int dx;
    scanf("%d %d %d %d", &a.lt.x, &a.lt.y, &a.rb.x, &a.rb.y);
    scanf("%d", &dx);

    printf("%d %d %d %d + %d = ", a.lt.x, a.lt.y, a.rb.x, a.rb.y, dx);

    move(&a, dx);

    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    return 0;
}