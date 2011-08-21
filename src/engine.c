
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"
#include "engine.h"

static void engine_init(engine_type *engine)
{
  engine->actual_player = ENGINE_BLACK;
  engine->round         = 0;
  engine->finished      = 0;
}

engine_type *engine_create(int width, int height)
{
  engine_type *res = malloc(sizeof(engine_type));
  if (res == NULL)
  {
      fprintf(stderr, "Out of memory.\n");
      exit(1);
  }
  engine_init(res);
  res->board = board_create(width, height);
  return(res);
}

void engine_destruct(engine_type *engine)
{
  board_destruct(engine->board);
  free(engine);
}

int engine_reset(engine_type *engine)
{
  engine_init(engine);
  board_clear(engine->board);
}

int engine_step(int row, int col, engine_type *engine)
{
  if (board_get_cell(engine->board, row, col) != ENGINE_EMPTY)
  {
    return(1);
  }
  else
  {
    if(board_set_cell(engine->board, row, col, engine->actual_player) == 0)
    {
      if (engine->actual_player == ENGINE_BLACK) {
        engine->actual_player = ENGINE_WHITE;
      } else {
        engine->round++;
        engine->actual_player = ENGINE_BLACK;
      }
      return(0);
    } else {
      return(1);
    }
  }
}

int engine_set(int row, int col, engine_player_type player, engine_type *engine)
{
  return(board_set_cell(engine->board, row, col, player));
}
