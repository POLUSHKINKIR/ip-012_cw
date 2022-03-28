#include <libspichki/steps.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(suite_start, makeStepComputer)
{
	int n = 100;
	makeStepComputer(&n);
	ASSERT_TRUE(n < 100 && n >= 90);
}
