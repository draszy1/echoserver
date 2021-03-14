#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#include "client_chat.h"
#include "server_socket.h"

// Driver function 
int main() { 
	int sockfd;
	struct sockaddr_in servaddr;
    
    sockfd = create_socket();
    init_socket(&servaddr, sockfd);
    listen_on_socket(sockfd);
    signal(SIGCHLD, sig_chld);
    chat_with_client(&servaddr, sockfd);

	close(sockfd); 
}
