/*
From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) 
and it (C) in turn create new child (D). 
All these processes should run concurrently for 5 seconds and cleaned up properly upon termination.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
int ret1,ret2,ret3,ret4,ret5,s;

ret1=fork();
  if(ret1==0)
  {
    ret2=fork();
    if(ret2==0)
	{
      ret3=fork();
	   if(ret3==0)
	      {
            ret4=fork();
			 if(ret4==0)
			 {
  				for(int l=0; l<=5;l++) 
      			{
       			 printf("child process D of step %d ",l);
      			 sleep(1);
	              }
				  _exit(0);
			 }
            for(int k=0; k<=5;k++) 
             {
             printf("child process c of step %d\n",k);
             sleep(1);
	         }
			 _exit(0);
	      }
         for(int j=0; j<=5;j++) 
          {
           printf("child process B of step %d\n ",j);
           sleep(1);
	      }
		  _exit(0);
	     }
   for(int i=0; i<=5;i++) 
      {
       printf("child process A of step %d\n ",i);
       sleep(1);// we use sleep to run all commands consequently due to use of sleep() process will go in waiting state by using software interrupt,
	   //          so cpu dispatcher will keep another process in running state so another process will run cosequently.
	  }
	  _exit(0);
   }
 //parent
 int s1,s2,s3,s4;
 waitpid(ret1,&s1,0);
 waitpid(ret2,&s2,0);
 waitpid(ret3,&s3,0);
 waitpid(ret4,&s4,0);
return 0;
}





