#ifndef server_h
#define server_h

#define PORT 9999
#define SA struct sockaddr
#define BACKLOG_QUEUE_LEN 5
#define CHILD_PID 0

void init_socket(struct sockaddr_in *servaddr, int);
int create_socket(void);
void listen_on_socket(int sockfd);
int accept_connection(struct sockaddr_in *servaddr, int listenfd);

#endif /* server_h */
