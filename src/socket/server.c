// server.c
// Provides implementations for server.h. These are all socket server related functions.

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "server.h"

void start_server() {
    int status;
    struct addrinfo hints;
    struct arrdinfo *servinfo;

    // Clearing and setting up hints
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;        // Works for IPv4 & 6
    hints.ai_socktype = SOCK_STREAM;    // TCP
    hints.ai_flags = AI_PASSIVE;        // Disables filling in manual IP
                                        // if you want to disable this then 
                                        // place an IP address in place of NULL
                                        // in getaddrinfo()

    // Read into servinfo
    status = getaddrinfo(NULL, PORT_NUM, &hints, &servinfo);

    if (status != 0) {                  // TODO: turn error checking into a func
        fprintf(stderr, "ERROR: failed to retrieve server info (%s)", gai_strerror(status));
        exit(1);
    }

    // TODO: walk the list of values of the linked list - connection
    // assumes the first one is the correct one to use
    
    // Set up the socket
    int sock_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    
    if (sock_fd != 0) {
        fprintf(stderr, "ERROR: Failed to create socket");
        exit(1);
    }

    // Bind the socket
    int err = bind(sock_fd, servinfo->ai_addr, servinfo->ai_addrlen);

    if (err != 0) {
        fprintf(stderr, "ERROR: Failed to bind socket");
        exit(1);
    }

    // Listen
    err = listen(sock_fd, 5);           // TODO: make configurable

    if (err != 0) {
        fprintf(stderr, "ERROR: Failed to listen");
        exit(1);
    }

    // Accept
    struct sockaddr_storage client;

    socklen_t client_size = sizeof(client);
    int client_fd = accept(sockfd, (struct sockaddr *)&client, &client_size);

    if (client_fd < 0) {
        fprintf(stderr, "ERROR: Failed to accept client");
        exit(1);
    }

    printf("client connected");

    // From here client_fd will send() and recv() messages to and from that
    // client.

    // Free servinfo
    freeaddrinfo(servinfo);
}
