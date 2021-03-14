#include <arpa/inet.h>
#include <unistd.h>

#include "client_chat.h"
#include "server_socket.h"

// Driver function 
int main() { 
	int sockfd;
	struct sockaddr_in servaddr;
    
    sockfd = create_socket();
    init_socket(&servaddr, sockfd);
    listen_on_socket(sockfd);
    chat_with_client(&servaddr, sockfd);

	close(sockfd); 
}
