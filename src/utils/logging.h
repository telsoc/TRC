#ifndef H_LOGGING
#define H_LOGGING

#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef enum {
    L_FATAL,
    L_ERROR,
    L_WARN,
    L_NOTIF,
    L_NORMAL
} MessageType;


/**
 * log() prints a message with a newline - it is coloured with ANSI escape
 * sequences in accordance to its type.
 */
static inline void mlog(MessageType type, const char* message) {
    // Print colour
    switch (type) {
        case L_FATAL:
            printf("\033[30;41mFATAL\t");
            break;
        case L_ERROR:
            printf("\033[31mERROR\t");
            break;
        case L_WARN:
            printf("\033[33mWARNING\t");
            break;
        case L_NOTIF:
            printf("\033[36mNOTIF\t");
            break;
        case L_NORMAL:
        default:
            printf("\033[37mLOG\t");
            break;
    }

    // Print message
    printf("%s\033[0m\n", message);
    fflush(stdout);
}


/**
 * log_err() is like log(L_ERROR, message), but it appends the string of 
 * strerror and explicitly prints to stderr.
 */
static inline void mlog_err(const char* message) {
    fprintf(stderr, "\033[31mERROR\t%s (errno message: %s)\033[0m\n", message, strerror(errno));
    fflush(stderr);
}

#endif
