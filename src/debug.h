#pragma once

#include <raylib.h>

#include "config.h"
#include "types.h"

#if DEBUG_INFO
/* TODO Also for monsters if possible */
typedef struct {
	Vector2 player_position;
	f32 player_rotation;
	Vector2 player_velocity;
	Vector2 player_acceleration;
} Debug_info ;

void debug_info_show(Debug_info *);
#endif
