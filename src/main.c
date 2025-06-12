#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "main.h"


int main() {
  /* Placeholder variable. start_connection
   * willbe returning some success/error value.
   */
  int x = start_server();
  return(x);
}


int start_server() {
  int sock_fd, conn_fd, len, err;
  struct sockaddr_in serv_addr, cli;

  if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "ERROR: failed to create socket!\n");
    exit(0);
  } printf("Socket created...\n");

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(PORT_NUM);

  if((err = bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) != 0) {
    fprintf(stderr, "ERROR: failed to bind socket: %s!\n", strerror(err));
    exit(0);
  } printf("Socket bound...\n");

  if((err = listen(sock_fd, 5)) != 0) {
    fprintf(stderr, "ERROR: listening failed: %s!\n", strerror(err));
    exit(0);
  } printf("Server listening...\n");
  len = sizeof(cli);

  conn_fd = accept(sock_fd, (struct sockaddr*)&cli, &len);
  if(conn_fd < 0) {
    fprintf(stderr, "ERROR: server accepting failed: %s!\n", strerror(err));
    exit(0);
  } printf("Server accepted the client...\n");
  
  return(0);
}
