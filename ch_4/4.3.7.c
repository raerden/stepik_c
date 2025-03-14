#include <stdio.h>
/*
Условие задачи
Написать функцию, которая переводит температуру из градусов Цельсия C в градусы Фаренгейта F по формуле
F=C⋅9/5+32
*/

float fahr(int cel);

int main()
{
    int cel;    // градусы Цельсия
    float f;    // градусы Фаренгейта

    scanf("%d", &cel);
    f = fahr(cel);
    printf("%.2f\n", f);    // .2f - печатать с точностью до 2 знаков после .

    return 0;
}

// F=C⋅9/5+32
float fahr(int cel) {
    float res;
    res = (cel * 1.8) + 32;
    return res;
}