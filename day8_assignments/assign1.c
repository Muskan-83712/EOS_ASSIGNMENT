/*1. From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all child processes
to complete and clean all of them. Hint: use loop to fork() multiple child processes*/


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int ret1, ret2, ret3, ret4, ret5,i,s;
	ret1 = fork();
	if(ret1 == 0){
		for(i=1; i<=5; i++){
			printf("child1 pid=%d\n", getpid());
			sleep(1);
		}
		_exit(0);
	}

	ret2 = fork();
	if(ret2 == 0){
		for(i=1; i<=5; i++){
			printf("child2 pid=%d\n", getpid());
			sleep(1);
		}
		_exit(0);
	}

	ret3 = fork();
	if(ret3 == 0){
		for(i=1; i<=5; i++){
			printf("child3 pid=%d\n", getpid());
			sleep(1);
		}
		_exit(0);
	}

	ret4 = fork();
	if(ret4 == 0){
		for(i=1; i<=5; i++){
			printf("child4 pid=%d\n", getpid());
			sleep(1);
		}
		_exit(0);
	}

	ret5 = fork();
	if(ret5 == 0){
		for(i=1; i<=5; i++){
			printf("child5 pid=%d\n", getpid());
			sleep(1);
		}
		_exit(0);
	}

		for(i=1;i<=5;i++){
			wait(&s);
		}

	return 0;
}

