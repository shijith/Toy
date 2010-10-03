#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

main(int argc,char* argv[])
{
	int fr, fw, n, k;
	char buff[100];
	
	if((fr = open(argv[1], O_RDONLY)) == -1){
		printf("%s :file not found\n", argv[1]);
		exit(0);
	}
	
	if((fw = open(argv[2], O_WRONLY))== -1)
		fw = creat(argv[2], 0644);
	
	while(n = read(fr, buff, 10))
		write(fw, buff, n);
	
	close(fr);
	close(fw);	
}	
