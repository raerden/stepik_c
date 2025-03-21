#include <stdio.h>
/*
12-часовой циферблат
Ручные часы имеют 12 часовой циферблат (от 00:00 до 11:59).

Для хранения и представления показаний часов используется структура:

typedef struct{
    int h; // часы
    int min; // минуты (от 0 до 59)
}TicTac;

Написать следующие функции для работы с часами:

// получает показание часов a и возвращает показание этих часов
// через min минут, .
TicTac after(TicTac a, int min);

// "переводит" вперед стрелки этих часов (me)
// на a.h часов и a.min минут
void forward(TicTac * me, TicTac a);

// "переводит" назад стрелки этих часов (me)
// на a.h часов и a.min минут
void backward(TicTac * me, TicTac a);

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b);

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a);

Sample Input:
02:10 25 02:10

Sample Output:
equal: 1
after: 02:35
forward: 04:20
backward: 00:00

*/

typedef struct{
    int h; // часы
    int min; // минуты (от 0 до 59)
}TicTac;


//Переводит часы и минуты в общие минуты
int time2min(TicTac a);

//Переводит минуты в структуру TicTac (часы и минуты)
TicTac min2time(int min);

// получает показание часов a и возвращает показание этих часов
// через min минут, .
TicTac after(TicTac a, int min);

// "переводит" вперед стрелки этих часов (me)
// на a.h часов и a.min минут
void forward(TicTac * me, TicTac a);

// "переводит" назад стрелки этих часов (me)
// на a.h часов и a.min минут
void backward(TicTac * me, TicTac a);

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b);

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a);


int main(){
    TicTac a,b,c;
    int mk;

    scanf("%d:%d", &(a.h), &(a.min));
    scanf("%d", &mk);
    scanf("%d:%d", &(b.h), &(b.min));
    // a.h = 2;
    // a.min = 10;
    // mk = 25;
    // b.h = 2;
    // b.min = 10;

    printf("equal: %d\n",isEqualTime(a,b));
    c = after(a, mk);
    printf("after: ");
    printTic(c);

    c = a;
    printf("forward: ");
    forward(&a, b);
    printTic(a);

    printf("backward: ");
    backward(&c, b);
    printTic(c);

    return 0;
}



//Переводит часы и минуты в общие минуты
int time2min(TicTac a) {
    return a.h * 60 + a.min;
}

//Переводит минуты в структуру TicTac (часы и минуты)
TicTac min2time(int min) {
    TicTac res;
    res.h = min / 60 % 12;
    res.min = min % 60;
    return res;
}

// получает показание часов a и возвращает показание этих часов
// через min минут, .
TicTac after(TicTac a, int min) {
    //Перевод часов и минут в общие минуты - time2min()
    //прибавить сдвиг min
    //Общие минуты перевести в формат TicTac - min2time()
    return min2time(time2min(a) + min);
}

// "переводит" вперед стрелки этих часов (me)
// на a.h часов и a.min минут
void forward(TicTac * me, TicTac a) {
    int min;
    min = time2min(*me) + time2min(a);//общее количество минут на обоих часах
    *me = min2time(min);
}

// "переводит" назад стрелки этих часов (me)
// на a.h часов и a.min минут
void backward(TicTac * me, TicTac a) {
    int min;
    //отнять общее кол-во минут часов A от минут часов Me
    //прибавить 720 минут (60*12) чтобы избежать отрицательных значений
    min = 720 + (time2min(*me) - time2min(a));
    *me = min2time(min);//Перевести общие минут в 12часовой формат часов
}

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b) {
    return a.h == b.h && a.min == b.min;
}

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a) {
    printf("%02d:%02d\n", a.h, a.min);
}
