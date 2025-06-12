/* Nicknames and real names must
 * be < 16 characters long.
 */
struct User {
  char nick[16];
  char real_name[16];
};

/* Channel names must be < 16 characters
 * long, and descriptions must be < 64.
 *
 * A channel must have < 32 users.
 */
struct Channel {
  char name[16];
  char desc[64];
  struct User users[32];
};
