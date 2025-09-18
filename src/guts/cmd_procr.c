#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd_procr.h"
#include "topology.h"
#include "init_guts.h"


char *process_command(char *cmd) {
    for(int i=0; i < NOC; i++) {
	if(strcmp(cmd, cmd_list[i])) {
	    func_list[i](cmd, 0, 0);
	    return("");
	}
    }

    fprintf(stderr, "ERROR: command not found!");
    return("ERROR: command not found!");
}

char r_admin(char *input, struct User *user, void *additional_args) {return(0);}
char r_away(char *input, struct User *user, void *additional_args) {return(0);}
char r_cnotice(char *input, struct User *user, void *additional_args) {return(0);}
char r_cprivmsg(char *input, struct User *user, void *additional_args) {return(0);}
char r_connect(char *input, struct User *user, void *additional_args) {return(0);}
char r_die(char *input, struct User *user, void *additional_args) {return(0);}
char r_encap(char *input, struct User *user, void *additional_args) {return(0);}
char r_error(char *input, struct User *user, void *additional_args) {return(0);}
char r_help(char *input, struct User *user, void *additional_args) {return(0);}
char r_info(char *input, struct User *user, void *additional_args) {return(0);}
char r_invite(char *input, struct User *user, void *additional_args) {return(0);}
char r_ison(char *input, struct User *user, void *additional_args) {return(0);}
char r_join(char *channel_name, struct User *user, void *channel_array) {
    for(int i = 0; i < MAX_CHANNELS; i++) {
	if(strcmp(channel_name, ((struct ChannelArray*)channel_array)->array[i]->name)) {
	    add_user_to_channel(((struct ChannelArray*)channel_array)->array[i], user);
	    return(0);
	}
    }

    fprintf(stderr, "ERROR: CHANNEL COULD NOT BE FOUND!\n");
    return(-1);
}

char r_kick(char *input, struct User *user, void *additional_args) {return(0);}
char r_kill(char *input, struct User *user, void *additional_args) {return(0);}
char r_knock(char *input, struct User *user, void *additional_args) {return(0);}
char r_links(char *input, struct User *user, void *additional_args) {return(0);}
char r_list(char *input, struct User *user, void *additional_args) {return(0);}
char r_lusers(char *input, struct User *user, void *additional_args) {return(0);}
char r_mode(char *input, struct User *user, void *additional_args) {return(0);}
char r_motd(char *input, struct User *user, void *additional_args) {return(0);}
char r_names(char *input, struct User *user, void *additional_args) {return(0);}
char r_nick(char *input, struct User *user, void *additional_args) {return(0);}
char r_notice(char *input, struct User *user, void *additional_args) {return(0);}
char r_oper(char *input, struct User *user, void *additional_args) {return(0);}
char r_part(char *input, struct User *user, void *additional_args) {return(0);}
char r_pass(char *input, struct User *user, void *additional_args) {return(0);}
char r_ping(char *input, struct User *user, void *additional_args) {return(0);}
char r_pong(char *input, struct User *user, void *additional_args) {return(0);}
char r_privmsg(char *input, struct User *user, void *additional_args) {return(0);}
char r_quit(char *input, struct User *user, void *additional_args) {return(0);}
char r_quote(char *input, struct User *user, void *additional_args) {return(0);}
char r_rehash(char *input, struct User *user, void *additional_args) {return(0);}
char r_rules(char *input, struct User *user, void *additional_args) {return(0);}
char r_server(char *input, struct User *user, void *additional_args) {return(0);}
char r_service(char *input, struct User *user, void *additional_args) {return(0);}
char r_servlist(char *input, struct User *user, void *additional_args) {return(0);}
char r_squery(char *input, struct User *user, void *additional_args) {return(0);}
char r_squit(char *input, struct User *user, void *additional_args) {return(0);}
char r_setname(char *input, struct User *user, void *additional_args) {return(0);}
char r_silence(char *input, struct User *user, void *additional_args) {return(0);}
char r_stats(char *input, struct User *user, void *additional_args) {return(0);}
char r_summon(char *input, struct User *user, void *additional_args) {return(0);}
char r_time(char *input, struct User *user, void *additional_args) {return(0);}
char r_topic(char *input, struct User *user, void *additional_args) {return(0);}
char r_trace(char *input, struct User *user, void *additional_args) {return(0);}
char r_user(char *input, struct User *user, void *additional_args) {return(0);}
char r_userhost(char *input, struct User *user, void *additional_args) {return(0);}
char r_userip(char *input, struct User *user, void *additional_args) {return(0);}
char r_users(char *input, struct User *user, void *additional_args) {return(0);}
char r_version(char *input, struct User *user, void *additional_args) {return(0);}
char r_wallops(char *input, struct User *user, void *additional_args) {return(0);}
char r_watch(char *input, struct User *user, void *additional_args) {return(0);}
char r_who(char *input, struct User *user, void *additional_args) {return(0);}
char r_whois(char *input, struct User *user, void *additional_args) {return(0);}
char r_whowas(char *input, struct User *user, void *additional_args) {return(0);}
