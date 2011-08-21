
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
      printf("%s %d,%d:\n", command, row,col);
      if (engine_step(row, col, engine) == 0)
      {
        printf("Round %d:\n", engine->round);
        board_print(engine->board);
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
