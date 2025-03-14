#include <stdio.h>
/*
1 галеон = 17 сиклей
1 сикль = 29 кнатов

В одном кошельке g1 галеонов, s1 сиклей и k1 кнатов.

В другом кошельке g2 галеонов, s2 сиклей и k2 кнатов.
Сколько всего денег в кошельках? Представьте эту сумму, используя минимальное количество монет.

Sample Input:

1 20 5
10 1 25
Sample Output:

12 5 1
*/
int main()
{
    int galleon_1, sickle_1, knut_1;
    int galleon_2, sickle_2, knut_2;
    int galleon_sum, sickle_sum, knut_sum;
    
    // scanf("%d%d%d", &galleon_1, &sickle_1, &knut_1);
    // scanf("%d%d%d", &galleon_2, &sickle_2, &knut_2);
galleon_1 = 1; sickle_1 = 20; knut_1 = 5;
galleon_2 = 10; sickle_2 = 1; knut_2 = 25;
    
    //переводим всю сумму в минимальные монеты - Кнаты
    knut_sum = (galleon_1 * 17 * 29) + sickle_1 * 29 + knut_1 + \
               (galleon_2 * 17 * 29) + sickle_2 * 29 + knut_2;
    
    //Из общей суммы Кнатов получаем количество Галеонов
    galleon_sum = knut_sum / (17 * 29);
    
    //Вычитаем Галеоны из общей суммы Кнатов
    knut_sum = knut_sum - galleon_sum * 17 * 29;

    //Из оставшихся Кнатов получаем количество Сиклей
    sickle_sum = knut_sum / 29;

    //Вычитаем Сикли из оставшихся Кнатов
    knut_sum = knut_sum - sickle_sum * 29;

    printf("%d %d %d\n", galleon_sum, sickle_sum, knut_sum);

    return 0;
}