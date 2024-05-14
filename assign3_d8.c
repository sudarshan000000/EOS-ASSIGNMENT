#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){

	int i=1,ret,s;

	printf("program for check max process capacity");
	while(1){
		ret=fork();
		if(ret==0){
			printf("child pid(process ID) = %d\n",getpid());
			_exit(0);
		}
		else if(ret ==-1)
		{
			printf("process failed");
			break;
		}
		else
		{
			i++;
			printf("count of child process=%d\n",i);
		}
	}
	for(int j=0;j<i;j++)
		wait(&s);
	return 0;
}


