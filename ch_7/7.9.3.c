#include <stdio.h>
/* 
Bfor_min Минимальное число
Дано натуральное число n, потом n целых чисел.

Вычислить и напечатать самое маленькое из них.

Напечатать сначала числа через пробел. На следующей строке напечатать минимальное число.

Тестовые данные
Sample Input:

3
1 5 -2
Sample Output:

1 5 -2
-2

*/


int main()
{
	int i, n, x;
	int min;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		if (scanf("%d", &x) == 1) {
			if (i == 0) min = x;
			if (min > x) min = x;
			if (i > 0) printf(" ");
			printf("%d", x);
		}
	printf("\n%d\n", min);

	return 0;
}