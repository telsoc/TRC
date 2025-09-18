#include <stdio.h>
#include "main.h"


int main(int argc, char **argv) {
    return 0;
}


char **parse_config(char *filename) {
    /* This hardcoded value does have a macro
     * for it, but regrettably, it's in another
     * branch, so for now it's this :( .
     */
    char *file_data[128];
    FILE *config_file = fopen(filename, "w");
    if(config_file == NULL) {
	fprintf(stderr, "ERROR: no such file, \"%s\"", filename);
	return(NULL);
    }


    fclose(config_file);
    return(file_data);
}
