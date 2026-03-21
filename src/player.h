#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

#define PLAYER_ROTATION_SPEED 360

typedef struct Player {
	Vector2 position;
	Vector2 velocity;
	float rotation;
	float hold_time;
} Player;

void player_update(Player *player);
void player_draw(Player player);

#endif	/* PLAYER_H */
