#include <stdio.h>
#include <assert.h>
/*
Для кодирования карт используют обозначения:

Масть (suit):
c - clubs, трефы, ♣
s - spades, пики, ♠️
h - hearts, червы, ♥️
d - diamond, бубны, ♦️
Достоинство (rank):
'2', '3', '4', '5', '6', '7', '8', '9' - от 2 до 9
'T' (ten - десять),
'J' (валет),
'Q' (дама),
'K' (король),
'A' (туз).
В этой нотации дама пик и король бубен записываются как QsKd.

struct_card Пиковая дама
Реализуйте функцию, которая ищет пиковую даму в переданной руке.

Sample Input:
QsAh9d

Sample Output:
QsAh9d
1
*/

#define DECKSIZE 52

struct Card {
    char rank;    // достоинство
    char suit;    // масть
};

int valid_card(struct Card * card)
{
    char * const suit = "cshd";        // в строках в конце тоже есть "фальшивый" символ '\0'
    char * const rank = "23456789TJQKA";
    int i;
    for (i = 0; suit[i] != '\0'; i++)
        if (suit[i] == card->suit)      // масть такая существует
            break;
    if (suit[i] == '\0')                // в card->suit была неправильная масть
        return 0;


    for (i = 0; rank[i] != '\0'; i++)
        if (rank[i] == card->rank)      // достоинство такое существует
            return 1;                   // масть и достоинство существуют, карта правильная


    return 0;                           // в card->rank было неправильное достоинство
}

void print_cards(struct Card * hand) {
    // напечатаем карты до фальшивой, фальшивую не печатаем:
    struct Card * p;    // указатель на одну карту
    for(p = hand; p->rank != 0; p++)
        printf("%c%c", p->rank, p->suit);
    printf("\n");
}

void read_cards(struct Card * hand) {
    struct Card * p;    // указатель на одну карту
    for(p = hand; (p - hand) < DECKSIZE && 2 == scanf("%c%c", &p->rank, &p->suit); p++)
        if (!valid_card(p))
                break;
    // в конец положим фальшивую карту
    p->rank = p->suit = 0;
}

int check(struct Card * hand) {
    struct Card * p;
    for (p = hand; p->rank != 0; p++)
        if (p->rank == 'Q' && p->suit == 's')
            return 1;
    return 0;
}

int main()
{
    struct Card hand[DECKSIZE+1];
    
    read_cards(hand);

    struct Card hand1 [] = {{'Q', 's'}, {'A','h'}, {'9', 'd'}, {0, 0}};
    struct Card hand2 [] = {{'2', 's'}, {'A','h'}, {0, 0}};
    assert(1 == check(hand1));
    assert(0 == check(hand2));

    print_cards(hand);
    printf("%d\n", check(hand));

    
    return 0;
}