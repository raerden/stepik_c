#include <stdio.h>
/*
Написать функцию, которая переводит температуру из градусов Фаренгейта F в градусы Цельсия C по формуле

F=C⋅9/5+32

Измерения - в целых числах.
*/

float celsius(int fahr);

int main()
{
    int fhr;    // градусы Фаренгейта
    float cls;    // градусы Цельсия

    scanf("Введите градусы в Фаренгейтах:%d", &fhr);
    cls = celsius(fhr);
    printf("Градусы в Цельсиях: %.2f\n", cls);    // .2f - печатать с точностью до 2 знаков после .


    return 0;
}

// C = (F-32) / 1.8
float celsius(int fahr) {
    float res;
    res = (fahr - 32) / 1.8;
    return res;
}