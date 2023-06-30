#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  socklen_t len;
  char buf[100];
  int sock_desc;
  int k;
  struct sockaddr_in client;
  memset(&client, 0, sizeof(client));
  sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock_desc == -1) {
    printf("ERROR IN CREATING SOCKET");
exit(1); }
  client.sin_family = AF_INET;
  client.sin_addr.s_addr = INADDR_ANY;
  client.sin_port = 3000;
  k = bind(sock_desc, (struct sockaddr *)&client, sizeof(client));
  if (k == -1) {
    printf("\nERROR IN BINDING SOCKET");
exit(1); }
  while (1) {
    k = recvfrom(sock_desc, buf, 100, 0, (struct sockaddr *)&client, &len);
    if ((strcmp(buf, "end") == 0)) {
      printf("\nEND OF TRANSMISSION FROM SERVER");
break; }
    printf("\n%s\n", buf);
  }
  close(sock_desc);
  exit(0);
  return (0);
}