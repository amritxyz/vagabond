#include "config.h"
#include "player.h"
#include "types.h"

void
player_update(Player *player)
{
	f32 delta = GetFrameTime();

	player->acceleration = (Vector2) {0};

	/* WASD Keys */
	if (IsKeyDown(KEY_W)) player->acceleration.y -= PLAYER_ACCEL;
	if (IsKeyDown(KEY_A)) player->acceleration.x -= PLAYER_ACCEL;
	if (IsKeyDown(KEY_S)) player->acceleration.y += PLAYER_ACCEL;
	if (IsKeyDown(KEY_D)) player->acceleration.x += PLAYER_ACCEL;

	/* Apply acceleration to velocity */
	player->velocity.x += player->acceleration.x * delta;
	player->velocity.y += player->acceleration.y * delta;

	/* Apply friction */
	player->velocity.x -= player->velocity.x * PLAYER_FRICTION * delta;
	player->velocity.y -= player->velocity.y * PLAYER_FRICTION * delta;

	/* Set max velocity */
	if (player->velocity.x > PLAYER_MAX_SPEED) player->velocity.x = PLAYER_MAX_SPEED;
	if (player->velocity.x < -PLAYER_MAX_SPEED) player->velocity.x = -PLAYER_MAX_SPEED;
	if (player->velocity.y > PLAYER_MAX_SPEED) player->velocity.y = PLAYER_MAX_SPEED;
	if (player->velocity.y < -PLAYER_MAX_SPEED) player->velocity.y = -PLAYER_MAX_SPEED;

	/* Update position with inc/dec in velocity */
	player->position.x += player->velocity.x * delta;
	player->position.y += player->velocity.y * delta;

	/* Set max rotation degree */
	if (player->rotation > 360.0f) player->rotation = 0;
	if (player->rotation < -(360.0f)) player->rotation = 0;

#if ENABLE_VIM_KEYS
	/* Vim keys */
	if (IsKeyDown(KEY_J)) player->rotation += 180 * delta;
	if (IsKeyDown(KEY_K)) player->rotation -= 180 * delta;
#endif
	/* Arrow left/right keys */
	if (IsKeyDown(KEY_RIGHT)) player->rotation += 180 * delta;
	if (IsKeyDown(KEY_LEFT)) player->rotation -= 180 * delta;

}

void
player_draw(Player player)
{
	DrawPoly(player.position, PLAYER_ENTITY_SHAPE, PLAYER_ENTITY_SIZE, player.rotation, PLAYER_ENTITY_COLOR);
}
