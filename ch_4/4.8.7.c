#include <stdio.h>
/*
Напишите функцию void min2time(int mm, int * ph, int * pm) которая минуты с 0:00 
переводит в часы и минуты на 24-часовом циферблате.

Sample Input:
123
Sample Output:
02:03
*/

void min2time(int mm, int * ph, int * pm) {
    *ph = mm / 60;  //Количество часов
    *ph = *ph % 24; //Отнимаем количество суток
    *pm = mm % 60; //Остаток минут
}

int main()
{
    int mm, h, m;
    scanf("%d", &mm);

    min2time(mm, &h, &m);

    printf("%02d:%02d\n", h, m);

    return 0;
}