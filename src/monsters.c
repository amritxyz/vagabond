#include <math.h>
#include <raylib.h>

#include "config.h"
#include "monsters.h"
#include "types.h"

Monsters monsters_group_one[MONSTER_MAX_COUNT] = { 0 };
Monsters monsters_group_two[MONSTER_MAX_COUNT] = { 0 };

void
monsters_update()
{
#ifdef DEBUG_INFO
	const char *debug_info = TextFormat("Monster Group One Position X: %f, Y: %f\nMonster Group Two Position X: %f, Y: %f",
						monsters_group_one->position.x, monsters_group_one->position.y,
						monsters_group_two->position.x, monsters_group_two->position.y);
	DrawText(debug_info, 10, (WINDOW_H-50), DEBUG_FONT_SIZE, DEBUG_FG_COLOR);
#endif
	monsters_init();
	monsters_draw();
}

void
monsters_init(void)
{
	b32 correct_range = false;

	for (u32 i = 0; i < MONSTER_MAX_COUNT; ++i) {
		u32 position_x = GetRandomValue(0, WINDOW_W);

		while (!correct_range) {
			if (position_x > (WINDOW_W / 2 - 150) && position_x < (WINDOW_H / 2 + 150))
				position_x = GetRandomValue(0, WINDOW_W);
			else correct_range = true;
		}
		correct_range = false;

		u32 position_y = GetRandomValue(0, WINDOW_H);

		while (!correct_range) {
			if (position_y > (WINDOW_H / 2) && position_y < (WINDOW_W / 2))
				position_y = GetRandomValue(0, WINDOW_H);
			else correct_range = true;
		}

		correct_range = false;
		u32 velocity_x = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);
		u32 velocity_y = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);

		while (!correct_range) {
			if (velocity_x == 0 && velocity_y == 0) {
				velocity_x = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);
				velocity_y = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);
			} else {
				correct_range = true;
			}
		}
		monsters_group_one[i].position = (Vector2) {position_x, position_y}; 
		monsters_group_one[i].speed    = (Vector2) {velocity_x, velocity_y};
		monsters_group_one[i].radius   = (f32)MONSTER_RADIUS;
		monsters_group_one[i].active   = true;
	}

	correct_range = false;
	for (u32 i = 0; i < MONSTER_MAX_COUNT; ++i) {
		u32 position_x = GetRandomValue(0, WINDOW_W);

		while (!correct_range) {
			if (position_x > (WINDOW_W / 2 - 150) && position_x < (WINDOW_H / 2 + 150))
				position_x = GetRandomValue(0, WINDOW_W);
			else correct_range = true;
		}
		correct_range = false;

		u32 position_y = GetRandomValue(0, WINDOW_H);

		while (!correct_range) {
			if (position_y > (WINDOW_H / 2) && position_y < (WINDOW_W / 2))
				position_y = GetRandomValue(0, WINDOW_H);
			else correct_range = true;
		}

		correct_range = false;
		u32 velocity_x = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);
		u32 velocity_y = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);

		while (!correct_range) {
			if (velocity_x == 0 && velocity_y == 0) {
				velocity_x = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);
				velocity_y = GetRandomValue(-MONSTER_SPEED, MONSTER_SPEED);
			} else {
				correct_range = true;
			}
		}
		monsters_group_two[i].position = (Vector2) {position_x, position_y}; 
		monsters_group_two[i].speed    = (Vector2) {velocity_x, velocity_y};
		monsters_group_two[i].radius   = (f32)MONSTER_RADIUS;
		monsters_group_two[i].active   = true;
	}
}

void
monsters_draw(void)
{
	for (i32 i = 0; i < MONSTER_MAX_COUNT; ++i)
		if (monsters_group_one[i].active) {
			monsters_group_one[i].position.x += monsters_group_one[i].speed.x;
			monsters_group_one[i].position.y += monsters_group_one[i].speed.y;
			monsters_group_one[i].position = (Vector2) {monsters_group_one[i].position.x, monsters_group_one[i].position.y}; 
			DrawCircleV(monsters_group_one[i].position, MONSTER_RADIUS, RED);
		}
	for (i32 i = 0; i < MONSTER_MAX_COUNT; ++i)
		if (monsters_group_two[i].active) {
			monsters_group_two[i].position.x += monsters_group_one[i].speed.x;
			monsters_group_two[i].position.y += monsters_group_one[i].speed.y;
			monsters_group_one[i].position = (Vector2) {monsters_group_one[i].position.x, monsters_group_one[i].position.y}; 
			DrawCircleV(monsters_group_two[i].position, MONSTER_RADIUS, RED);
		}
}
