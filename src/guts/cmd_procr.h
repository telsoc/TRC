/* Number Of Commands */
#define NOC 56

char *r_admin(char *input);
char *r_away(char *input);
char *r_cnotice(char *input);
char *r_cprivmsg(char *input);
char *r_connect(char *input);
char *r_die(char *input);
char *r_encap(char *input);
char *r_error(char *input);
char *r_help(char *input);
char *r_info(char *input);
char *r_invite(char *input);
char *r_ison(char *input);
char *r_join(char *input);
char *r_kick(char *input);
char *r_kill(char *input);
char *r_knock(char *input);
char *r_links(char *input);
char *r_list(char *input);
char *r_lusers(char *input);
char *r_mode(char *input);
char *r_motd(char *input);
char *r_names(char *input);
char *r_nick(char *input);
char *r_notice(char *input);
char *r_oper(char *input);
char *r_part(char *input);
char *r_pass(char *input);
char *r_ping(char *input);
char *r_pong(char *input);
char *r_privmsg(char *input);
char *r_quit(char *input);
char *r_quote(char *input);
char *r_rehash(char *input);
char *r_rules(char *input);
char *r_server(char *input);
char *r_service(char *input);
char *r_servlist(char *input);
char *r_squery(char *input);
char *r_squit(char *input);
char *r_setname(char *input);
char *r_silence(char *input);
char *r_stats(char *input);
char *r_summon(char *input);
char *r_time(char *input);
char *r_topic(char *input);
char *r_trace(char *input);
char *r_user(char *input);
char *r_userhost(char *input);
char *r_userip(char *input);
char *r_users(char *input);
char *r_version(char *input);
char *r_wallops(char *input);
char *r_watch(char *input);
char *r_who(char *input);
char *r_whois(char *input);
char *r_whowas(char *input);


/* The below two lists may be merged into one
 * of tuples at some point, though unless it's
 * packed, that might add some unnecessary memory
 * overhead.
 */
char *cmd_list[NOC] = {"admin", "away", "cnotice", "cprivmsg", "connect", "die", "encap", "error", "help", "info", "invite", "ison", "join", "kick", "kill", "knock", "links", "list", "lusers", "mode", "motd", "names", "nick", "notice", "oper", "part", "pass", "ping", "pong", "privmsg", "quit", "quote", "rehash", "rules", "server", "service", "servlist", "squery", "squit", "setname", "silence", "stats", "summon", "time", "topic", "trace", "user", "userhost", "userip", "users", "version", "wallops", "watch", "who", "whois", "whowas"};

char *(*func_list[NOC])(char*) = {r_admin, r_away, r_cnotice, r_cprivmsg, r_connect, r_die, r_encap, r_error, r_help, r_info, r_invite, r_ison, r_join, r_kick, r_kill, r_knock, r_links, r_list, r_lusers, r_mode, r_motd, r_names, r_nick, r_notice, r_oper, r_part, r_pass, r_ping, r_pong, r_privmsg, r_quit, r_quote, r_rehash, r_rules, r_server, r_service, r_servlist, r_squery, r_squit, r_setname, r_silence, r_stats, r_summon, r_time, r_topic, r_trace, r_user, r_userhost, r_userip, r_users, r_version, r_wallops, r_watch, r_who, r_whois, r_whowas};
