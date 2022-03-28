#define CTEST_MAIN

#include <ctest.h>

#include <time.h>
#include <stdlib.h>

int main(int argc, const char** argv)
{
	srand(time(0));
    return ctest_main(argc, argv);
}
