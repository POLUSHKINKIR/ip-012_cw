#include <libspichki/start.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(suite_start, getRandom)
{
	for (int i = 0; i < 10; i++)
	{
		int n = getRandom();
		ASSERT_TRUE(n > 0 && n <= 10);
	}
}
