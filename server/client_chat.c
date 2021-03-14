#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "server_socket.h"
#include "client_chat.h"

// Function designed for chat between client and server.
void chat_with_client(struct sockaddr_in *servaddr, int listenfd)
{
	int pid;

	for (;;) {
		int connfd = accept_connection(servaddr, listenfd);

		pid = fork();

		if (pid == CHILD_PID) {
			close(listenfd);
			handle_msg(connfd);	
			printf("Child process is closing client descriptor: %d\n", connfd);
			close(connfd);
			exit(EXIT_SUCCESS);
		}
			
		printf("Parent process is closing client descriptor: %d\n", connfd);
		close(connfd);
	}
}

void handle_msg(int connfd) {
	char buff[MAX];
	// infinite loop for chat
	for (;;) {
		bzero(buff, MAX);

		// read the message from client and copy it in buffer
		int read_bytes = read(connfd, buff, sizeof(buff));

		if (read_bytes == 0) {
			break;
		}

		// print buffer which contains the client contents
		printf("From client: %s\n", buff);
		echo_response(buff);

		// and send that buffer to client
		write(connfd, buff, sizeof(buff));
	}
}

void echo_response(char *buffer) {
	strncat(buffer, "ECHO", 5);

	for (int i = 0; i <= strlen(buffer); i++) {
		if (buffer[i] == '\n') {
			buffer[i] = '_';
		}
	}
}
