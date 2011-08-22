/****************************************************************************
Copyright (C) 2011 Laszlo Simon <laszlo.simon@gmail.com>

This file is part of GomoKun project.

GomoKun is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GomoKun is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GomoKun. If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/
/**
 *  \file Gomocup protokol modul.
 */

#ifndef _GCUP_H_
#define _GCUP_H_

void gcup_start(int size);
void gcup_rectstart(int width, int height);
void gcup_restart(void);
void gcup_begin(void);
void gcup_board(void );
void gcup_board_move(int x, int y, int field);
void gcup_board_done(void );
void gcup_end(void);
void gcup_about(void);
void gcup_turn(int x, int y);
void gcup_takeback(int x, int y);
void gcup_play(int x, int y);
void gcup_info_timeout_turn(int val);
void gcup_info_timeout_match(int val);
void gcup_info_max_memory(int val);
void gcup_info_time_left(int val);
void gcup_info_game_type(int val);
void gcup_info_rule(int val);
void gcup_info_evaluate(int x, int y);
void gcup_info_folder(char *path);

#endif
