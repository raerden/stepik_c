#include <stdio.h>
/*
R_decimal_fract десятичная дробь
Известно, что любое рациональное число можно представить в виде периодической 
десятичной дроби.

Написать программу, которая представляет заданную правильную простую дробь в 
виде десятичной дроби с выделением периодической части.

Входные данные:

Два натуральных числа, записанных через пробел - числитель и знаменатель дроби

Выходные данные:

Десятичное представление этой дроби в виде: 0, далее (без разделителей) 
непериодическая часть и, в скобках, периодическая часть.

Тестовые данные
Sample Input:
1 3

Sample Output:
0,(3)

1 3 - 0,(3)
1 4 - 0,25(0)
5 7 - 0,(714285)
1 21 - 0,(047619)
7 121 - 0,(0578512396694214876033)

*/

#define MAX 100

int main(){
    int m, n;   // делимое делитель
    int j, i;   //счетчики циклов
    int p, pl;  //начало и конец периодиеской части
    int a[MAX]; //Массив для делимых чисел
    int r[MAX]; //Массив для отстатка от делимого (результат)

    scanf("%d %d",&m, &n);

    i = 0;
    while (i < MAX) {
        for(j = 0; j < i; j++) {
            if (a[j] == m)
                break;// Повтор делимого. Начало периодичности
                // goto point; // можно выйти из вложенного цикла при помощи goto
        }

        a[i] = m;//вносим делимое в массив.
        r[i] = m / n;
        if (m / n != 0)
            m = m % n;
        m = m * 10;//Как при делении в столбик прибавляем к делимому 0.
        if (j < i) break;// Повтор делимого. Начало периодичности. Прерываем while
        i++;
    }

    //point: // для выхода из вложенного цикла

    p = 1;//начало периодической части
    pl = 0;//конец периодической части
    while (pl == 0 && p < i) {
        for(j = p; j < i; j++) {
            if (a[p] == a[j+1]) {
                //printf("начало %d, повтор %d\n", p, j+1);
                pl= j+1;
                break;
            }
        }
        if (pl == 0)
            p++;
    }

    //выводим результат
    printf("%d,",r[0]);//выводим первый элемент. Целая часть
    //выводим не периодическую часть
    if (p > 1)
        for(j = 1; j < p; j++) {
            printf("%d",r[j]); 
        }
    //выводим периодическую часть в скобках
    printf("(");
    for(j = p; j < i; j++) {
        printf("%d",r[j]); 
    }
    printf(")\n");

    return 0;
} 

/*
// Элегантное решение

#include <stdio.h>
#define N 1000

int main() {
    int m, n, a[N], from;
    
    scanf("%d %d", &m, &n);
    
    int i = 0;
    while (1) {
        m *= 10;
        for (int j = 0; j < i; j++) {
            if (a[j] == m) {
                from = j; 
                goto point;
            }
        }
        a[i++] = m;
        m %= n;
    }
    point:
    
    printf("0,");
    for (int j = 0; j < from; j++) printf("%d", a[j] / n);
    printf("(");
    for (int j = from; j < i; j++) printf("%d", a[j] / n);
    printf(")");
    
    return 0;
}

*/