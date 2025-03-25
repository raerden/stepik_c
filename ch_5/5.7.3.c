#include <stdio.h>
/* struct_colors Цвета RGB

Требуется написать функции:

// считать RGB-формат с консоли
Color getColor();
// перевод из RGB-формата в число
unsigned long long convertToHTML(Color);
// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long);
// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue:
// 255 128 222
// Печатать только числа через пробел и \n в конце!!!
void printRGB(Color);
// печать цвета в HTML-формате и \n в конце.
// Примеры: FFA902 0AA3FF
void printHTML(Color);

Sample Input:
255 128 16

Sample Output:
255 128 16
16744464
FF8010
255 128 16
*/

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

// считать RGB-формат с консоли
Color getColor();

// перевод из RGB-формата в число
unsigned long long convertToHTML(Color);

// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long);

// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue:
// 255 128 222
// Печатать только числа через пробел и \n в конце!!!
void printRGB(Color);

// печать цвета в HTML-формате и \n в конце.
// Примеры: FFA902 0AA3FF
void printHTML(Color);

int main(){
    Color z, z2;
    unsigned long long html;

    z = getColor();
    printRGB(z);

    html = convertToHTML(z);
    printf("%llu\n", html);
    printHTML(z);

    z2 = convertToRGB(html);
    printRGB(z2);

    return 0;
}

// считать RGB-формат с консоли
Color getColor() {
    Color res;
    scanf("%hhu%hhu%hhu", &res.red, &res.green, &res.blue);
    return res;
}

//255 128 16
void printRGB(Color z) {
    printf("%d %d %d\n", z.red, z.green, z.blue);
}

//FF8010
void printHTML(Color z) {
    printf("%02X%02X%02X\n", z.red, z.green, z.blue);
}

// перевод из RGB-формата в число
//255 128 16
//16744464
unsigned long long convertToHTML(Color z) {
    return z.red * 256 * 256 + z.green * 256 + z.blue;
}

// преобразование числа цвета в RGB-формат
//16744464
//255 128 16
Color convertToRGB(unsigned long long rgb) {
    Color res;

    res.blue = rgb % 256;
    res.green = (rgb / 256) % 256;
    res.red = (rgb / 256 / 256) % 256;

    return res;
}