#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main(int argc, char **argv) {

  struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(6767);

  bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(sock, 5);

  while(1) {
    int clisock = accept(sock, (struct sockaddr *) NULL, NULL);

    if (clisock >= 0) {
      int messageLength = 160;
      char message[messageLength+1];
      int in, index = 0, limit = messageLength;

      while ((in = recv(clisock, &message[index], messageLength, 0)) > 0) {
        index += in;
        limit -= in;
      }

      printf("%s\n", message);
    }

    close(clisock);
  }
}

