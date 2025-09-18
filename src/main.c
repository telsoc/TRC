#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main(int argc, char **argv) {
    char **config = parse_config(argv[1]);
    for(int i = 0; config[i] != NULL; i++) printf("%s", config[i]);
    return 0;
}


char **parse_config(char *filename) {
    /* This hardcoded value does have a macro
     * for it, but regrettably, it's in another
     * branch, so for now it's this :( .
     */
    char **file_data = malloc(128);
    FILE *config_file = fopen(filename, "r");
    if(config_file == NULL) {
	fprintf(stderr, "ERROR: no such file, \"%s\"\n", filename);
	return(NULL);
    }
    for(int i = 0; i < 16; i++) file_data[i] = malloc(32);
    for(int i = 0; fgets(file_data[i], 16, config_file); i++);

    fclose(config_file);
    return(file_data);
}
