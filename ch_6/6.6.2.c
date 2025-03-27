#include <stdio.h>
/* Ладья

В шахматах ладья (rook) ходит только по горизонтали или вертикали.

Координаты клетки записываются как буква столбца и номер строки.
 Например, g7 место белой ладьи.

Ход записывается как координаты откуда тире координаты куда. 
Ход черной ладьи будет записан как a4-f4.

Дан ход. Напечатайте ход и может ли ладья так ходить (YES) или нет (NO).

Sample Input:
a5-g5

Sample Output:
a5-g5
YES

*/

typedef struct {
    char h;// a - h
    int v;// 1 - 8
} Point;

int main()
{
    Point from, to;
    int error = 0;

    if (scanf("%c%d-%c%d", &from.h, &from.v, &to.h, &to.v) != 4)
        error = 1;
    
    printf("%c%d-%c%d\n", from.h, from.v, to.h, to.v);

    //проверки валидности ввода. Буквы в диапазоне a-h
    if (error || from.h < 'a' || from.h > 'h')
        error = 1;
    if (error || to.h < 'a' || to.h > 'h')
        error = 1;

    //проверки валидности ввода. Цифры в диапазоне 1-8
    if (error || from.v < 1 || from.v > 8)
        error = 1;
    if (error || to.v < 1 || to.v > 8)
        error = 1;

    //ладья перемещается либо горизонтально a-h либо вертикально 1-8
    //значит буква ИЛИ цифра, при перемещении, должна оставаться одной и тойже
    if (error || from.v != to.v && from.h != to.h) 
        error = 1;

    if (error == 0)
        printf("YES");
    else 
        printf("NO");

    return 0;
}

