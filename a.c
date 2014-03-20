#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int a(int x)
{
	printf("%s input = %d\n", __func__, x);
	return (x + 100);
}
