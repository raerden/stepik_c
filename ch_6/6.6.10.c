#include <stdio.h>
/* 
Пересечение прямоугольников
Дана структура, описывающая прямоугольник со сторонами, параллельными осям координат.

Реализуйте функцию, intersection, которая возвращает координаты точек прямоугольника, 
образованного в результате пересечения двух прямоугольников, 
которые гарантированно имеют хотя бы одну общую точку.

struct Rect intersection(struct Rect a, struct Rect b);


Sample Input:
-7 8 12 5
1 9 14 3

Sample Output:
-7 8 12 5
1 9 14 3
1 8 12 5


Test #2 input
1 9 14 3
-7 18 12 5
Test #2 output
1 9 14 3
-7 18 12 5
1 9 12 5


Test #3 input
-7 18 12 5
1 9 14 3
Test #3 output
-7 18 12 5
1 9 14 3
1 9 12 5
*/

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

//Проверяем условие когда прямоугольники НЕ пересекаются
int is_crossed(struct Rect a, struct Rect b) {
    if ((a.rb.y > b.lt.y || b.rb.y > a.lt.y) || \
        (a.rb.x < b.lt.x || b.rb.x < a.lt.x))
        return 0;
    return 1;
}

struct Rect intersection(struct Rect a, struct Rect b) {
    struct Rect res;
    res.lt.x = a.lt.x >= b.lt.x ? a.lt.x : b.lt.x;
    res.lt.y = a.lt.y >= b.lt.y ? b.lt.y : a.lt.y;
    res.rb.x = a.rb.x >= b.rb.x ? b.rb.x : a.rb.x;
    res.rb.y = a.rb.y >= b.rb.y ? a.rb.y : b.rb.y;
    return res;
}

void print_rect(struct Rect r) {
    printf("%d %d %d %d\n", r.lt.x, r.lt.y, r.rb.x, r.rb.y);
}


int main()
{
    struct Rect r1, r2;

    scanf("%d%d%d%d", &r1.lt.x, &r1.lt.y, &r1.rb.x, &r1.rb.y);
    scanf("%d%d%d%d", &r2.lt.x, &r2.lt.y, &r2.rb.x, &r2.rb.y);

    print_rect(r1);
    print_rect(r2);

    if (is_crossed(r1, r2)) {
        struct Rect res = intersection(r1, r2);
        print_rect(res);
    }


    return 0;
}

