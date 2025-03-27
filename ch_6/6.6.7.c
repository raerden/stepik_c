#include <stdio.h>
/* 
Делится на 3 или 5, но не на 15
Напишите программу, которая печатает YES, если число делится на 3 или 5, 
но не делится на 15. Иначе напечатайте NO.

Sample Input:
6

Sample Output:
YES

*/


int main()
{
    int a;
    scanf("%d", &a);

    if ((a % 15 == 0) || (a % 3 != 0 && a % 5 != 0))
        printf("NO");
    else
        printf("YES");

    return 0;
}

