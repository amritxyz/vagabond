#include "debug.h"
#include <raylib.h>

#if DEBUG_INFO
void
debug_info_show(Debug_info *debug_info)
{
	const char *debug_info_text = TextFormat("Player Position X: %f, Y: %f\nRotation: %f\nVelocity: %f\nAccleration X: %f, Y: %f",
							debug_info->player_position.x, debug_info->player_position.y,
							debug_info->player_rotation,
							debug_info->player_velocity,
							debug_info->player_acceleration.x, debug_info->player_acceleration.y);
	DrawText(debug_info_text, (f32)DEBUG_FONT_SIZE/2, (f32)DEBUG_FONT_SIZE/3, DEBUG_FONT_SIZE, DEBUG_FG_COLOR_PLAYER);
}
#endif
