#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <libspichki/start.h>

void start()
{
    srand(time(0));

    const int matches = 100;

    printf("Hey from lib %d \n", matches);
}
