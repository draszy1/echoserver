#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

#include "client_socket.h"
#include "server_chat.h"

int main() { 
	int sockfd;
	struct sockaddr_in servaddr;

    sockfd = create_socket();
    init_socket(&servaddr);
    connect_to_socket(&servaddr, sockfd);
    chat_with_server(sockfd);

	// close the socket
	printf("Closing connection with server...\n");
	close(sockfd); 
}
