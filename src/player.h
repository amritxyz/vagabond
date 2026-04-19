#pragma once

#include <raylib.h>

#include "types.h"

#define PLAYER_ROTATION_SPEED 360

typedef struct Player {
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	f32 rotation;
} Player;

void player_update(Player *player);
void player_draw(Player player);
