#include <stdio.h>
#include "init_guts.h"

#ifndef MESSAGE_LENGTH
#define MESSAGE_LENGTH 128
#endif


int load_line() {
  char cmd[MESSAGE_LENGTH];
  fgets(cmd, MESSAGE_LENGTH, stdin);
  printf("%s\n", cmd);

  return(0);
}
