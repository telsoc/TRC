#include "topology.h"

/* Number Of Commands */
#define NOC 56


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


/* The below two lists may be merged into one
 * of tuples at some point, though unless it's
 * packed, that might add some unnecessary memory
 * overhead.
 */
char *cmd_list[NOC] = {"admin", "away", "cnotice", "cprivmsg", "connect", "die", "encap", "error", "help", "info", "invite", "ison", "join", "kick", "kill", "knock", "links", "list", "lusers", "mode", "motd", "names", "nick", "notice", "oper", "part", "pass", "ping", "pong", "privmsg", "quit", "quote", "rehash", "rules", "server", "service", "servlist", "squery", "squit", "setname", "silence", "stats", "summon", "time", "topic", "trace", "user", "userhost", "userip", "users", "version", "wallops", "watch", "who", "whois", "whowas"};

char (*func_list[NOC])(char*, struct User*, void *) = {r_admin, r_away, r_cnotice, r_cprivmsg, r_connect, r_die, r_encap, r_error, r_help, r_info, r_invite, r_ison, r_join, r_kick, r_kill, r_knock, r_links, r_list, r_lusers, r_mode, r_motd, r_names, r_nick, r_notice, r_oper, r_part, r_pass, r_ping, r_pong, r_privmsg, r_quit, r_quote, r_rehash, r_rules, r_server, r_service, r_servlist, r_squery, r_squit, r_setname, r_silence, r_stats, r_summon, r_time, r_topic, r_trace, r_user, r_userhost, r_userip, r_users, r_version, r_wallops, r_watch, r_who, r_whois, r_whowas};
