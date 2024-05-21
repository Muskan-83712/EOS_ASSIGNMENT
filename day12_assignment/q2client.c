#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stdlib.h>


#define SOCK_PATH "/tmp/desd_sock"

int main(){
	int cli_fd,ret,num1,num2,res;
	struct sockaddr_un serv_addr;

	cli_fd = socket(AF_UNIX, SOCK_STREAM ,0);
	if(cli_fd < 0){
		perror("socket() failed");
		_exit(1);

	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, SOCK_PATH);

	ret = connect(cli_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret < 0){

		perror("connect() failed");
		_exit(2);
	}

	printf("client");
	printf("enter two numbers : ");
	scanf("%d%d",&num1,&num2);

	write(cli_fd,&num1,sizeof(num1));
	write(cli_fd,&num2,sizeof(num2));
	printf("numbers sent succesfully !!!\n");
	
	read(cli_fd,&res,sizeof(res));
	printf("result : %d\n",res);


	close(cli_fd);
	return 0;
}
