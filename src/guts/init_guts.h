#include "topology.h"


struct Guts {
  struct ChannelArray *channel_array;
};


struct Guts init_guts(char **channels, int noc);
struct ChannelArray *init_channel_array(struct ChannelArray *channel_array, char **channels, int noc);
struct Channel *init_channel(char *channel_name);
