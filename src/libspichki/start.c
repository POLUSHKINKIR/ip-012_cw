#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <libspichki/start.h>
#include <libspichki/steps.h>

int getRandom()
{
    return rand() % 10 + 1;
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
