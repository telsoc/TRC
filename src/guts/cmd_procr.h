#include "topology.h"

/* Number Of Commands */
#define NOC 56


int process_command(char *cmd, struct User *user);
char *command_part(char *cmd);
char *arguments_part(char *cmd);
int load_line(struct User *user);

char r_admin(char *input, struct User *user, void *additional_args);
char r_away(char *input, struct User *user, void *additional_args);
char r_cnotice(char *input, struct User *user, void *additional_args);
char r_cprivmsg(char *input, struct User *user, void *additional_args);
char r_connect(char *input, struct User *user, void *additional_args);
char r_die(char *input, struct User *user, void *additional_args);
char r_encap(char *input, struct User *user, void *additional_args);
char r_error(char *input, struct User *user, void *additional_args);
char r_help(char *input, struct User *user, void *additional_args);
char r_info(char *input, struct User *user, void *additional_args);
char r_invite(char *input, struct User *user, void *additional_args);
char r_ison(char *input, struct User *user, void *additional_args);
char r_join(char *channel_name, struct User *user, void *channel_array);
char r_kick(char *input, struct User *user, void *additional_args);
char r_kill(char *input, struct User *user, void *additional_args);
char r_knock(char *input, struct User *user, void *additional_args);
char r_links(char *input, struct User *user, void *additional_args);
char r_list(char *input, struct User *user, void *additional_args);
char r_lusers(char *input, struct User *user, void *additional_args);
char r_mode(char *input, struct User *user, void *additional_args);
char r_motd(char *input, struct User *user, void *additional_args);
char r_names(char *input, struct User *user, void *additional_args);
char r_nick(char *input, struct User *user, void *additional_args);
char r_notice(char *input, struct User *user, void *additional_args);
char r_oper(char *input, struct User *user, void *additional_args);
char r_part(char *input, struct User *user, void *additional_args);
char r_pass(char *input, struct User *user, void *additional_args);
char r_ping(char *input, struct User *user, void *additional_args);
char r_pong(char *input, struct User *user, void *additional_args);
char r_privmsg(char *input, struct User *user, void *additional_args);
char r_quit(char *input, struct User *user, void *additional_args);
char r_quote(char *input, struct User *user, void *additional_args);
char r_rehash(char *input, struct User *user, void *additional_args);
char r_rules(char *input, struct User *user, void *additional_args);
char r_server(char *input, struct User *user, void *additional_args);
char r_service(char *input, struct User *user, void *additional_args);
char r_servlist(char *input, struct User *user, void *additional_args);
char r_squery(char *input, struct User *user, void *additional_args);
char r_squit(char *input, struct User *user, void *additional_args);
char r_setname(char *input, struct User *user, void *additional_args);
char r_silence(char *input, struct User *user, void *additional_args);
char r_stats(char *input, struct User *user, void *additional_args);
char r_summon(char *input, struct User *user, void *additional_args);
char r_time(char *input, struct User *user, void *additional_args);
char r_topic(char *input, struct User *user, void *additional_args);
char r_trace(char *input, struct User *user, void *additional_args);
char r_user(char *input, struct User *user, void *additional_args);
char r_userhost(char *input, struct User *user, void *additional_args);
char r_userip(char *input, struct User *user, void *additional_args);
char r_users(char *input, struct User *user, void *additional_args);
char r_version(char *input, struct User *user, void *additional_args);
char r_wallops(char *input, struct User *user, void *additional_args);
char r_watch(char *input, struct User *user, void *additional_args);
char r_who(char *input, struct User *user, void *additional_args);
char r_whois(char *input, struct User *user, void *additional_args);
char r_whowas(char *input, struct User *user, void *additional_args);


/* char *cmd_list[NOC]; */
/* char (*func_list[NOC])(char*, struct User*, void *); */
