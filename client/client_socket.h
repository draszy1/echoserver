#ifndef client_h
#define client_h

#define PORT 8080
#define SA struct sockaddr
#define HOME "127.0.0.1"

int create_socket(void);
void init_socket(struct sockaddr_in *servaddr);
void connect_to_socket(struct sockaddr_in *servaddr, int sockfd);

#endif /* client_h */
