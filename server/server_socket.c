#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "server_socket.h"

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Socket successfully created..\n");
    }
    
    return sockfd;
}

void init_socket(struct sockaddr_in *servaddr, int sockfd) {
    bzero(servaddr, sizeof(*servaddr));
    // assign IP, PORT
    servaddr->sin_family = AF_INET;
    servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr->sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)servaddr, sizeof(*servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    } else {
        printf("Socket successfully binded..\n");
    }
}

void listen_on_socket(int sockfd) {
    if ((listen(sockfd, BACKLOG_QUEUE_LEN)) != 0) {
        printf("Listen failed...\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Server listening..\n");
    }
}


