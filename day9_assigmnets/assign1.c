#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

int main(){
	int pid,signum,ret;
	printf("kill process taking id and sig number from user\n");
	printf("enter the pid,signum: ");
	scanf("%d %d",&pid,&signum);
	ret = kill(pid,signum);

	return 0;
}


