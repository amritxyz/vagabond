/* See LICENSE file for copyright and license details. */
#include <raylib.h>

#include "config.h"
#include "main.h"

void
begin_drawing(void)
{
	BeginDrawing();
		ClearBackground(BG_COLOR);
		close_key_q();
	EndDrawing();
}

int
close_key_q(void)
{
	if (GetKeyPressed() == KEY_Q)
		CloseWindow();
	return -1;
}

int main(void)
{
	InitWindow(WINDOW_W, WINDOW_H, TITLE);

	while (!WindowShouldClose())
		begin_drawing();
	return 0;
}
