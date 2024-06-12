#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main()
{
    int sockfd;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in saddress;
    socklen_t addr_len = sizeof(saddress);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    saddress.sin_port = htons(PORT);
    saddress.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &saddress.sin_addr);
    sendto(sockfd, "Basack", 6, 0, (struct sockaddr*) &saddress, addr_len);
    int numbytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    buffer[numbytes] = '\0';
    printf("Recieved data:\n");
    printf("%s\n",buffer);
    close(sockfd);
}