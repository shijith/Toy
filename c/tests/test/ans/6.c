#include<stdio.h>
#include<string.h>

int compare(void *p1, void *p2)
{
	return strcmp(*(char **)p1, *(char **)p2);
}


main()
{
	int i;
	char *s[] = {"pqr", "abc", "def"};

	qsort(s, 3, sizeof(s[0]), compare);

	for(i = 0; i < 3; i++)
		printf("%s\n", s[i]);
}
