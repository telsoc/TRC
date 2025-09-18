#include <stdlib.h>
#include <string.h>
#include "init_guts.h"
#include "topology.h"


/* noc is Number Of Channels */
struct Guts init_guts(char **channels, int noc) {
  struct Guts guts;
  /* Below line is just to get rid of a warning
   * during compilation. If you want to remove it,
   * feel free.
   */
  guts.channel_array = NULL;
  guts.channel_array = init_channel_array(guts.channel_array, channels, noc);
  
  return(guts);
}

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
