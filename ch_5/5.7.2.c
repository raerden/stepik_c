#include <stdio.h>
#include <math.h>
/*
Поворот
Написать функцию

void rotRLine(struct Line * t);
Она поворачивает отрезок на плоскости XY на 90 градусов
по часовой стрелке вокруг точки (0,0).

Напечатайте полученный отрезок и его длину с точностью до 3 десятичных знаков.

Входные данные: 4 целых числа через пробел - x, y координаты
точки - целые числа через пробел.

Выходные данные: x y координаты концов отрезка и его длина
с точностью до десятичных знаков.

Sample Input:
3 0 0 4

Sample Output:
0 -3 4 0 5.000

*/

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;    // начало отрезка
    Point b;    // конец отрезка
    float len;  // длина отрезка
} Line;

float distance(Point a, Point b);   // расстояние между точками
void scanLine(Line * t);
void printLine(Line t);
void rotRLine(Line * t);
void rotPoint(Point * p);

int main() {
    Line t;

    scanLine(&t);
    //Поворот на 90 градусов по часовой стрелке
    rotRLine(&t);
    printLine(t);

    return 0;
}

float distance(Point a, Point b) {
    float a1, b1;
    a1 = (a.x - b.x) * (a.x - b.x);
    b1 = (a.y - b.y) * (a.y - b.y);
    return sqrt(a1 + b1);
}

void scanLine(Line * t) {
    scanf("%d%d", &t->a.x, &t->a.y);
    scanf("%d%d", &t->b.x, &t->b.y);
    t->len = distance(t->a, t->b);
}

void printLine(Line t) {
    printf("%d %d ", t.a.x, t.a.y);
    printf("%d %d ", t.b.x, t.b.y);
    printf("%.3f\n", t.len);
}

//поворот отрезка на 90 по часовой, относительно 0,0 оси координат
void rotRLine(Line * t) {
    rotPoint(&t->a);
    rotPoint(&t->b);
}

void rotPoint(Point * p) {
    Point res;
    res.x = p->y;
    res.y = p->x * -1;
    *p = res;
}