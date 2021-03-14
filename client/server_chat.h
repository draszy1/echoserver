#ifndef server_chat_h
#define server_chat_h

#define MAX 80
#define NEWLINE '\n'
#define EXIT_PHRASE_LEN 4
#define EXIT_PHRASE "exit"

void chat_with_server(int sockfd);
void read_until_newline(char *buffer);
int exit_request(char *buffer);

#endif /* server_chat_h */
