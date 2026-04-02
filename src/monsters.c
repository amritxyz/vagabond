#include "collision.h"
#include "monsters.h"
#include "config.h"

void
monsters_draw(Monsters *monster)
{
	f32 delta = GetFrameTime();

	/* TODO Collision detection */
	for (u8 i = 0; i < MONSTERS_LIMIT; i++) {
		if (monster[i].sposition.x < 300 && monster[i].sposition.y < 200) {
			/* top left */
			monster[i].speed.x += monster[i].acceleration.x * delta;
			monster[i].speed.y += monster[i].acceleration.y * delta;
			monster[i].position.x += monster[i].speed.x * delta;
			monster[i].position.y += monster[i].speed.y * delta;
		} else if (monster[i].sposition.x < 300 && monster[i].sposition.y > 600) {
			/* bottom left */
			monster[i].speed.x += monster[i].acceleration.x * delta;
			monster[i].speed.y += monster[i].acceleration.y * delta;
			monster[i].position.x += monster[i].speed.x * delta;
			monster[i].position.y -= monster[i].speed.y * delta;
		} else if (monster[i].sposition.x > 800 && monster[i].sposition.y < 300){
			/* top right */
			monster[i].speed.x += monster[i].acceleration.x * delta;
			monster[i].speed.y += monster[i].acceleration.y * delta;
			monster[i].position.x -= monster[i].speed.x * delta;
			monster[i].position.y += monster[i].speed.y * delta;
		} else if (monster[i].sposition.x > 800 && monster[i].sposition.y > 500){
			/* bottom right */
			monster[i].speed.x += monster[i].acceleration.x * delta;
			monster[i].speed.y += monster[i].acceleration.y * delta;
			monster[i].position.x -= monster[i].speed.x * delta;
			monster[i].position.y -= monster[i].speed.y * delta;
		} else if (monster[i].sposition.y < 300) {
			/* top center */
			monster[i].speed.x += monster[i].acceleration.x * delta;
			monster[i].speed.y += monster[i].acceleration.y * delta;
			monster[i].position.y += monster[i].speed.y * delta;
		} else {
			/* bottom center */
			monster[i].speed.x += monster[i].acceleration.x * delta;
			monster[i].speed.y += monster[i].acceleration.y * delta;
			monster[i].position.y -= monster[i].speed.y * delta;
		}
	}
	monsters_update(monster);
}

void
monsters_update(Monsters *monster)
{
	for (u8 i = 0; i < MONSTERS_LIMIT; i++)
		DrawCircleV(monster[i].position, 20, MONSTERS_COLOR);
}

/* INFO monsters_init()
 * Spawn static monster at random coordinate in the first init of the game */
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
		monster[i].sposition = (Vector2) {x, y};
		monster[i].speed    = (Vector2){ 50.0f, 50.0f };
	}
}
