#pragma once

#include <raylib.h>

#include "monsters.h"
#include "player.h"
#include "types.h"

typedef struct {
	u32 x, y;
	f32 radius;
} Collision;

b32 collision(Monsters *, Player *);
