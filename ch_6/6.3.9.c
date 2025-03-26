#include <stdio.h>
/* 
Принадлежит [-25, 37)
Напишите программу. Она читает целое число, печатает его и печатает YES, 
если число принадлежит [-25, 37). Иначе печатает NO

*/

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d ", x);

    if (x >= -25 && x < 37) 
        printf("YES");
    else 
        printf("NO");

    return 0;
}

