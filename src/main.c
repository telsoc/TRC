#include "./socket/server.h"
#include "./socket/client.h"

#include <stdio.h>

int main() {
    int function;

    printf("Functions:\n\t1) Server\n\t2) Client\n>");
    scanf("%d", &function);

    if (function == 1)
        start_server();
    else
        start_client();

    return 0;
}
