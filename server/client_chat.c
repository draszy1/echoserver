#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "server_socket.h"
#include "client_chat.h"

// Function designed for chat between client and server.
void chat_with_client(struct sockaddr_in *servaddr, int sockfd)
{
	for (;;) {
		int connfd = accept_connection(servaddr, sockfd);
		handle_msg(connfd);		
		printf("Closing client descriptor: %d\n", connfd);
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

int accept_connection(struct sockaddr_in *servaddr, int sockfd) {
	socklen_t len = sizeof(*servaddr);
	int connfd = accept(sockfd, (SA*)servaddr, &len);

	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	} else {
		printf("server acccept the client...\n");
		printf("Client's FD: %d\n", connfd);
		printf("IP: %s\n", inet_ntoa(servaddr->sin_addr));
		printf("PORT: %d\n", htons(servaddr->sin_port));
	}

	return connfd;
}
