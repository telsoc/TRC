#include <stdlib.h>
#include <string.h>
#include "init.h"
#include "topology.h"


/* noc is Number Of Channels */
struct ChannelArray *init_channel_array(struct ChannelArray *channel_array, char **channels, int noc) {
  channel_array = malloc(sizeof(struct ChannelArray));
  channel_array->number_of_channels = noc;
  channel_array->array = (struct Channel**) malloc(sizeof(struct Channel*) * noc);
  for(int i = 0; i < noc; i++) {
    channel_array->array[i] = init_channel(channels[i]);
  }
  return(channel_array);
}

struct Channel *init_channel(char *channel_name) {
  struct Channel *new_channel = malloc(sizeof(struct Channel));
  strcpy(new_channel->name, channel_name);
  new_channel->number_of_users = 0;
  new_channel->desc[0] = '\0';
  new_channel->users[0] = NULL;

  return(new_channel);
}
