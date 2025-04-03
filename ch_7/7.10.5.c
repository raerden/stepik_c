#include <stdio.h>
/* 
Сколько раз встретилась цифра в числе?
Даны через пробел цифра d и целое число в десятичной записи k. 
0≤k≤2^32
 
Напечатайте d, k и сколько раз цифра d входит в десятичную запись числа k?

Тестовые данные
Sample Input:

3 13234533
Sample Output:

3 13234533 4

*/


int main()
{
	long long unsigned int number, num;
	int digit, x, cnt;

	scanf("%d%llu", &digit, &number);

	cnt = 0;
	num = number;
	do {
		x = num % 10;
		num = num / 10;
		if (digit == x) cnt++;
	} while(num > 0);


	printf("%d %llu %d\n", digit, number, cnt);

	

	return 0;
}