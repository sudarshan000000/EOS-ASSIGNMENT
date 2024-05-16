/*
   1. Execute "wc" command from your program (using fork() + exec()). The command should read data from the ﬁle "in.txt" (instead of terminal) and output
   should be displayed on terminal.
 */
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


int main(){
	int ret,s,fd,err;
	printf("parent started");
	ret=fork();
	if(ret==0){
	 // output redirection
		fd = open("in.txt",O_RDONLY);
		close(0); // stdout
		dup(fd); // copy fd on stdout
		close(fd);

		err = execlp("wc","wc",NULL);
	if(err<0){
		perror("exec() failed");
		_exit(0);
	}
	}
	else
		waitpid(-1, &s, 0);
	printf("parent completed!\n");
	return 0;
}


