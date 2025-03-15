#include <stdio.h>
/*

time2minMacro h, m в минуты с полуночи
Напишите макрос time2min(h,m), который из часов и минут вычисляет минуты с 0:00.

Использование макроса: mm = time2min(1, 25);

Sample Input:
2:15

Sample Output:
135
270
200

*/
#define time2min(h,m) ((h) * 60 + (m))

int main()
{
    int h, m, mm;
    scanf("%d:%d", &h, &m);
    
    mm = time2min(h, m);
    printf("%d\n", mm);
    
    mm = time2min(h, m)*2;
    printf("%d\n", mm);
    
    mm = time2min(h+1, m+5);
    printf("%d\n", mm);

    return 0;
}