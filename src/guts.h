/* Number Of Commands */
#define NOC 56

int r_admin();
int r_away();
int r_cnotice();
int r_cprivmsg();
int r_connect();
int r_die();
int r_encap();
int r_error();
int r_help();
int r_info();
int r_invite();
int r_ison();
int r_join();
int r_kick();
int r_kill();
int r_knock();
int r_links();
int r_list();
int r_lusers();
int r_mode();
int r_motd();
int r_names();
int r_nick();
int r_notice();
int r_oper();
int r_part();
int r_pass();
int r_ping();
int r_pong();
int r_privmsg();
int r_quit();
int r_quote();
int r_rehash();
int r_rules();
int r_server();
int r_service();
int r_servlist();
int r_squery();
int r_squit();
int r_setname();
int r_silence();
int r_stats();
int r_summon();
int r_time();
int r_topic();
int r_trace();
int r_user();
int r_userhost();
int r_userip();
int r_users();
int r_version();
int r_wallops();
int r_watch();
int r_who();
int r_whois();
int r_whowas();


char *cmd_list[NOC] = {"admin", "away", "cnotice", "cprivmsg", "connect", "die", "encap", "error", "help", "info", "invite", "ison", "join", "kick", "kill", "knock", "links", "list", "lusers", "mode", "motd", "names", "nick", "notice", "oper", "part", "pass", "ping", "pong", "privmsg", "quit", "quote", "rehash", "rules", "server", "service", "servlist", "squery", "squit", "setname", "silence", "stats", "summon", "time", "topic", "trace", "user", "userhost", "userip", "users", "version", "wallops", "watch", "who", "whois", "whowas"};

int (*func_list[NOC])() = {r_admin, r_away, r_cnotice, r_cprivmsg, r_connect, r_die, r_encap, r_error, r_help, r_info, r_invite, r_ison, r_join, r_kick, r_kill, r_knock, r_links, r_list, r_lusers, r_mode, r_motd, r_names, r_nick, r_notice, r_oper, r_part, r_pass, r_ping, r_pong, r_privmsg, r_quit, r_quote, r_rehash, r_rules, r_server, r_service, r_servlist, r_squery, r_squit, r_setname, r_silence, r_stats, r_summon, r_time, r_topic, r_trace, r_user, r_userhost, r_userip, r_users, r_version, r_wallops, r_watch, r_who, r_whois, r_whowas};
