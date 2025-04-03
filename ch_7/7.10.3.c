#include <stdio.h>
/* 
палиндром числа
Дано целое десятичное число 
1≤N≤10^9 , последняя цифра не 0.

Число, записанное десятичными цифрами является палиндромом если его
 можно одинаково прочитать как справа налево, так и наоборот.

Написать программу, которая выясняет является ли данное число палиндромом 
(печатать YES) или нет (печатать NO).

Sample Input:
123321

Sample Output:
YES

*/


int main()
{
	int a, b, x;

	scanf("%d", &a);

	x = a;
	b = 0;
	do {
		b = b * 10 + x % 10;
		x = x / 10;
	} while(x > 0);

	if (a == b)
		printf("YES\n");
	else
		printf("NO\n");
	

	return 0;
}