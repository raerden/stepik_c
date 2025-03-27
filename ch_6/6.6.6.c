#include <stdio.h>
/* 
Тип треугольника
Даны стороны треугольника - целые числа.

Напишите функцию triangle_len_type(a, b, c), где a, b, c - стороны треугольника.

Функция должна вернуть:

2 - если треугольник равносторонний (все стороны одинаковой длины)
1 - если треугольник равнобедренный (2 стороны одинаковые, третья другая)
0 - все стороны разные
-1 - такой треугольник не может быть.

Sample Input:
3 3 3

Sample Output:
2

*/

//Треугольник если сумма двух сторон больше третьей.
int is_triangle(int a, int b, int c) {
    if ((a + b > c) && (a + c > b) && (b + c > a))
        return 1;
    return 0;
}

//Равносторонний треугольник
int is_equal_all_sides(int a, int b, int c) {
    if (a == b && a == c && b == c)
        return 2;
    return 0;
}

//Равнобедренный треугольник
int is_equal_both_sides(int a, int b, int c) {
    if (a == b || a == c || b == c)
        return 1;
    return 0;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int res = -1;//Предполагаем невозможный треугольник
    if (is_triangle(a,b,c)) { //Это треугольник. Вопрос, какой?

        if (is_equal_all_sides(a,b,c)) // Равносторонний
            res = 2;
        else if (is_equal_both_sides(a,b,c)) //Равнобедренный
            res = 1;
        else
            res = 0;//В противном случае это разносторонний треугольник
    }
       
    printf("%d", res);

    return 0;
}

