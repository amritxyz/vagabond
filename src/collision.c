#include <raylib.h>

#include "collision.h"
#include "config.h"
#include "resume.h"

b32
collision(Monsters *monster, Player *player)
{
	b32 collision = false;
	for (u8 i = 0; i < MONSTERS_LIMIT; i++) {
		b32 check_collision_x = monster[i].position.x + MONSTERS_SIZE >= player->position.x && \
					player->position.x + PLAYER_ENTITY_SIZE >= monster[i].position.x;;

		b32 check_collision_y = monster[i].position.y + MONSTERS_SIZE >= player->position.y && \
					player->position.y + PLAYER_ENTITY_SIZE >= monster[i].position.y;;

		if (check_collision_x & check_collision_y) {
			restart_exit();
			collision = true;
		}
	}
	return collision;
}
