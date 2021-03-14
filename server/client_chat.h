#ifndef client_chat_h
#define client_chat_h

#define MAX 80
#define NEWLINE '\n'
#define EXIT_PHRASE_LEN 4
#define EXIT_PHRASE "exit"

int accept_connection(struct sockaddr_in *servaddr, int sockfd);
void chat_with_client(struct sockaddr_in *servaddr, int sockfd);
void echo_response(char *buffer);
void handle_msg(int connfd); 

#endif /* client_chat_h */
