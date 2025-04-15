#include <stdio.h>
/*

В Си целые числа ограничены типами unsigned long long int. Чтобы работать с большими числами нужно придумать как их хранить и написать функции для работы с ними.

Число 147 это 7⋅10^0 + 4⋅10^1 + 1⋅10^2

Будем хранить коэффициенты 
a0 a1 a2​
в массиве a как a[0], a[1], a[2].
И будем в n хранить максимальную степень 10 в разложении числа по степеням 10.

Напишите функцию void elong_print(Decimal x), которая печатает длинное число и \n в конце.
*/

#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x) {
    for (int i = x.n; i >= 0; i--)
        printf("%d", x.a[i]);
    printf("\n");
}


int main()
{
    Decimal x = {{7, 4, 1}, 2}; // число 147
    Decimal zero ={{0}, 0};     // число 0 представим как 0 умножить на 10 в степени 0

    elong_print(x);     // 147
    elong_print(zero);  // 0
   
    return 0;
}