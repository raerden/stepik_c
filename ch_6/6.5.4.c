#include <stdio.h>
/* 
Сколько столов

Из 4 ножек и 1 столешницы делают 1 стол.
Сколько столов можно сделать из N ножек и K столешниц?

Sample Input:
14 6

Sample Output:
3
*/

int main()
{
    int n, stol;
    scanf("%d%d", &n, &stol);
    n = n / 4;

    if (n > 0 && stol > 0) {
        printf("%d", (stol <= n) ? stol : n);
    }
    else 
        printf("0");

    return 0;
}

