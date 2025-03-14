#include <stdio.h>
/*
Написать реализацию функции swap и её вызов в  main
*/

void swap(int * px, int * py) {
    int t;
    t = *px;
    *px = *py;
    *py = t;
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);      // если ввели 2 3

    swap(&x, &y);

    printf("%d %d\n", x, y);    // то напечатает 3 2

    return 0;
}

