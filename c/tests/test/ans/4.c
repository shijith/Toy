#include <stdio.h>
#include <malloc.h>

main()
{
	char **s;
	int i;

	s = (char **)malloc(5 * sizeof(char *));

	for(i = 0; i < 5; i++) {
		s[i] = (char *)malloc(20);
		scanf("%s", s[i]);
	}

	for(i = 0; i < 5; i++)
		printf("%d - > %s\n", (i+1), s[i]);
	
}
