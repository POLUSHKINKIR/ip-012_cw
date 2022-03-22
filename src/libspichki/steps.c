#include <stdio.h>
#include <stdlib.h>

#include <libspichki/const.h>
#include <libspichki/start.h>

int makeStep(int* i)
{
    int n;
    printf("Возьмите от 1 до 10 спичек:\n>");
    char str[128];
    fgets(str, 128, stdin);
    if (str[0] == 'q')
        return EXITCODE_FORCED;
    n = atoi(str);
    if (n >= 1 && n <= 10 && n <= *i) {
        printf("Вы взяли %d\n", n);
        *i -= n;
    } else {
        printf("Пожалуйста, введите правильное число спичек!\n");
        return EXITCODE_FAILURE;
    }
    return EXITCODE_SUCCESS;
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
