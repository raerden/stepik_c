#include <stdio.h>
/* 
Наибольший по площади прямоугольник
Дана структура, описывающая прямоугольник со сторонами,
параллельными осям координат. Реализуйте функцию, max,
возвращающую больший по площади прямоугольник. 
Если два прямоугольника имеют равные площади, возвратите любой из них.

struct Rect * max(struct Rect * pa, struct Rect * pb);

Sample Input:
-7 5 5 -3
1 3 14 -4

Sample Output:
-7 5 5 -3 96
1 3 14 -4 91
96

*/

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

int rect_s(struct Rect r) {
    int res;
    res = (r.rb.x - r.lt.x) * (r.rb.y - r.lt.y);
    return res < 0 ? res * -1 : res;
}

struct Rect * max(struct Rect * pa, struct Rect * pb) {
    struct Rect * pm = pa;
    int s1 = rect_s(*pa);
    int s2 = rect_s(*pb);
    if (s1 < s2)
        pm = pb;
    return pm;
}

void print_rect(struct Rect r) {
    printf("%d %d %d %d %d\n", r.lt.x, r.lt.y, r.rb.x, r.rb.y, rect_s(r));
}


int main()
{
    struct Rect r1, r2;

    scanf("%d%d%d%d", &r1.lt.x, &r1.lt.y, &r1.rb.x, &r1.rb.y);
    scanf("%d%d%d%d", &r2.lt.x, &r2.lt.y, &r2.rb.x, &r2.rb.y);

    print_rect(r1);
    print_rect(r2);

    struct Rect * m;
    m = max(&r1, &r2);
    printf("%d\n", rect_s(*m));

    return 0;
}
