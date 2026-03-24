#ifndef MONSTERS_H
#define MONSTERS_H

#include <raylib.h>

#include "types.h"

typedef struct {
	Vector2	position;
	Vector2	path;
	Vector2	speed;
	u32	count;
	b32	active;
	f32	radius;
} Monsters;

void monsters_update(void);
void monsters_init(void);
void monsters_draw(void);

#endif /* MONSTERS_H */
