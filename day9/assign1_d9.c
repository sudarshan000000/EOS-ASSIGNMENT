#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

int ret,signal,pid;

printf("enter pid =\n");
scanf("%d",&pid);
printf("enter signal = \n");
scanf("%d",&signal);

ret=kill(pid,signal);
return 0;
} 




