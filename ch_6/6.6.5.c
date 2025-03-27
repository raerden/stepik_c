#include <stdio.h>
/* 
Холодильник и дверь
Нужно пронести холодильник в дверь. Размер двери w h сантиметров, 
размер холодильника a, b, c сантиметров.

Холодильник можно поворачивать и класть на бок.

Даны размеры двери через пробел на одной строке и размеры холодильника через 
пробел на другой строке.

Напечатайте YES, если холодильник можно пронести в дверь. Иначе напечатайте NO.

Читаем, что если ширина двери 60, то холодильник шириной 60 в него пройдет 
(если пройдет по высоте).

В дверь 80х180 холодильник 60х90х200 пройдет (YES). Надо развернуть так, 
чтобы в 80х180 проходило 60х90.

В дверь 80х180 холодильник 60х190х200 не пройдет (NO). Никак не повернуть,
 чтобы в 80х180 проходило 60х190.

Тестовые данные
Sample Input:
180 80
200 60 120

Sample Output:
YES

*/


int main()
{
    int w, h, a, b, c;
    scanf("%d%d", &w, &h);
    scanf("%d%d%d", &a, &b, &c);
    
    if ((w >= a && (h >= b || h >= c)) ||  \
        (w >= b && (h >= a || h >= c)) ||  \
        (w >= c && (h >= a || h >= b)) )
        printf("YES");
    else 
        printf("NO");

    return 0;
}

