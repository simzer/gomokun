
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "board.h"

typedef enum
{
  ENGINE_EMPTY = 0,
  ENGINE_BLACK = 1,
  ENGINE_WHITE = 2
} engine_player_type;

typedef struct
{
  board_type *board;
  engine_player_type actual_player;
  int round;
  int finished;
} engine_type;

engine_type *engine_create(int width, int height);
int engine_set(int row, int col, engine_player_type player, engine_type *engine);
int engine_step(int row, int col, engine_type *engine);
int engine_reset(engine_type *engine);
void engine_destruct(engine_type *engine);

#endif
