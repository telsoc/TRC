#include <stdlib.h>
#include "topology.h"


/* To anyone who reads this code, this here
 * sits as proof that lambdas are a useful
 * language feature (lisp 4 life).
 *
 * NOTE:
 * THESE FUNCTIONS DO NOT DO VERY MUCH CHECKING!
 * The functions calling these ones should be
 * ensuring that the user and channels exist
 * before anything is done.
 */
struct UserArray *add_new_user(struct User new_user, struct UserArray *user_array) {
  user_array->number_of_users += 1;
  user_array->array = realloc(user_array->array,
			      user_array->number_of_users * sizeof(struct User));

  if(user_array->array == NULL)
    return(user_array);

  user_array->array[user_array->number_of_users - 1] = new_user;
  return(user_array);
}

int add_user_to_channel(struct Channel *channel, struct User *user) {
  if(MAX_CHANNEL_USERS <= channel->number_of_users)
    return(-1);

  channel->users[channel->number_of_users] = user;
  return(0);
}
