/* See LICENSE file for copyright and license details. */
#pragma once

#include "monsters.h"
#include "player.h"
#include "types.h"

void init_player(Player *);
void init_monsters(Monsters *);
void debug_info(Player *);
void die(void);
