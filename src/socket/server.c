// server.c
// Provides implementations for server.h. These are all socket server related functions.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "../utils/logging.h"
#include "server.h"

struct addrinfo* get_address_info(char* port_str) {
    struct addrinfo hints;
    struct addrinfo* servinfo;

    // Clearing and setting up hints
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;        // Works for IPv4 & 6
    hints.ai_socktype = SOCK_STREAM;    // TCP
    hints.ai_flags = AI_PASSIVE;        // Disables filling in manual IP
                                        // if you want to disable this then 
                                        // place an IP address in place of NULL
                                        // in getaddrinfo()

    // Read into servinfo
    int err = getaddrinfo(NULL, port_str, &hints, &servinfo);

    if (err < 0) {                      // TODO: turn error checking into a func
        mlog_err("ERROR: failed to retrieve server info");
        exit(1);
    }

    mlog(L_NORMAL, "LOG: retrieved addrinfo\n");

    // TODO: walk the list of values of the linked list - connection
    // assumes the first one is the correct one to use

    return servinfo;
}



int socket_create(int family, int socktype, int protocol) {
    int sock_fd = socket(family, socktype, protocol);
    
    if (sock_fd < 0) {
        mlog_err("ERROR: Failed to create socket");
        exit(1);
    }

    mlog(L_NORMAL, "LOG: created socket\n");

    return sock_fd;
}

int socket_create_from_info(struct addrinfo* servinfo) {
    return socket_create(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
}



void socket_bind(int sock_fd, struct sockaddr* addr, socklen_t addrlen) {
    int err = bind(sock_fd, addr, addrlen);

    if (err < 0) {
        mlog_err("ERROR: Failed to bind socket");
        exit(1);
    }

    mlog(L_NORMAL, "LOG: binded socket\n");
}

void socket_bind_from_info(int sock_fd, struct addrinfo* servinfo) {
    socket_bind(sock_fd, servinfo->ai_addr, servinfo->ai_addrlen);
}



void socket_listen(int sock_fd, int backlog) {
    int err = listen(sock_fd, backlog);

    if (err < 0) {
        mlog_err("ERROR: Failed to listen");
        exit(1);
    }

    mlog(L_NORMAL, "LOG: socket listening\n");
}



int socket_accept(int sock_fd) {
    struct sockaddr_storage client;
    socklen_t client_size = sizeof(client);

    int client_fd = accept(sock_fd, (struct sockaddr *)&client, &client_size);

    if (client_fd < 0) {
        mlog_err("ERROR: Failed to accept client");
        exit(1);
    }

    mlog(L_NORMAL, "LOG: client accepted\n");

    return client_fd;
}



char* server_recv(int client_fd) {
    char* buf = (char*) malloc(sizeof(char) * MESSAGE_MAX_LEN);

    if (buf == NULL)
        return NULL;

    ssize_t read_bytes = recv(client_fd, buf, MESSAGE_MAX_LEN, 0);

    if (read_bytes == CLIENT_DISCONNECT)
        return "\0";
        
    buf[read_bytes] = '\0';
    return buf;
}


int server_send(int client_fd, char* msg, int len) {
    return send(client_fd, msg, len, 0);
}


int start_server(char* port_str) {
    struct addrinfo* servinfo = get_address_info(port_str);
    int sock_fd = socket_create_from_info(servinfo);
    socket_bind_from_info(sock_fd, servinfo);
    socket_listen(sock_fd, 5);

    // Free servinfo
    freeaddrinfo(servinfo);

    return sock_fd;
}
