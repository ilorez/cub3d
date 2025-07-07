#ifndef SETTINGS_H
# define SETTINGS_H

# define WIDTH 1000
# define HEIGHT 700
# define MOVE_STEP_SIZE 10

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
  KEY_VIEW_LEFT = 1, // left click
  KEY_VIEW_RIGHT = 3 // right click
}	t_keys;

#endif
