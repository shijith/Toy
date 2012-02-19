#include<stdio.h>
#include<unistd.h>

main()
{
	if(fork()) {
		wait();
		printf("\nParent doing a clean up\n");
		sleep(2);
		execl("/usr/bin/clear", "clear", (char *)0);
	} else {
		printf("Child with a ls\n");
		execlp("ls", "ls", "-l", (char *)0);
	}
	
	return 0;
}	
