/*
From one parent create 5 child processes. Each child should run for 5 seconds
and print count along with its pid. Parent should wait for all child processes
to complete and clean all of them. Hint: use loop to fork() multiple child 
processes.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
int ret,i,s,count;
//1 parent is available here by this parent we will create multiple childs by terminate previous child
for(i=1; i<=5; i++){
	ret=fork();
	   if(ret ==0){
		for(count=1;count<=5; count++ ){
		printf("%d process process id(pid)=%d\n",count,getpid());
	   sleep(1);
	   }
     _exit(i);
	}
}
for(i=1;i<=5;i++0){

}
return 0;
}





