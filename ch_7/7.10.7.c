#include <stdio.h>

/* 
for_14 Скобки
Некоторые скобочные структуры правильные, другие — неправильные.
Ваша задача — определить правильная ли скобочная структура.

Вход	Выход
()		YES
(())()	YES
())		NO
)(		NO

Sample Input:
()
Sample Output:
YES

Test #2 input
(())()
Test #2 output
YES

Test #3 input
())
Test #3 output
NO

Test #4 input
)(
Test #4 output
NO
*/


int main()
{
	char c;
	int l, r;
	
	l = 0;
	r = 0;
	while((c = getchar()) != EOF) {
		if (c == '(' && r <= l) l++;
		if (c == ')') r++;
	}

	printf("%s\n", l == r ? "YES" : "NO");

	return 0;
}