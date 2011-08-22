%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}

%%
[0-9]+            yylval.number=atoi(yytext); return NUMBER;
([a-zA-Z]:|[~]*[/])[a-zA-Z0-9\\/]+  yylval.string=strdup(yytext);return PATH;
,                 return COMMA;
^START            return START;
^RECTSTART        return RECTSTART;
^RESTART          return RESTART;
^BEGIN            return GAME_BEGIN;
^BOARD            return BOARD;
^DONE             return DONE;
^END              return END;
^ABOUT            return ABOUT;
^TURN             return TURN;
^TAKEBACK         return TAKEBACK;
^PLAY             return PLAY;
^INFO             return INFO;
^[A-Z]+           yylval.string=strdup(yytext);return UNKNOWN;
timeout_turn      return timeout_turn; 
timeout_match     return timeout_match;
max_memory        return max_memory;
time_left         return time_left;
game_type         return game_type;
rule              return rule;
evaluate          return evaluate;
folder            return folder;
\n                return ENDL;
[ \t]+
%%
