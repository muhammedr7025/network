#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define PORT 1425
#define MAXDATASIZE 100
int main() {
  int sockfd, numbytes;
  char buf[MAXDATASIZE];
  struct sockaddr_in their_addr;
  their_addr.sin_family = AF_INET;
  their_addr.sin_port = htons(PORT);
  their_addr.sin_addr.s_addr = INADDR_ANY;
  bzero(&(their_addr.sin_zero), 8);
  while (1) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd, (struct sockaddr *)&their_addr,
                sizeof(struct sockaddr)) == -1) {
      perror("error_connect");
exit(1); }
    printf("\nEnter the string\n");
    scanf("%s", buf);
    if (send(sockfd, buf, 15, 0) == -1) {
      perror("error_send");
      close(sockfd);
      exit(0);
    }
    if ((numbytes == recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
      perror("error_receive");
exit(1); }
    printf("received %s\n", buf);
    close(sockfd);
  }
return (0); }