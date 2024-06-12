#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* message = "Hello from server";

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))==0)
    {
        perror("Socket generation failed");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if(bind(sockfd, (struct sockaddr *) &address, addrlen)<0){
        perror("bind failed");
        exit(1);
    }
    listen(sockfd, 3);
    new_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
    send(new_socket, message, strlen(message), 0);
    printf("Server message sent\n");
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Info recieved: %s\n", buffer);
    close(sockfd);
    close(new_socket);
    return 0;
}