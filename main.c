#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char **argv)
{
	int retA, retB;

	printf("%s calling a()\n", __func__);
	retA = a(100);
	printf("%s return from a()=%d\n", __func__, retA);

	printf("%s calling b()\n", __func__);
	retA = b(200);
	printf("%s return from b()=%d\n", __func__, retB);


}
