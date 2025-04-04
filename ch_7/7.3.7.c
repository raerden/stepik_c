#include <stdio.h>
/* 
Bloop_money4 На сколько хватит стипендии?
У студента money монет. Студент хочет покупать рис каждый день.

В первую неделю рис стоит price монет. В эти дни цена не меняется.

Каждую следующую неделю (в первый день недели, до начала рабочего дня) цена риса 
увеличивается на delta монет (price = price + delta). Неделя - 7 дней.

Первый раз студент купил рис в понедельник. Он покупал рис, пока были деньги, 
money ≥ price монет.

Входные данные: на одной строке через пробел price delta money

Выходные данные: сколько дней студент покупал рис.

Подсказка: используйте в программе переменную wday.
В ней храните номер дня недели (понедельник, вторник, среда, четверг, пятница, 
суббота, воскресенье, дальше меняется цена риса и наступает следующий понедельник).

Тестовые данные
Sample Input:
10 1 100

Sample Output:
9

*/


int main()
{
	int price; 		// цена риса
	int delta; 		// рост цены
    int money;      // количество денег

	int wday = 1;	// номер дня недели. 1 - понедельник
	int eat_days = 0;	// на сколько дней хватит денег

	// читаем входные данные (что дано)
    scanf("%d", &price);
    scanf("%d", &delta);
	scanf("%d", &money);


	while (money >= price) {
		//printf("eat days=%d, wday = %d. Price = %d, Money = %d\n", eat_days, wday, price, money);
		money -= price;	// купил рис
		eat_days++;	// посчитали сытый день
		wday++;	// счетчик дней
		if (wday == 8) {	// наступил понедельник
			wday = 1;
			price = price + delta;	// Цена выросла
		}
	}

	//printf("eat days=%d, wday = %d. Price = %d, Money = %d\n", eat_days, wday, price, money);
    printf("%d\n", eat_days);

	return 0;
}