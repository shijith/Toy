#include<stdio.h>
#include<unistd.h>
main(){
	int fd;
	char buff[] = "This is file content";

	fd = creat("out", 0644);

	close(1);
	dup(fd);

	printf("%s",buff);

	close(fd);
}
	
