#include <stdio.h>
/* 
Времена года
Зима начинается с 1 декабря и длится до последнего дня февраля,
весна начинается с 1 марта и длится до последнего дня (31) мая,
лето начинается с 1 июня и длится до 31 августа,
осень начинается с 1 сентября и длится до 30 ноября

YYYY-MM-DD	Формат сезонов	Комментарии
0010-12-03	0010-00-03	Третий день зимы
0010-01-03	0010-00-34	Третий день второго месяца зимы
0010-03-03	0010-01-03	Третий день весны

Требуется написать следующие функции:

// получает параметры даты с консоли (три целых числа через тире:
// YYYY-MM-DD)
// Например, 2020-12-13
Data getData();

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data);

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая,
// лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data);

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season);


Test #1 input
10-12-03
Test #1 output
0010-12-03
0010-00-03

Test #2 input
10-01-10
Test #2 output
0010-01-10
0010-00-41

Test #3 input
10-02-15
Test #3 output
0010-02-15
0010-00-77

*/

typedef struct
{
    int yy; // год
    char mm; // месяц
    char dd; // день
}Data;

typedef struct
{
    int yy; // год
    char season; // время года (зима - 0, весна - 1, лето - 2, осень - 3)
    int day; // день от начала текущего времени года
}Season;

Data getData() {
    Data res;
    scanf("%d-%hhd-%hhd", &res.yy, &res.mm, &res.dd);
    return res;
}

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data pr) {
    printf("%04d-%02d-%02d\n", pr.yy, pr.mm, pr.dd);
}

/*
если год делится на 4 без остатка, но делится на 100 только с остатком, 
то он високосный, иначе — невисокосный, кроме случая, 
если он делится без остатка на 400 — тогда он всё равно високосный.
*/
int is_leapyear(int y) {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 > 0))
        return 1;
    return 0;
}

// Возвращает дней в месяце с учетом високосного года
int days_in_month(int year, char month) {
    int res;
    switch (month)
    {
    case 1: res = 31; break;
    case 2: res = 28; break;
    case 3: res = 31; break;
    case 4: res = 30; break;
    case 5: res = 31; break;
    case 6: res = 30; break;
    case 7: res = 31; break;
    case 8: res = 31; break;
    case 9: res = 30; break;
    case 10: res = 31; break;
    case 11: res = 30; break;
    case 12: res = 31; break;
    }
    if (month == 2 && is_leapyear(year)) 
        res = 29;
    return res;
}

int seasdays(int season, Data dat) {
    int res = 0;
    switch (season)
    {
    case 1:// весна. Месяца 3,4,5
        if (dat.mm > 3)
            res = days_in_month(dat.yy, 3);
        if (dat.mm > 4)
            res += days_in_month(dat.yy, 4);
        res += dat.dd;
    break;
    
    case 2:// Лето. Месяца 6,7,8
        if (dat.mm > 6)
            res = days_in_month(dat.yy, 6);
        if (dat.mm > 7)
            res += days_in_month(dat.yy, 7);
        res += dat.dd;
    break;

    case 3:// Осень. Месяца 9,10,11
        if (dat.mm > 9)
            res = days_in_month(dat.yy, 9);
        if (dat.mm > 10)
            res += days_in_month(dat.yy, 10);
        res += dat.dd;
    break;

    case 0:// Зима. Месяца 12,1,2
        if (dat.mm == 1)
            res = days_in_month(dat.yy, 12);
        if (dat.mm == 2)
            res = days_in_month(dat.yy, 12) + days_in_month(dat.yy, 1);
        res += dat.dd;
    break;
    }
    return res;
}

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая,
// лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
/*
(зима - 0, весна - 1, лето - 2, осень - 3)
0010-12-03	0010-00-03	Третий день зимы
0010-01-03	0010-00-34	Третий день второго месяца зимы
0010-03-03	0010-01-03	Третий день весны
*/
Season convToSeas(Data dat) {
    Season res;
    res.yy = dat.yy;
    //сезон по месяцам
    if (dat.mm > 2 && dat.mm < 6) 
        res.season = 1;// месяца 03-05 - весна
    else if (dat.mm > 5 && dat.mm < 9) 
        res.season = 2;// 06-08 - лето
    else if (dat.mm > 8 && dat.mm < 12) 
        res.season = 3;// 09-11 - осень
    else
        res.season = 0;// Зима. Месяца 12,01,02
    
    res.day = seasdays(res.season, dat);
    return res;
}

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season pr) {
    printf("%04d-%02d-%02d\n", pr.yy, pr.season, pr.day);
}

int main()
{
    Data dat;
    Season seas;
    dat = getData();
    printData(dat);
    seas = convToSeas(dat);
    printSeas(seas);

    return 0;
}

