#include "./socket/server.h"
#include "./socket/client.h"

#include <stdio.h>

#define PORT "64322"

int main() {
    int function;

    printf("Functions:\n\t1) Server\n\t2) Client\n>");
    scanf("%d", &function);

    if (function == 1) {
        int client = start_server(PORT);
        printf("%s\n", server_recv(client));
        server_send(client, "Pong\0", 5);
        printf("%s\n", server_recv(client));
        server_send(client, "Pong\0", 5);
    }
    else
        start_client(PORT);

    return 0;
}
