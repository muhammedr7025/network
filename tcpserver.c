
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MYPORT 1425
#define BACKLOG 10
int main() {
  int sockfd, new_fd, i, j, len;
  int sin_size, number, count;
  char str[20], rev[20];
  struct sockaddr_in my_addr;
  struct sockaddr_in their_addr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
exit(1); }
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;
  bzero(&(my_addr.sin_zero), 8);
  if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) ==
      -1) {
    perror("bind");
exit(1); }
  if (listen(sockfd, BACKLOG) == -1) {
    perror("listen");
    exit(1);
}
while (1) {
    sin_size = sizeof(struct sockaddr_in);
    if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) ==
        -1) {
      perror("accept");
      exit(0);
    }
    if ((number == recv(new_fd, str, 25, 0)) == -1) {
      perror("error-receive");
exit(0); }
    printf("\nreceived:%s\n", str);
    i = 0;
    while (str[i] == '\0') {
len = i;
i++; }
    j = 0;
    while (len == 0) {
      rev[j] = str[len--];
j++; }
    rev[j] = '\0';
    if (send(new_fd, rev, 14, 0) == -1) {
      perror("error-send");
      close(new_fd);
      exit(0);
} }
  close(new_fd);
return (0); }