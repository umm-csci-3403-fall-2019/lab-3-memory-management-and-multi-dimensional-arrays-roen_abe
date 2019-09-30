#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "mergesort.h"

bool needsSorting(int rangeSize)
{
	return rangeSize >= 2;
}
