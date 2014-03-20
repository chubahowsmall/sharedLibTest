#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "header.h"

#define LIB_PATH "/home/ytlee/test-shared-lib/libtest.so"


int main(int argc, char **argv)
{
	int retA, retB;

	void *lib_handle = NULL;
	int (*a)(int);
	int (*b)(int);
	char *error = NULL;


	printf("%s: using dynamic loading...\n", __func__);

	lib_handle = dlopen(LIB_PATH, RTLD_LAZY);
	if(!lib_handle)
	{
		printf("%s: loading %d fail\n", __func__, LIB_PATH);
		return (1);
	}

	a = dlsym(lib_handle, "a");
	if((error = dlerror()) != NULL)
	{
		printf("%s: lookup for %s() fail\n", __func__, "a");
		goto err;
	}

	b = dlsym(lib_handle, "b");
	if((error = dlerror()) != NULL)
	{
		printf("%s: lookup for %s() fail\n", __func__, "b");
		goto err;
	}

	printf("%s calling a()\n", __func__);
	retA = (*a)(100);
	printf("%s return from a()=%d\n", __func__, retA);

	printf("%s calling b()\n", __func__);
	retB = (*b)(200);
	printf("%s return from b()=%d\n", __func__, retB);


err:
	
	dlclose(lib_handle);
	
	return 0;
}
