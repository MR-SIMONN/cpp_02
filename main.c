#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *i = malloc(5);
	*i = 5;
 	printf("%d\n", *i);
	printf("%p\n", i);
	free(i);
	printf("%d\n", *i);
	printf("%p\n", i);
	free(i);
}