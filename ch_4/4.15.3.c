#include <stdio.h>
/*
Возведение в степень

Напишите функцию

long long int ipow(long long int a, unsigned int n, unsigned int * depth);

Она вычисляет 
a в степени n. В depth запишите глубину рекурсивного вызова функции.

Функция ipow должна быть реализована так, чтобы для нескольких вызовов подряд
 она записывала в depth корректное значение:

int d = 7;
res = ipow(2, 32, &d);  // res = 4294967296, d = 6
res = ipow(3, 12, &d);  // res = 531441, d = 5

Sample Input:
3 12

Sample Output:
531441 5

*/
long long int ipow(long long int a, unsigned int n, unsigned int * depth) {
    //printf("start: a=%lld n=%d dp=%d\n", a, n, *depth);
    if (n == 0) {
        *depth = 1;
        return 1;
    }
    if (n == 1) {
        *depth = 1;
        return a;
    }
    long long int res;
    if (n % 2 != 0) {// нечетная степень
        res = a * ipow(a, n - 1, depth);
        //printf("нечет a=%lld n=%d dp=%d res=%lld\n", a, n - 1, *depth, res);
    } else {
        long long int half_pow = ipow(a, n / 2, depth);
        res = half_pow * half_pow;
        //printf("четн a=%lld n=%d dp=%d res=%lld\n", a, n - 1, *depth, res);
    }
    (*depth)++;
    return res;
}

int main()
{
    int a, n, d;
    
    scanf("%d%d", &a, &n);

    long long int res = ipow(a, n, &d);
    
    printf("%lld %d\n", res, d);

    return 0;
}