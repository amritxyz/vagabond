#include "config.h"
#include "player.h"
#include "types.h"

#define AVG_VELOCITY 100.0f

/* TODO: More cleaner approact to handle velocity [not linearly if possible],
 * also use math function in future to handle \`exdpy\` stuffs
 */

void
player_update(Player *player)
{
#if DEBUG_INFO == 0
	const char *position_rotation = TextFormat("Player Position X: %f, Y: %f, Rotation: %f",
							player->position.x, player->position.y, player->rotation);
	DrawText(position_rotation, (f32)DEBUG_FONT_SIZE/2, (f32)DEBUG_FONT_SIZE/3, DEBUG_FONT_SIZE, DEBUG_FG_COLOR);
#endif
	f32 delta = GetFrameTime();

	/* WASD Keys */
	if (IsKeyDown(KEY_W) && player->velocity.y < AVG_VELOCITY) {
		player->velocity.y -= 2.0f + player->hold_time * 1.5f;
		player->position.y -= 2.0f;
	}
	if (IsKeyDown(KEY_A) && player->velocity.x < AVG_VELOCITY) {
		player->velocity.x -= 2.0f + player->hold_time * 1.5f;
		player->position.x -= 2.0f;
	}
	if (IsKeyDown(KEY_S) && player->velocity.y < AVG_VELOCITY) {
		player->velocity.y += 2.0f + player->hold_time * 1.5f;
		player->position.y += 2.0f;
	}
	if (IsKeyDown(KEY_D) && player->velocity.x < AVG_VELOCITY) {
		player->velocity.x += 2.0f + player->hold_time * 1.5f;
		player->position.x += 2.0f;
	}
	if (IsKeyDown(KEY_SPACE)) {
		player->velocity.x = 0.0f;
		player->velocity.y = 0.0f;
		player->position.x -= 0.0f;
	}

	if (IsKeyUp(KEY_W) || IsKeyUp(KEY_A)) {
		if (player->velocity.x < 0 && player->velocity.x > -AVG_VELOCITY)
			player->velocity.x += delta * 10.0f;
		else
			player->velocity.x -= delta * 10.0f;
		if (player->velocity.y < 0 && player->velocity.y > -AVG_VELOCITY)
			player->velocity.y += delta * 10.0f;
		else
			player->velocity.y -= delta * 10.0f;
	}
	if (IsKeyUp(KEY_S) || IsKeyUp(KEY_D)) {
		if (player->velocity.y > 0)
			player->velocity.y -= delta * 10.0f;
		else
			player->velocity.y += delta * 10.0f;
		if (player->velocity.x > 0)
			player->velocity.x -= delta * 10.0f;
		else
			player->velocity.x += delta * 10.0f;
	}

	player->position.x += player->velocity.x * delta;
	player->position.y += player->velocity.y * delta;

	const char * velocity = TextFormat("Velocity: X: %f, Y: %f", player->velocity.x, player->velocity.y);
	DrawText(velocity, 10, 30, 20, RED);
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
