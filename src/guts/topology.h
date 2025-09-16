#define NICK_LENGTH 16
#define NAME_LENGTH 16
#define DESC_LENGTH 64
#define MESSAGE_LENGTH 128
#define MAX_CHANNEL_USERS 32
#define MAX_CHANNELS 128


struct User {
  char nick[NICK_LENGTH];
  char real_name[NAME_LENGTH];
};

/* number_of_users is fine to be an unsigned
 * int, because I'm not convinced that
 * there's more than 4294967296 IRC users that
 * exist.
 */
struct UserArray {
  struct User *array;
  unsigned int number_of_users;
};

struct Channel {
  char name[NAME_LENGTH];
  char desc[DESC_LENGTH];
  struct User *users[MAX_CHANNEL_USERS];
  unsigned char number_of_users;
};

struct ChannelArray {
  struct Channel **array;
  unsigned int number_of_channels;
};

/* This is set to a user pointer to try
 * and save memory, similar to a flyweight.
 *
 * Channel is a pointer for the same reason.
 */
struct Message {
  struct User *user;
  struct Channel *channel;
  char message[MESSAGE_LENGTH];
};


struct UserArray *add_new_user(struct User new_user, struct UserArray *user_array);
int add_user_to_channel(struct Channel *channel, struct User *user);
