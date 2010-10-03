#include<unistd.h>
main(int argc,char* argv[]){
	execlp("id", "id", "-u", argv[1], NULL);
}
