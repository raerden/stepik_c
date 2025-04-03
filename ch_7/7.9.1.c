#include <stdio.h>
/* 
Сумма четных чисел
Дано натуральное число n, потом n целых чисел.

Вычислить и напечатать сумму только четных чисел.

Тестовые данные
Sample Input:
5
10 5 -2 6 1

Sample Output:
14

*/


int main()
{
	int i, n, x;
	int sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		if (scanf("%d", &x) == 1 && x % 2 == 0)
			sum += x;
	

	printf("%d\n", sum);

	return 0;
}