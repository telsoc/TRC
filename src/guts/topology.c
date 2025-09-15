#include <stdlib.h>
#include "topology.h"


struct User_Array add_new_user(struct User new_user, struct User_Array user_array) {
  user_array.number_of_users += 1;
  user_array.array = realloc(user_array.array,
			     user_array.number_of_users * sizeof(struct User));

  if(user_array.array == NULL)
    return(user_array);

  user_array.array[user_array.number_of_users - 1] = new_user;
  return(user_array);
}
