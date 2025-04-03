#include <stdio.h>
/* 
Bfor_count_even Сколько четных чисел
Дано натуральное число n, потом n целых чисел.

Вычислить и напечатать сколько из них четных чисел.

Тестовые данные
Sample Input:
5
10 5 -2 6 1

Sample Output:
3

*/


int main()
{
	int i, n, x;
	int even = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		if (scanf("%d", &x) == 1 && x % 2 == 0)
			even++;
	

	printf("%d\n", even);

	return 0;
}