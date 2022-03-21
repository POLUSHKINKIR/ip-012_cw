#include <stdio.h>
#include <stdlib.h>

#include <libspichki/start.h>

int makeStep(int* i)
{
    int n;
    printf("Возьмите от 1 до 10 спичек:\n>");
    char str[10];
    fgets(str, 10, stdin);
    n = atoi(str);
    if (n >= 1 && n <= 10 && n <= *i) {
        printf("Вы взяли %d\n", n);
        *i -= n;
    } else {
        printf("Пожалуйста, введите правильное число спичек!\n");
        return -1;
    }
    return 0;
}

void makeStepComputer(int* i)
{
    int n;
    n = getRandom();
    if (n > *i)
        n = *i;
    printf("Компьютер взял: %d\n", n);
    *i -= n;
}   
