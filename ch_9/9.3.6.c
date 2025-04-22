#include <stdio.h>
/*
Судоку

Дано решенное судоку

Напечатать YES, если решение верное, иначе напечатать NO.

Судоку решено верно, если в каждой строке, 
столбце и квадрате 3х3 числа от 1 до 9 встречаются ровно один раз.
Test #1 input
6 4 2 1 8 3 5 9 7
3 1 9 5 2 7 6 8 4
5 8 7 9 4 6 3 2 1
8 9 4 2 6 5 7 1 3
7 3 6 8 1 9 2 4 5
2 5 1 7 3 4 9 6 8
4 6 5 3 9 1 8 7 2
1 7 8 6 5 2 4 3 9
9 2 3 4 7 8 1 5 6
Test #1 output
YES


Test #3 input
1 2 3 4 5 6 7 8 9
9 1 2 3 4 5 6 7 8
8 9 1 2 3 4 5 6 7
7 8 9 1 2 3 4 5 6
6 7 8 9 1 2 3 4 5
5 6 7 8 9 1 2 3 4
4 5 6 7 8 9 1 2 3
3 4 5 6 7 8 9 1 2
2 3 4 5 6 7 8 9 1
Test #3 output
NO

*/

#define N 9


void printsudoku(int a[N][N]) {
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            if (j > 0) printf(" ");
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

void readsudoku(int a[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
}

//проверяет чтобы в массиве a[N] цифры 1-9 не повторялись более одного раза
int check_row9(int a[N]) {
    int m[10] = {0};// 1 2
    for (int i = 0; i < N; i++) {

        if (a[i] < 1 || a[i] > 9) 
            return 0;

        if (m[a[i]] == 0)
            m[a[i]] = 1;
        else
            return 0;

    }
    return 1;
}

int check_rows(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        if (check_row9(a[i]) == 0)
            return 0;
    }
    return 1;
}

int check_cols(int a[N][N]) {
    int m[N];
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            m[j] = a[j][i];
        }
        if (check_row9(m) == 0)
            return 0;
    }
    return 1;
}

int check_square3(int sx, int sy, int a[N][N]) {
    int m[N];
    int c = 0;
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            m[c] = a[i+sx][j+sy];
            //printf("[%d] ",m[c]);
            c++;
        }
    }
    if (check_row9(m) == 0)
        return 0;
    return 1;
}

int check_squares(int a[N][N]) {
    for (int sx = 0; sx < 9; sx = sx + 3) {
        for(int sy = 0; sy < 9; sy = sy + 3) {
            //printf("%d %d,",sx, sy);
            //printf("-%d\n",check_square3(sx, sy, a));
            if (check_square3(sx, sy, a) == 0)
                return 0;
        }
        //printf("\n");
        
    }
    return 1;
}

int main()
{
    int a[N][N];
    readsudoku(a);
    

    //a[3][6] = 1;
    //printsudoku(a);



    //printf("\n%d\n", check_row9((a[0])));
    //printf("\n%d\n", check_rows(a));
    //printf("\n%d\n", check_cols(a));
    //printf("\n%d\n", check_squares(a));

    if (check_rows(a) && check_cols(a) && check_squares(a))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

