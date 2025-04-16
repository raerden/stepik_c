#include <stdio.h>
/*

В Си целые числа ограничены типами unsigned long long int. 
Чтобы работать с большими числами нужно придумать как их хранить и 
написать функции для работы с ними.

Число 147 это 7⋅10^0 + 4⋅10^1 + 1⋅10^2

Будем хранить коэффициенты 
a0 a1 a2​
в массиве a как a[0], a[1], a[2].
И будем в n хранить максимальную степень 10 в разложении числа по степеням 10.

Реализуйте функцию сложения чисел x и y, которая возвращает сумму чисел.
Decimal add (Decimal x, Decimal y);

Sample Input:
1234567890
325

Sample Output:
9: 1234568215

*/

#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x) {
    printf("%d: ", x.n);
    for (int i = x.n; i >= 0; i--)
        printf("%d", x.a[i]);
    printf("\n");
}

Decimal add (Decimal x1, Decimal y1) {
    Decimal x, y;
    if (x1.n < y1.n) {
        x = y1;
        y = x1;
    } else {
        x = x1;
        y = y1;
    }

    // elong_print(x);// 2: 147
    // elong_print(y);// 1: 13

    if (x.n < N - 1)
        x.a[x.n + 1] = 0;// занулить ячейку для старшего десятка 147 -> 0147
    for (int i = 0; i <= x.n; i++) { // 7 4 1
        if (i <= y.n) {
            //printf("%d+%d=%d\n", x.a[i], y.a[i], x.a[i] + y.a[i]);
            x.a[i] += y.a[i];
        }

        if (x.a[i] > 9) {
            x.a[i] -= 10;
            // printf("(i=%d)\n",x.a[i]);
            ++x.a[i+1];
            // printf("{i+1=%d}\n",x.a[i+1]);
        }
        // printf("\n");
    }
    if (x.n < N-1 && x.a[x.n + 1] > 0)
        ++x.n;

    return x;
}

Decimal strtodecimal(char * a) {
    char * p;
    char m[N];
    int x,n;
    Decimal res;
    
    //разобрать строку на числа
    n = 0;
    for(p = a; *p != '\0'; p++) {
        x = *p - '0';
        if (x >= 0 && x <= 9) {
            m[n] = x;
            n++;
        }
    }

    //перевернуть число
    x = 0;
    for (int i = n-1; i >= 0; i--) {
        res.a[x] = m[i];
        x++;
    }
    res.n = n - 1;

    return res;
}

int main()
{
    Decimal x = {{7, 4, 1}, 2};  // set number 147
    Decimal y = {{3, 1}, 1};     // set number 13

    // Decimal x = strtodecimal("147");
    // Decimal y = strtodecimal("13");

    Decimal res;

    res = add(x, y);             // res = x+y = 147+13 = 160
    elong_print(res);            // print 160
   
    return 0;
}
