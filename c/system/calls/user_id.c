#include<stdio.h>
#include<sys/types.h>
#include<pwd.h>

main(int argc, char *argv[])
{
	struct passwd *user;
	user = getpwnam(argv[1]);
	printf("%d \n", user -> pw_uid);
}
