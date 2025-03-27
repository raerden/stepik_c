#include <stdio.h>
/* Принадлежит ли точка области?
По данным x и y координатам точки напечатайте - принадлежит точка к 
указанной области (включая границы) или нет.

Треугольная область образуется линиями функции которых:
y≤3+x
y≤3−x
y≥−2

Если принадлежит, напечатайте YES, иначе напечатайте NO.

Sample Input:
2.0 -1.5

Sample Output:
YES

*/

typedef struct {
    float x;
    float y;
} Point;

int main()
{
    Point o;
    scanf("%f%f", &o.x, &o.y);
    
    //printf("%.2f %.2f\n", o.x, o.y);
    
    if ((o.y <= 3 + o.x) && (o.y <= 3 - o.x) && (o.y >= -2))
        printf("YES");
    else 
        printf("NO");

    return 0;
}

