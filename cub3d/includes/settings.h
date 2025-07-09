#ifndef SETTINGS_H
# define SETTINGS_H

// colors
#include "colors.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 600
# define MAX_MAP_WIDTH WIN_WIDTH 
# define MAX_MAP_HEIGHT WIN_HEIGHT
# define MOVE_STEP_SIZE 10
# define PLAYER_COLOR COLOR_RED

// keys enums
typedef enum s_keys
{
	KEY_0 = 48,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_UP,
	KEY_RIGHT,
	KEY_DOWN,
  KEY_VIEW_LEFT = 1, // mouse left click
  KEY_VIEW_RIGHT = 3 // mouse right click
}	t_keys;

#endif
