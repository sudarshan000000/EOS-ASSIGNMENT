#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

//step1: implement SIGINT handler
void sigint_handler(int sig){
printf("will not affect if KILL SIGINT on my shell");
}

int main(){
	int cmd[512], *ptr, *args[32];
	int ret,err,i,s;
	//step2: register signal handler
	signal(2,sigint_handler);//signal(SIGINT,sigint_handler);
	
	while(1){
		printf("myshell_cmd> ");
		gets(cmd);
		i=0;
		ptr=strtok(cmd, " ");
		args[i] = ptr;
		i++;

		//
		do{
			ptr = strtok(NULL, " ");
			args[i]= ptr;
			i++;
		}while(ptr != NULL);
		

	    if(strcmp(args[0],"exit")==0)
		        break;  //internal command 1 -->exit
		
		else if(strcmp(args[0],"cd")==0)
		         chdir(args[1]);  //internal command 2-->cd
    
	    else{
		ret = fork();
		if(ret==0){
			err =execvp(args[0],args);
			if(err <0){
				perror("bad comaand");
				_exit(1);
			}
		}
		else
			wait(&s);
	}
}
	printf("bye!\n");
	return 0;
}
