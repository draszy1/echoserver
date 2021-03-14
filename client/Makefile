CC = gcc
CFLAGS  = -g -Wall
TARGET = client
OBJS = server_chat.o client_socket.o

all: $(TARGET)

client_socket.o:
	$(CC) -c client_socket.c
	
server_chat.o:
	$(CC) -c server_chat.c

$(TARGET): $(TARGET).o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(TARGET).o

clean:
	$(RM) $(TARGET) $(TARGET).o $(OBJS)
