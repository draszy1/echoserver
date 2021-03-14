CC = gcc
CFLAGS  = -g -Wall
TARGET = server
OBJS = client_chat.o server_socket.o

all: $(TARGET)

server_socket.o:
	$(CC) -c server_socket.c
	
client_chat.o:
	$(CC) -c client_chat.c

$(TARGET): $(TARGET).o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(TARGET).o

clean:
	$(RM) $(TARGET) $(TARGET).o $(OBJS)
