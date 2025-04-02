#include <stdio.h>
/* 
Высокие студенты
У студентов измерили рост в сантиметрах (целое число) и записали числа на одной 
строке через пробел. Напечатайте сколько студентов измерили и сколько человек
 было выше 170 сантиметров?

Тестовые данные
Sample Input:

155 172 180 170 164 160
Sample Output:

6 2

*/


int main()
{
	int rost;
	int std = 0;
	int tall_std = 0;
	
	while (scanf("%d", &rost) == 1) {
		std++;
		if (rost > 170) 
			tall_std++;
	}

	printf("%d %d\n", std, tall_std);

	return 0;
}