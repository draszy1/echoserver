#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "server_chat.h"

void chat_with_server(int sockfd) {
    char buff[MAX];

    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");

        read_until_newline(buff);

        if (exit_request(buff)) {
            break;
        }

        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s\n", buff);
   }
}

void read_until_newline(char *buffer) {
    int i = 0;

    // copy server message in the buffer
    while ((buffer[i++] = getchar()) != NEWLINE)
        ;
}

int exit_request(char *buffer) {
    // if msg contains "Exit" then server exit and chat ended.
    if (strncmp(EXIT_PHRASE, buffer, EXIT_PHRASE_LEN) == 0) {
        printf("Exit phrase detected...ending\n");
        
        return 1;
    }
    
    return 0;
}
