#include <stdio.h>
/* 
Пересекаются ли прямоугольники?
Дана структура, описывающая прямоугольник со сторонами, параллельными осям координат. 
Реализуйте функцию, is_crossed, которая возвращает 1, если два прямоугольника 
пересекаются и 0 в противном случае.

Если у двух прямоугольников общая хотя бы одна точка, эти прямоугольники пересекаются.

int is_crossed(struct Rect a, struct Rect b);

Sample Input:
-7 8 12 5
1 9 14 3

Sample Output:
-7 8 12 5
1 9 14 3
1

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
    printf("%d\n", is_crossed(r1,r2));

    return 0;
}

