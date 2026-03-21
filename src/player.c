#include "config.h"
#include "player.h"
#include "types.h"

void
player_update(Player *player)
{
#if DEBUG_INFO == 0
	const char *position_rotation = TextFormat("Player Position X: %f, Y: %f, Rotation: %f",
							player->position.x, player->position.y, player->rotation);
	DrawText(position_rotation, (f32)DEBUG_FONT_SIZE/2, (f32)DEBUG_FONT_SIZE/3, DEBUG_FONT_SIZE, DEBUG_FG_COLOR);
#endif
	/* WASD Keys */
	if (IsKeyDown(KEY_W))
		player->position.y -= 2.0f;
	if (IsKeyDown(KEY_A))
		player->position.x -= 2.0f;
	if (IsKeyDown(KEY_S))
		player->position.y += 2.0f;
	if (IsKeyDown(KEY_D))
		player->position.x += 2.0f;
#if VIM_MODE == 0
	/* Vim keys */
	if (IsKeyDown(KEY_J))
		player->rotation += 3.0f;
	else if (IsKeyDown(KEY_K))
		player->rotation -= 3.0f;
#endif
	/* Arrow left/right keys */
	if (IsKeyDown(KEY_RIGHT))
		player->rotation += 3.0f;
	else if (IsKeyDown(KEY_LEFT))
		player->rotation -= 3.0f;
}

void
player_draw(Player player)
{
	DrawPoly(player.position, 3, 50, player.rotation, BLACK);
}
