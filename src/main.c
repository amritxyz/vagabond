/* See LICENSE file for copyright and license details. */
#include <raylib.h>

#include "config.h"
#include "main.h"
#include "monsters.h"
#include "player.h"
#include "types.h"
#include "debug.h"

/* Initial spawn position of player [center of the screen]. */
Vector2 SCREEN_CENTER = { (f32)WINDOW_W/2, (f32)WINDOW_H/2 };

void
die(void)
{
	if (GetKeyPressed() == KEY_Q)
		CloseWindow();
}

int main(void)
{
	/* Initial Player Position */
	InitWindow(WINDOW_W, WINDOW_H, TITLE);

	SetTargetFPS(CURRENT_FPS);

	Monsters monster[MONSTERS_LIMIT] = { 0 };
	for (u8 i = 0; i < MONSTERS_LIMIT; ++i) {
		Monsters monster[MONSTERS_LIMIT] = {
			monster[i].position = (Vector2){ 0 },
			monster[i].speed = (Vector2){ 0 },
			monster[i].acceleration = (Vector2){ MONSTERS_ACCELERATION, MONSTERS_ACCELERATION },
			monster[i].path = (Vector2){ 0 },
			monster[i].active = false
		};
	}

	Player player = {
		.position = SCREEN_CENTER,
		.velocity = (Vector2){ 0 },
		.rotation = (f32)0,
	};

	monsters_init(monster);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BG_COLOR);
			player_update(&player);
			monsters_draw(monster);
#if DEBUG_INFO
		Debug_info debug_info = {
			.player_position = player.position,
			.player_rotation = player.rotation,
			.player_velocity = player.velocity,
			.player_acceleration = player.acceleration
		};
		debug_info_show(&debug_info);
#endif
			player_draw(player);
			die();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
