#include <stdio.h>
/*
Определите структуру, описывающую окружность с центром с координатами x и y
типа int и радиусом r типа double так, чтобы было корректен прототип функции:

Circle zoom(Circle c, int k);

*/

typedef struct {
    int x;
    int y;
    double r;
} Circle;
//или
/*
struct str_Circle {
    int x;
    int y;
    double r;
};
typedef struct str_Circle Circle;
*/

Circle zoom(Circle c, int k);

int main()
{
    Circle c = {1, 2, 3};
    Circle z = zoom(c, 5);
    printf("%.0lf\n", z.r);
    return 0;
}

Circle zoom(Circle c, int k)
{
    Circle res = c;
    res.r *= k;
    return res;
}