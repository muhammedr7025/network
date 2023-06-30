
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
int main() {
  char buf[100];
  int i = 1, k;
  int sock_desc;
  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock_desc == -1) {
    printf("ERROR IN CREATING SOCKET");
exit(1); }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = 3000;
  while (1) {
    sprintf(buf, "DATA PKT %d", i);
    k = sendto(sock_desc, buf, 100, 0, (struct sockaddr *)&server,
               sizeof(server));
    if (k == -1) {
      printf("\nERROR IN SENDING DATA PACKETS");
exit(1); }
    sleep(1);
    if (i == 20) {
      strcpy(buf, "END");
      k = sendto(sock_desc, buf, 100, 0, (struct sockaddr *)&server,sizeof(server));
break; }
i++; }
  close(sock_desc);
  exit(0);
  return (0);
}