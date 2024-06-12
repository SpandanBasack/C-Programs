#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main()
{
    int sockfd;
    char buffer[BUFFER_SIZE]={0};
    char* message = "Hello from client";
    struct sockaddr_in address;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    connect(sockfd, (struct sockaddr*) &address, sizeof(address));
    send(sockfd, message, strlen(message), 0);
    printf("Hello message sent\n");
    int bytesRead = read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s\n", buffer);
    close(sockfd);
    return 0;
}