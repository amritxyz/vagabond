#ifndef MONSTERS_H
#define MONSTERS_H

#include <raylib.h>

#include "types.h"

typedef struct {
	Vector2 position;
	Vector2 speed;
	Vector2 acceleration;
	Vector2 path;
	b32 active;
} Monsters;

void monsters_draw(Monsters *monster);
void monsters_update(Monsters *monster);
void monsters_init(Monsters *monster);

#endif	/* MONSTERS_H */
