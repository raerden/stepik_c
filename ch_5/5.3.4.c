#include <stdio.h>
/*
time_def Определение структуры Time

Для хранения и представления показаний часов напишите 
структуру с именем Time и целочисленными полями h и m.

*/

struct Time {
    int h;//максимум 24
    int m;//максимум 60
   };

int main()
{
    struct Time t;
    scanf("%d:%d", &t.h, &t.m);
    printf("%02d:%02d\n", t.h, t.m);
    return 0;
}