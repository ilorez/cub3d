#ifndef SETTINGS_H
# define SETTINGS_H

// colors
#include "colors.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 600
# define MAX_MAP_WIDTH WIN_WIDTH 
# define MAX_MAP_HEIGHT WIN_HEIGHT 
# define PLAYER_SPEED 1
# define PLAYER_COLOR COLOR_RED
//# define PI 3.14159265359
# define PI 3.14159265358979323846 
# define ROTATION_SPEED_DEG 1 // degree
# define ROTATION_SPEED_INC (PI / 2)
# define ROTATION_SPEED_MAX (PI * 10)
# define ROTATION_SPEED_MIN (PI / 10)

// raycasting
# define RAY_WIDTH 10.0
# define FOV (PI / 2) //90 * (PI / 180)
# define RAY_NUM (WIN_WIDTH / RAY_WIDTH)
# define ANGLE_INC (FOV / RAY_NUM)


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
  KEY_VIEW_RIGHT = 3, // mouse right click
  KEY_RSUP = ']', // stand for up Rotation speed
  KEY_RSDOWN = '[', // stand for down Rotation speed
  KEY_SPUP = '=',
  KEY_SPUP2 = '+',
  KEY_SPDOWN = '-'
}	t_keys;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
