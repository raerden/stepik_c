#include <stdio.h>
#include <ctype.h>

/* 
Сколько раз встретилась цифра в ОЧЕНЬ БОЛЬШОМ числе?
Даны через пробел цифра d и целое число в десятичной записи k. 
0≤k≤10^1000
 

Напечатайте d, k и сколько раз цифра d входит в десятичную запись числа k?

Подсказка-1: это не копия предыдущей задачи. k не поместится ни в один 
целочисленный тип. Придется читать и обрабатывать по символу.

Sample Input:
3 13234533

Sample Output:
3 13234533 4

Test #7 input
0 1234567890123456789012345678901234567890
Test #7 output
0 1234567890123456789012345678901234567890 4

*/


int main()
{
	int cnt;
	int digit, x, c;
	
	scanf("%d", &digit);
	printf("%d ", digit);
	cnt = 0;
	while((c = getchar()) != EOF) 
		if (isdigit(c)) {
			x = -1;
			switch (c)
			{
				case 48: x = 0;	break;
				case 49: x = 1;	break;
				case 50: x = 2;	break;
				case 51: x = 3;	break;
				case 52: x = 4;	break;
				case 53: x = 5;	break;
				case 54: x = 6;	break;
				case 55: x = 7;	break;
				case 56: x = 8;	break;
				case 57: x = 9;	break;
			}
			if (digit == x) cnt++;

			printf("%d", x);
		}

	 printf(" %d\n", cnt);


	return 0;
}