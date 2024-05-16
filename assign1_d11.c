/*
   3. Find the size of pipe buﬀer in your system.
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
char ch ='A';
int ret, arr[2];

void sigint_handler(int sig){
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}
int main(){
	ret = pipe(arr);
	if(ret<0){
		perror("pipe() failed");
		_exit(0);
	}
	sigaction(SIGINT, &ch, NULL);
	int count=0;
	while(1){
		write(arr[1],&ch, 1);
		count++;
		printf("bytes written: %d\n",count);
	}
	return 0;
}
