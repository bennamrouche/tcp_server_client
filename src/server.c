
# include <stdio.h>
# include <netdb.h>
# include <netinet/in.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/types.h>
# include "color.h"
# include <unistd.h>
# define MAX 80
#define PORT 2022
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int connfd)
{
	char buff[MAX];
	int n;
	// infinite loop for chat
	for (;;)
	{
		bzero(buff, MAX);

		// read the message from client and copy it in buffer
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		print_mgs_B("From client:");
		print_mgs("\t");
		print_mgs(buff);
		print_mgs("Enter The Message :> ");
		bzero(buff, MAX);
		n = 0;
		// copy server message in the buffer
		while ((buff[n++] = getchar()) != '\n')
			;

		// and send that buffer to client
		write(connfd, buff, sizeof(buff));

		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("exit", buff, 4) == 0)
		{
			print_error("Server Exit...\n");
			break;
		}
	}
}

// Driver function
int main()
{
	unsigned int len ;
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		print_error("socket creation failed...\n");
		exit(0);
	}
	else
		print_hint_B("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
	{
		print_error("socket bind failed...\n");
		exit(0);
	}
	else
		print_hint_B("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 2)) != 0)
	{
		print_error("Listen failed...\n");
		exit(0);
	}
	else
		print_hint_B("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA *)&cli, &len);
	if (connfd < 0)
	{
		print_error("server accept failed...\n");
		exit(0);
	}
	else
		print_hint_B("server accept the client...\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}
