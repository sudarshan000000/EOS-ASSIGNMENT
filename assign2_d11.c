#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){
	int ret,arr1[2],arr2[2],n1,n2,num1,num2,r,res,s;

	ret=pipe(arr1);
	ret=pipe(arr2);
	ret=fork();
	if(ret==0){
	//child process
	close(arr1[0]);  //pipe1 -->
	close(arr2[1]);
	printf("enter num1:\n");
	scanf("%d",&num1);
	printf("enter num2: \n");
	scanf("%d",&num2);
	ret=write(arr1[1],&num1,sizeof(num1));
	ret=write(arr1[1],&num2,sizeof(num2));
	

	ret=read(arr2[0],&res, sizeof(res));
	printf("result: %d\n",res);

	close(arr2[0]);
	close(arr1[1]);
	}
    else{
 	close(arr1[1]);
	close(arr2[0]);
	ret=read(arr1[0],&n1,sizeof(n1));
	ret=read(arr1[0],&n2,sizeof(n2));
	r=n1+n2;
	ret=write(arr2[1],&r,sizeof(r));
	close(arr2[1]);
    close(arr1[0]);
	waitpid(-1,&s,0);
    }
	return 0;


}
