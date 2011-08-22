%{

#include <stdio.h>
#include <string.h>
#include "gcup.h"
 
void yyerror(const char *str)
{
}
 
int yywrap()
{
        return 1;
} 

%}

%union 
{
        int number;
        char *string;
}

%token <number> NUMBER
%token <string> PATH
%token <string> UNKNOWN

%token COMMA START RECTSTART RESTART GAME_BEGIN BOARD DONE
%token INFO timeout_turn timeout_match max_memory time_left game_type rule evaluate folder
%token END ABOUT TURN TAKEBACK PLAY ENDL NA

%%

commands:
        | commands command
        ;

command:
        target_start
        | target_rectstart
        | target_restart
        | target_begin
        | target_board
        | target_board_move
        | target_board_done
        | target_timeout_turn
        | target_timeout_match
        | target_max_memory
        | target_time_left
        | target_game_type
        | target_rule
        | target_evaluate
        | target_folder
        | target_end
        | target_about
        | target_turn
        | target_takeback
        | target_play
        | target_unknown
        | target_na
        | target_empty
        | error 
          {
                printf("ERROR syntax error\n");
          }
        
        ;
        
target_start:
        START NUMBER ENDL
        {
                gcup_start($2);
        }
        ;

target_rectstart:
        RECTSTART NUMBER COMMA NUMBER ENDL
        {
                gcup_rectstart($2, $4);
        }
        ;

target_restart:
        RESTART ENDL
        {
                gcup_restart();
        }
        ;

target_begin:
        GAME_BEGIN ENDL
        {
                gcup_begin();
        }
        ;

target_board:
        BOARD ENDL 
        {
                gcup_board();
        }
        ;

target_board_move:
        NUMBER COMMA NUMBER COMMA NUMBER ENDL
        {
                gcup_board_move($1, $3, $5);
        }
        ;

target_board_done:
        DONE ENDL
        {
                gcup_board_done();
        }
        ;

target_timeout_turn:
        INFO timeout_turn NUMBER ENDL
        {
                gcup_info_timeout_turn($3);
        }
        ;

target_timeout_match:
        INFO timeout_match NUMBER ENDL
        {
                gcup_info_timeout_match($3);
        }
        ;

target_max_memory:
        INFO max_memory NUMBER ENDL
        {
                gcup_info_max_memory($3);
        }
        ;

target_time_left:
        INFO time_left NUMBER ENDL
        {
                gcup_info_time_left($3);
        }
        ;

target_game_type:
        INFO game_type NUMBER ENDL
        {
                gcup_info_game_type($3);
        }
        ;

target_rule:
        INFO rule NUMBER ENDL
        {
                gcup_info_rule($3);
        }
        ;

target_evaluate:
        INFO evaluate NUMBER COMMA NUMBER ENDL
        {
                gcup_info_evaluate($3, $5);
        }
        ;

target_folder:
        INFO folder PATH ENDL
        {
                gcup_info_folder($3);
        }
        ;

target_end:
        END ENDL
        {
                gcup_end();
        }
        ;

target_about:
        ABOUT ENDL
        {
                gcup_about();
        }
        ;

target_turn:
        TURN NUMBER COMMA NUMBER ENDL
        {
                gcup_turn($2, $4);
        }
        ;

target_takeback:
        TAKEBACK NUMBER COMMA NUMBER ENDL
        {
                gcup_takeback($2, $4);
        }
        ;

target_play:
        PLAY NUMBER COMMA NUMBER ENDL
        {
                gcup_play($2, $4);
        }
        ;

target_unknown:
        UNKNOWN
        {
                printf("UNKNOWN unknown command %s\n", $1);
        }

target_na:
        NA
        {
                printf("ERROR syntax error\n");
        }
        ;

target_empty:
        ENDL
        {
        }
        ;

%%