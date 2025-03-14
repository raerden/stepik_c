#include <math.h>
#include <stdio.h>
/*
geron Формула Герона

Напишите функцию

float area(int x1, int y1, int x2, int y2, int x3, int y3);
, которая вычисляет площадь треугольника по 3 точкам по формуле 
S=  sqrt( p(p−a)(p−b)(p−c) )
​ , где 

p= (a+b+c) / 2

a,b,c - длины сторон треугольника.

В функции main напечатайте найденную площадь с точностью до 3 десятичных знаков. Используйте %.3f

Sample Input:
3 0 0 4 0 0

Sample Output:
6.000

*/

float dist(int x1, int y1, int x2, int y2);
float area(int x1, int y1, int x2, int y2, int x3, int y3);

int main()
{
    int x1, y1, x2, y2, x3, y3;            // координаты вершин треугольника
    float p, s, a, b, c; //Периметр, площадь и длины сторон треугольника

    scanf("%d%d", &x1, &y1);       // прочитали числа
    scanf("%d%d", &x2, &y2);
    scanf("%d%d", &x3, &y3);

    s = area(x1, y1, x2, y2, x3, y3);
     
    printf("%.3f\n", s);         // напечатать площадь
    return 0;
}

float dist(int x1, int y1, int x2, int y2) {
    float res;
    int a, b;
    a = x1 - x2;
    b = y1 - y2;
    res = sqrt(a * a + b * b);
    return res;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    float p, s, a, b, c; //Периметр, площадь и длины сторон треугольника
    float res;

    a = dist(x1, y1, x2, y2);   // Посчитали длины сторон
    b = dist(x2, y2, x3, y3);
    c = dist(x3, y3, x1, y1);

    p = (a + b + c) / 2.0; // Периметр треугольника
    res = sqrt(p * (p - a) * (p - b) * (p - c)); // S=  sqrt( p(p−a)(p−b)(p−c) )

    return res;
}