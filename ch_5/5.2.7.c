#include <stdio.h>
/*
из большой в маленькую
Дана большая латинская буква. Напечатайте соответствующую ей маленькую латинскую букву.

Sample Input:
A

Sample Output:
a

*/

int main()
{
    char ch;

    scanf("%c", &ch);

    ch = ch + ('a'-'A'); // Насколько далеко отстоит a(97) от A(65)
    
    printf("%c\n", ch);

    return 0;
}