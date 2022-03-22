#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <libspichki/const.h>
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

    int player = PLAYER_ONE;

    for (int i = matches; i > 0;) {
        printf("----------------------------\n");
        printf("В куче осталось %d спичек!\n", i);

        if (player == PLAYER_ONE) {
            int code = makeStep(&i);
            if (code == EXITCODE_FORCED)
                return;
            if (code == EXITCODE_SUCCESS)
                player = PLAYER_TWO;
        } else {
            makeStepComputer(&i);
            player = PLAYER_ONE;
        }
    }

    if (player == PLAYER_ONE)
        printf("Вы проиграли!\n");
    else
        printf("Поздравляю! Вы выиграли!\n");
}
