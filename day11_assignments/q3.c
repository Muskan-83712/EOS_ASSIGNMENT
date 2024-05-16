/*3. Find the size of pipe buﬀer in your system.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>


int ret;
int arr[2];

void sigint_handler(int sig){
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}


int main(){
	char ch = 'A';
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
	}
	ret = pipe(arr);
	int count = 0;
	while(1){
		write(arr[1],&ch,sizeof(ch));
		count++;
		printf("bytes written : %d\n",count);
	}
	return 0;
}
