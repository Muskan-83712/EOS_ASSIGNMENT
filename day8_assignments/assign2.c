/*2. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int retB,retC,retD,s1,s2,s3,i;
	retB = fork();
	if(retB == 0){
		retC = fork();
		if(retC == 0){
			retD = fork();
			if(retD == 0){
				for(i=1;i<=5;i++){
					printf("the pid and ppid of child D is pid:%d ppid:%d\n",getpid(),getppid());
					sleep(1);
				}
				_exit(0);
			}
		for(i=1;i<=5;i++){
			printf("the pid and ppid of child C is pid:%dppid:%d\n",getpid(),getppid());
			sleep(1);
		}
		waitpid(retD,&s3,0);
		_exit(0);

		}
	for(i=1;i<=5;i++){
		printf("the pid and ppid of child B is pid:%dppid:%d\n",getpid(),getppid());
        sleep(1);
     }
	 waitpid(retC,&s2,0);
	 _exit(0);

	}
	for(i=1;i<=5;i++){
		printf("the pid and ppid of parentA is pid:%dppid:%d\n",getpid(),getppid());
		sleep(1);
	}
	waitpid(retB,&s1,0);
	
	return 0;
}
