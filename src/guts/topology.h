#define NICK_LENGTH 16
#define NAME_LENGTH 16
#define DESC_LENGTH 64
#define MESSAGE_LENGTH 128
#define MAX_CHANNEL_USERS 32


struct User {
  char nick[NICK_LENGTH];
  char real_name[NAME_LENGTH];
};

struct Channel {
  char name[NAME_LENGTH];
  char desc[DESC_LENGTH];
  struct User *users[MAX_CHANNEL_USERS];
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
