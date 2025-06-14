/// @file server.h
/**
 * Starting a server that complies with IPv4 and 6 is as simple as running the
 * following:
 *
 * ```
 * struct addrinfo* servinfo = get_address_info("12345");
 * int sock_fd = socket_create_from_info(servinfo);
 * socket_bind_from_info(sock_fd, servinfo);
 * socket_listen(sock_fd, 5);
 * int client = socket_accept(sock_fd);
 * ```
 *
 * Implementations for handling multiple connections are not provided - this 
 * file only deals with socket and server creation, and send/recv. 
 *
 * This means `client` in the above program  will only be a single client
 * (the client who connects first).
 */

#ifndef H_SERVER
#define H_SERVER

#include <sys/socket.h>

#define MESSAGE_MAX_LEN 512     ///< Max message that most IRC clients can support
#define CLIENT_DISCONNECT 0     ///< Value returned by recv call if the other end has disconnected

// TODO: create a type alias for client?

/** 
 * Retrieves a linked list of address information
 *
 * This can be used to automatically support IPv4 and IPv6 address if you use
 * the `socket_x_from_info` functions to create your sockets.
 *
 * Make sure to call freeaddrinfo() from <sys/socket.h> to avoid leaking memory.
 *
 * @param[in] port_str Target port address
 */
struct addrinfo* get_address_info(char* port_str);



/// Wrapper for socket() that performs logging and error checking (it will call exit() on fail)
int socket_create(int family, int socktype, int protocol);

/// Wrapper for socket_create() that accepts addrinfo* 
int socket_create_from_info(struct addrinfo* servinfo);



/// Wrapper for bind() that performs logging and error checking (it will call exit() on fail)
void socket_bind(int sock_fd, struct sockaddr* addr, socklen_t addrlen);

/// Wrapper for socket_bind() that accepts addrinfo* 
void socket_bind_from_info(int sock_fd, struct addrinfo* servinfo);



/// Wrapper for listen() that performs logging and error checking (it will call exit() on fail)
void socket_listen(int sock_fd, int backlog);

/// Wrapper for accept() that performs logging and error checking (it will call exit() on fail)
int socket_accept(int sock_fd);



/// Recieve raw text data from client_fd (blocking)
char* server_recv(int client_fd);

/// Send raw text data to client_fd (blocking)
int server_send(int client_fd, char* msg, int len);



/// Wrapper for all server.h functions, starts a server on a given port and returns the socket file descriptor (returned in int). From here you can accept clients and use send/recv.
int start_server(char* port_str);

#endif
