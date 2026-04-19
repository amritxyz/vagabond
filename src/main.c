/* See LICENSE file for copyright and license details. */
#include <raylib.h>

#include "collision.h"
#include "config.h"
#include "debug.h"
#include "main.h"
#include "monsters.h"
#include "player.h"
#include "resume.h"
#include "types.h"

/* Initial spawn position of player [center of the screen]. */
Vector2 SCREEN_CENTER = { (f32)WINDOW_W/2, (f32)WINDOW_H/2 };

void
init_player(Player *player)
{
	player->position = SCREEN_CENTER;
	player->velocity = (Vector2){ 0 };
	player->rotation = (f32)0;
}

void
init_monsters(Monsters *monsters)
{
	for (u8 i = 0; i < MONSTERS_LIMIT; ++i) {
		monsters[i] = (Monsters) {
			.sposition = (Vector2){ 0 },
			.position = (Vector2){ 0 },
			.speed = (Vector2){ 0 },
			.acceleration = (Vector2){ MONSTERS_ACCELERATION, MONSTERS_ACCELERATION },
			.direction = (Vector2){ 0 },
			.active = false
		};
	}
}

#if DEBUG_INFO
void
debug_info(Player *player)
{
		Debug_info debug_info = {
			.player_position = player->position,
			.player_rotation = player->rotation,
			.player_velocity = player->velocity,
			.player_acceleration = player->acceleration
		};
		debug_info_show(&debug_info);
}
#endif

void
collision_detect(Monsters *monster, Player *player, b32 *monster_init_bool)
{
	if (!collision(monster, player)) {
		player_update(player);
		monsters_update(monster);
		player_draw(*player);
		monster_init_bool = false;
	} else if (!restart_exit()) {
		if (!monster_init_bool)
			monsters_init(monster);
		player->position = SCREEN_CENTER;
		player_update(player);
		monsters_update(monster);
		player_draw(*player);
	}
}

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

	Monsters monsters[MONSTERS_LIMIT];
	init_monsters(monsters);

	Player player;
	init_player(&player);

	monsters_init(monsters);
	b32 monster_init_bool = true;

	while (!WindowShouldClose()) {
		BeginDrawing();

#if DEBUG_INFO
		/* INFO change `DEBUG_INFO` to 1 or 0 to enable or disable debug
		   info respectively */
		debug_info(&player);
#endif
		ClearBackground(BG_COLOR);
		collision_detect(monsters, &player, &monster_init_bool);
		die();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
