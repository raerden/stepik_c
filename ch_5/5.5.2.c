#include <stdio.h>
#include <assert.h>
/*
Обьявление структуры.
Функции для работы со структурой
Тестирование валидности функций
*/

struct Time {
    int h;      // часы
    int m;      // минуты
};

// печать hh:mm
void print_time(struct Time t)
{
    printf("%02d:%02d\n", t.h, t.m);
}

int time2min(struct Time t)
{
    int res;
    res = t.h * 60 + t.m;
    return res;
}

// mm -> h, m
struct Time min2time(int mm)
{
    struct Time res;    // объявили res типа struct Time
    res.m = mm % 60;     // вычислили значение res
    res.h = mm / 60 % 24;
    return res;         // вернули res
}
/*
// Или такой вариант реализации функции min2time
// mm -> h, m
struct Time min2time(int mm)
{
    struct Time res = {
        .m = mm %60,
        .h = mm / 60 % 24
        };
    return res;
}
*/

//Сравнение двух структур
int is_equal(struct Time t1, struct Time t2)
{
    if (t1.h != t2.h)
        return 0;
    if (t1.m != t2.m)
        return 0;
    return 1;
}

// t1 + t2
struct Time add(struct Time t1, struct Time t2)
{
    int mmres = time2min(t1) + time2min(t2);    // всего минут с 0:00
    struct Time res = min2time(mmres);          // из минут во время
    return res;                                 // вернули время
}

int main()
{
    struct Time t1 = {22, 55};
    struct Time dt = { 2, 7};
    struct Time t2,                     // результат
                expected_res = {1, 2};  // ожидаемый результат для тестов

    int mm = time2min(dt);  // 2:07
    //Тест функции time2min
    assert(mm == 127);

    struct Time t = min2time(127);
    print_time(t); 

    //Тест функции min2time
    assert(1==is_equal(min2time(127), dt));

    t2 = add(t1, dt);
    print_time(t2);
    //Тест функции add (сложение вреимени)
    assert(1==is_equal(t2, expected_res));

    return 0;
}

