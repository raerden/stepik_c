#include <stdio.h>
/*
Площадь прямоугольника - 2.

Прямоугольник на плоскости XY со сторонами, параллельным осям, 
задан x и y координатами левой верхней и правой нижней вершин. 

Напишите функцию, которая возвращает площадь прямоугольника a.

int area(struct Rect a);

Sample Input:
-7 5 5 -3

Sample Output:
-7 5 5 -3 96

*/
struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt;    // координаты левой верхней вершины
    struct Point rb;    // координаты правой нижней вершины
};

int area(struct Rect a) {
    int width = a.rb.x - a.lt.x;
    int heigth = a.lt.y - a.rb.y;
    return width * heigth;
}

int main()
{
    struct Rect a;
    int s;
    scanf("%d %d %d %d", &a.lt.x, &a.lt.y, &a.rb.x, &a.rb.y);

    s = area(a);

    printf("%d %d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y, s);
    return 0;
}