#include "monsters.h"
#include "config.h"

/*
 * TODO
 * Spawn monsters in group with status `active` or `!active`
 * After passing the width or height of the screen it changes to `!active`
 * And destroyed and anoter group (array) of monsters starts to spawn.
 */
void
monsters_draw(Monsters *monster)
{

	f32 delta = GetFrameTime();

	for (u8 i = 0; i < MONSTERS_LIMIT; i++) {
		monster[i].speed.x += monster[i].acceleration.x * delta;
		monster[i].speed.y += monster[i].acceleration.y * delta;
		monster[i].position.x += monster[i].speed.x * delta;
		monster[i].position.y += monster[i].speed.y * delta;
	}
	monsters_update(monster);
}

void
monsters_update(Monsters *monster)
{

	for (u8 i = 0; i < MONSTERS_LIMIT; i++)
		DrawCircleV(monster[i].position, 20, MONSTERS_COLOR);
}

/*
 * INFO monsters_init()
 * Spawn static monster at random coordinate in the first init of the game
 */
void
monsters_init(Monsters *monster)
{
	for (u8 i = 0; i < MONSTERS_LIMIT; ++i) {
		u32 x, y;

		do {
			x = GetRandomValue(0, WINDOW_W);
		} while ( x > (WINDOW_W / 2 - 150) && x < (WINDOW_W / 2 + 150));

		do {
			y = GetRandomValue(0, WINDOW_H);
		} while ( y > (WINDOW_H / 2 - 150) && y < (WINDOW_H / 2 + 150));

		monster[i].position = (Vector2){ x, y };
		monster[i].speed    = (Vector2){ 50.0f, 50.0f };
	}
}
