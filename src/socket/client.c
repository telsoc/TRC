// client.c
// A file for testing purposes. Provides a simple socket client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "client.h"
#include "server.h"

void start_client() {
    int status;
    struct addrinfo hints;
    struct addrinfo *clientinfo;

    // Clearing and setting up hints
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;        // Works for IPv4 & 6
    hints.ai_socktype = SOCK_STREAM;    // TCP

    // Read into servinfo
    status = getaddrinfo("localhost", PORT_NUM, &hints, &clientinfo);

    if (status < 0) {                  // TODO: turn error checking into a func
        perror("ERROR: failed to retrieve server info");
        exit(1);
    }

    printf("LOG: retrieved addrinfo\n");

    // TODO: walk the list of values of the linked list - connection
    // assumes the first one is the correct one to use

    // Set up the socket
    int sock_fd = socket(clientinfo->ai_family, clientinfo->ai_socktype, clientinfo->ai_protocol);

    if (sock_fd < 0) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    printf("LOG: created socket\n");

    // Connect the socket to the server
    int err = connect(sock_fd, clientinfo->ai_addr, clientinfo->ai_addrlen);

    if (err < 0) {
        perror("ERROR: Failed to connect socket");
        exit(1);
    }

    printf("LOG: socket connected to server\n");

    // Freeing info
    freeaddrinfo(clientinfo);
}
