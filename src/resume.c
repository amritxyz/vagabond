#include <raygui.h>
#include <raylib.h>

#include "config.h"
#define RAYGUI_IMPLEMENTATION
#include "resume.h"

i32
restart_exit()
{
	GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0x444444ff);
	GuiSetStyle(DEFAULT, LINE_COLOR, 0xffffffff);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
	// GuiSetStyle(SLIDER, TEXT_PADDING, 10);
	// GuiSetStyle(DEFAULT, TEXT_PADDING, 10);
	// GuiSetStyle(CHECKBOX, TEXT_PADDING, 10);
	// GuiSetStyle(TEXTBOX, TEXT_PADDING, 20);

	int show_message_box = 0;
	if (!show_message_box) {
		int result = GuiMessageBox((Rectangle){0, 0, WINDOW_W, WINDOW_H}, "Game Finished.", "Score: ....", "Restart;Close");
		if (result > 1) {
			CloseWindow();
		} else if (result == 1){
			show_message_box = 1;
			return 0;
		}
	}
	return 1;
}
