// #include <stdio.h>
// #include <netinet/in.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>
// #include <unistd.h>

// #define PORT 8000
// #define BUFFERSIZE 1024

// int main()
// {
//     int sockfd;
//     struct sockaddr_in address, client_address;
//     socklen_t client_len = sizeof(client_address);
//     int addrlen = sizeof(address);
//     char buffer[BUFFERSIZE] = {0};
//     if(sockfd = socket(AF_INET, SOCK_DGRAM, 0)==-1)
//     {
//         perror("Error in socket creation\n");
//         exit(1);
//     }
//     address.sin_family = AF_INET;
//     address.sin_port = htons(PORT);
//     address.sin_addr.s_addr = INADDR_ANY; 
//     bind(sockfd, (struct sockaddr*) &address, addrlen);
//     int numbytes = recvfrom(sockfd, buffer, BUFFERSIZE, 0, (struct sockaddr *) &client_address, &client_len);
//     buffer[numbytes] = '\0';
//     printf("Recieved data:\n");
//     printf("%s\n",buffer);
//     sendto(sockfd, "ABC", 3, 0, (struct sockaddr*) &client_address, client_len);
//     printf("Message sent.\n");
//     close(sockfd);
// }

#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8000
#define BUFFERSIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in address, client_address;
    socklen_t client_len = sizeof(client_address);
    int addrlen = sizeof(address);
    char buffer[BUFFERSIZE] = {0};

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Error in socket creation\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY; 

    if (bind(sockfd, (struct sockaddr*)&address, addrlen) == -1) {
        perror("Bind failed\n");
        exit(1);
    }

    int numbytes = recvfrom(sockfd, buffer, BUFFERSIZE, 0, (struct sockaddr*)&client_address, &client_len);
    buffer[numbytes] = '\0';
    printf("Received data:\n");
    printf("%s\n", buffer);

    if (sendto(sockfd, "ABC", 3, 0, (struct sockaddr*)&client_address, client_len) == -1) {
        perror("Sendto failed\n");
        exit(1);
    }
    printf("Message sent.\n");

    close(sockfd);
    return 0;
}    