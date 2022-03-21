#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void start()
{
    srand(time(0));

    const int matches = 100;

    int player = 1;

    for (int i = matches; i > 0;) {
        printf("----------------------------\n");
        printf("В куче осталось %d спичек!\n", i);

        if (player == 1) {
            if (makeStep(&i) == 0)
                player *= -1;
        } else {
            makeStepComputer(&i);
            player *= -1;
        }
    }

    if (player == 1)
        printf("Вы проиграли!\n");
    else
        printf("Поздравляю! Вы выиграли!\n");
}
