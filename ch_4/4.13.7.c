#include <stdio.h>
/*

Напишите макрос min2time(mm,h,m), который из mm минуты с 0:00 вычисляет
 часы h и минуты m для циферблата часов.

Использование макроса: min2time(125, hres, mres);

Sample Input:
135

Sample Output:
02:15
03:20

*/
#define min2time(mm,h,m) m = ((mm) % 60); h = ((mm) / 60 % 24)

int main()
{
    int h, m, mm;
    scanf("%d", &mm);
    
    min2time(mm, h, m);
    printf("%02d:%02d\n", h, m);
    
    min2time(mm+65, h, m);
    printf("%02d:%02d\n", h, m);

    return 0;
}