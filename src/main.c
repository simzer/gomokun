
#include <stdlib.h>
#include <stdio.h>

#include "board.h"
#include "engine.h"

int main(int argc, char **argv)
{
  engine_type *engine = engine_create(19,19);
  int row, col;
  char command[256];

  while(1)
  {
    if (scanf("%s %d,%d", command, &row, &col) == 3)
    {
      if (engine_step(row, col, engine) == 0)
      {
//        printf("Round %d:\n", engine->round);
        ai_calculate_step(engine, &row, &col);
        engine_step(row, col, engine);
        printf("%d,%d\n", row,col);
//        board_print(engine->board);
        fflush(stdout);
      }
      else
      {
        printf("ERROR Invalid move.\n", engine->round);
        engine_destruct(engine);
        return(1);
      }
    }
    else
    {
      printf("UNKNOWN Unknown command.\n", engine->round);
      engine_destruct(engine);
      return(1);
    }
  }
  engine_destruct(engine);
  return(0);
}
