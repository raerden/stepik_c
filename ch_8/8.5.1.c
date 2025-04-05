#include <stdio.h>
#include <stdlib.h>
/*
Четные и нечетные
Дано натуральное число 
n<1000, далее n целых чисел.

Напечатать сначала четные числа. На следующей строке напечатать нечетные числа.

Тестовые данные
Sample Input:
5
2 17 18 -4 9

Sample Output:
2 18 -4
17 9

*/

int main(){
    
    int n, i;
    
    scanf("%d", &n);
    int * m = malloc(n * sizeof(int));

    for (i=0; i < n; i++)
    	scanf("%d", &m[i]);

	for (i=0; i < n; i++) 
        if (m[i] % 2 == 0)
    	    printf("%d ", m[i]); 
    printf("\n");

	for (i=0; i < n; i++) 
        if (m[i] % 2 != 0)
    	    printf("%d ", m[i]); 
    printf("\n");

    free(m);
    return 0;

}