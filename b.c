#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int b(int x)
{
	printf("%s: input = %d\n", __func__, x);
	return (x + 200);
}
