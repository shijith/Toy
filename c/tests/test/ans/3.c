#include <stdio.h>
#include <malloc.h>

main()
{
	char *s[5];
	int i;

	for(i = 0; i < 5; i++) {
		s[i] = (char *)malloc(20);
		scanf("%s", s[i]);
	}

	for(i = 0; i < 5; i++)
		printf("%d - > %s\n", (i+1), s[i]);
}
