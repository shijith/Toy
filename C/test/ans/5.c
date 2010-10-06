#include<stdio.h>

int compare(void *p1, void *p2)
{
	return *(int *)p1 - *(int *)p2;
}


main()
{
	int i;

	int a[] = {1, 10, 2, 5, 4, 3};

	qsort(a, 6, sizeof(a[0]), compare);

	for(i = 0; i < 6; i++)
		printf("%d\n", a[i]);
}
