<h1 align="center">The official telsoc IRC server's style guide!</h1>

When creating C files, functions, or variables, default to snake case, that is, a function that adds some connection could be called `add_connection`.

When creating structs or typedefs for them, default to upper camel case, that is, a struct for a linked list could be called `LinkedList`.

Macros should be in screaming snake case, such as `NUMBER_OF_THINGS`.

Use 4 spaces for indentation, not tabs.
How you do your comments is up to you (IE, `// :3` and `/* :3 */` are both valid).


Each .c file should have a corresponding header file with the same root name, that is, `foo.c` should have `foo.h`.
Functions should be documented in their header files, unless it's some specific implementation details, which should go -- as you may have guessed -- beside the implementation.
