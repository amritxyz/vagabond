/* See LICENSE file for copyright and license details. */
#include <raylib.h>

#include "config.h"
#include "main.h"
#include "monsters.h"
#include "player.h"
#include "types.h"

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

	Player player = {
		.position = SCREEN_CENTER,
		.velocity = (Vector2){ 0 },
		.rotation = 0,
	};

	while (!WindowShouldClose()) {
		BeginDrawing();
			player_update(&player);
			monsters_update();
			ClearBackground(BG_COLOR);
			player_draw(player);
			monsters_draw();
			die();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
