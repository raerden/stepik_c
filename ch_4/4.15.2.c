#include <stdio.h>
/*
Наибольший общий делитель. Алгоритм Евклида

Даны 2 целых числа. Найти НОД(a,b) с помощью алгоритма Евклида.
Для этого написать рекурсивную функцию, которая возвращает 
наибольший общий делитель для a и b:

int nod(int a, int b);

a   b  ost(a % b)
132 21 18
 21 18  3
 18  3  0
  3  0  0

Sample Input:
10 32

Sample Output:
2

*/
int nod(int a, int b) {
    if (b == 0) return a;
    return nod(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int res = nod(a, b);
    
    printf("%d\n", res);

    return 0;
}