/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv) {

  struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(6768);
  //ip of the mediator node which will forward the request to destination node 
  servaddr.sin_addr.s_addr = inet_addr("10.92.80.59");

  while(1) {

    char message[161];
    fgets(message, 161, stdin);

    /* Replacing '\n' with '\0' */
    char *tmp = strchr(message, '\n');
    if (tmp) *tmp = '\0';

    connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    send(sock, message, strlen(message), 0);
    close(sock);
  }
}

