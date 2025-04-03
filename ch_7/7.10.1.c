#include <stdio.h>
/* 
for_4 n! факториал
Дано 
0 ≤ n ≤ 12
Вычислите n!

Тестовые данные
Sample Input:
3

Sample Output:
6

1 2 3


*/


int main()
{
	int i, n, x;

	scanf("%d", &n);

	x = 1;
	for (i = 0; i < n; i++)
		x += x * i;


	printf("%d\n", x);

	return 0;
}