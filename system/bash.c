#include<stdio.h>
#include<stdlib.h>

main()
{
	int len, i = 0;
	char *cmd[5], c;
	while(1) {
		len = 0;
		i = 0;
		cmd[len] = (char *)malloc(10);
		printf("guest@emptycup:~$ ");
       		fflush(stdout);	

		while((c = getchar()) != '\n') {
			if(c == 32) {
				*(cmd[len] + i++) = '\0';
				i = 0;
				cmd[++len] = (char *)malloc(10);
			} else {
				*(cmd[len] + i++) = c;
			}
		}

		cmd[++len] = 0;
		if(fork() == 0)
			execvp(cmd[0], cmd, 0);
		wait();
	}
}
