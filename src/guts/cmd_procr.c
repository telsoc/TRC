#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd_procr.h"

char *process_command(char *cmd) {
  for(int i=0; i < NOC; i++) {
    if(strcmp(cmd, cmd_list[i])) {
      func_list[i](cmd);
      return("");
    }
  }

  fprintf(stderr, "ERROR: command not found!");
  return("ERROR: command not found!");
}

char *r_admin(char *input) {return(0);}
char *r_away(char *input) {return(0);}
char *r_cnotice(char *input) {return(0);}
char *r_cprivmsg(char *input) {return(0);}
char *r_connect(char *input) {return(0);}
char *r_die(char *input) {return(0);}
char *r_encap(char *input) {return(0);}
char *r_error(char *input) {return(0);}
char *r_help(char *input) {return(0);}
char *r_info(char *input) {return(0);}
char *r_invite(char *input) {return(0);}
char *r_ison(char *input) {return(0);}
char *r_join(char *input) {return(0);}
char *r_kick(char *input) {return(0);}
char *r_kill(char *input) {return(0);}
char *r_knock(char *input) {return(0);}
char *r_links(char *input) {return(0);}
char *r_list(char *input) {return(0);}
char *r_lusers(char *input) {return(0);}
char *r_mode(char *input) {return(0);}
char *r_motd(char *input) {return(0);}
char *r_names(char *input) {return(0);}
char *r_nick(char *input) {return(0);}
char *r_notice(char *input) {return(0);}
char *r_oper(char *input) {return(0);}
char *r_part(char *input) {return(0);}
char *r_pass(char *input) {return(0);}
char *r_ping(char *input) {return(0);}
char *r_pong(char *input) {return(0);}
char *r_privmsg(char *input) {return(0);}
char *r_quit(char *input) {return(0);}
char *r_quote(char *input) {return(0);}
char *r_rehash(char *input) {return(0);}
char *r_rules(char *input) {return(0);}
char *r_server(char *input) {return(0);}
char *r_service(char *input) {return(0);}
char *r_servlist(char *input) {return(0);}
char *r_squery(char *input) {return(0);}
char *r_squit(char *input) {return(0);}
char *r_setname(char *input) {return(0);}
char *r_silence(char *input) {return(0);}
char *r_stats(char *input) {return(0);}
char *r_summon(char *input) {return(0);}
char *r_time(char *input) {return(0);}
char *r_topic(char *input) {return(0);}
char *r_trace(char *input) {return(0);}
char *r_user(char *input) {return(0);}
char *r_userhost(char *input) {return(0);}
char *r_userip(char *input) {return(0);}
char *r_users(char *input) {return(0);}
char *r_version(char *input) {return(0);}
char *r_wallops(char *input) {return(0);}
char *r_watch(char *input) {return(0);}
char *r_who(char *input) {return(0);}
char *r_whois(char *input) {return(0);}
char *r_whowas(char *input) {return(0);}
