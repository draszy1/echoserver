#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "client_socket.h"

int create_socket() {
    // socket create and varification
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Socket successfully created..\n");
    }

    printf("Socket FD: %d\n", sockfd);
    return sockfd;
}

void init_socket(struct sockaddr_in *servaddr) {
    bzero(servaddr, sizeof(*servaddr));

    // assign IP, PORT
    servaddr->sin_family = AF_INET;
    servaddr->sin_addr.s_addr = inet_addr(HOME);
    servaddr->sin_port = htons(PORT);
}

void connect_to_socket(struct sockaddr_in *servaddr, int sockfd) {
    // connect the client socket to server socket
    printf("IP: %s\n", inet_ntoa(servaddr->sin_addr));
    printf("PORT: %d\n", htons(servaddr->sin_port));
    
    if (connect(sockfd, (SA*)servaddr, sizeof(*servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("connected to the server..\n");
    }
}
