#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv) {

  struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);
 char messageToForward[100];
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(6768);

  bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(sock, 5);

  while(1) {

    int pid;
   pid=fork();


    if(pid==0){
      printf("In child Process serving as Server for one of the client\n");
    int clisock = accept(sock, (struct sockaddr *) NULL, NULL);

    if (clisock >= 0) {
      int messageLength = 160;
      char message[messageLength+1];
      int in, index = 0, limit = messageLength;

      while ((in = recv(clisock, &message[index], messageLength, 0)) > 0) {
        index += in;
        limit -= in;
      }

      strcpy(messageToForward,message);
      printf("%s\n", message);
    }

    close(clisock);
  }

    else if(pid>0){

        struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(6767);
  
  //ip of destination node
  servaddr.sin_addr.s_addr = inet_addr("10.92.80.58");
 printf("In Parent process acting as client  to whom request will be forwarded\n");
  while(1) {

    //char message[161];
    //fgets(message, 161, stdin);

    /* Replacing '\n' with '\0' */
     char *tmp = strchr(messageToForward, '\n');
     if (tmp) *tmp = '\0';

    connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    send(sock, messageToForward, strlen(messageToForward), 0);
    close(sock);
  }
 }
}

}

