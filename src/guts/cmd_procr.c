#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd_procr.h"


char *process_command(char *cmd) {
  for(int i=0; i < NOC; i++) {
    if(strcmp(cmd, cmd_list[i])) {
      func_list[i]();
      return(0x0);
    }
  }

  /* This will probably be sent to a client, instead
   * of just sitting in stderr, but for now this works.
   */
  fprintf(stderr, "ERROR: command not found!");
  return("ERROR: command not found!");
}


int r_admin() {return(0);}
int r_away() {return(0);}
int r_cnotice() {return(0);}
int r_cprivmsg() {return(0);}
int r_connect() {return(0);}
int r_die() {return(0);}
int r_encap() {return(0);}
int r_error() {return(0);}
int r_help() {return(0);}
int r_info() {return(0);}
int r_invite() {return(0);}
int r_ison() {return(0);}
int r_join() {return(0);}
int r_kick() {return(0);}
int r_kill() {return(0);}
int r_knock() {return(0);}
int r_links() {return(0);}
int r_list() {return(0);}
int r_lusers() {return(0);}
int r_mode() {return(0);}
int r_motd() {return(0);}
int r_names() {return(0);}
int r_nick() {return(0);}
int r_notice() {return(0);}
int r_oper() {return(0);}
int r_part() {return(0);}
int r_pass() {return(0);}
int r_ping() {return(0);}
int r_pong() {return(0);}
int r_privmsg() {return(0);}
int r_quit() {return(0);}
int r_quote() {return(0);}
int r_rehash() {return(0);}
int r_rules() {return(0);}
int r_server() {return(0);}
int r_service() {return(0);}
int r_servlist() {return(0);}
int r_squery() {return(0);}
int r_squit() {return(0);}
int r_setname() {return(0);}
int r_silence() {return(0);}
int r_stats() {return(0);}
int r_summon() {return(0);}
int r_time() {return(0);}
int r_topic() {return(0);}
int r_trace() {return(0);}
int r_user() {return(0);}
int r_userhost() {return(0);}
int r_userip() {return(0);}
int r_users() {return(0);}
int r_version() {return(0);}
int r_wallops() {return(0);}
int r_watch() {return(0);}
int r_who() {return(0);}
int r_whois() {return(0);}
int r_whowas() {return(0);}
