#ifndef SETTINGS_H
# define SETTINGS_H

// colors
#include "colors.h"

// window components
# define WIN_WIDTH 1600
# define WIN_HEIGHT 800
# define MAX_MAP_WIDTH 200 
# define MAX_MAP_HEIGHT 200 
# define PLAYER_COLOR COLOR_RED

// MAP
# define MAP_SIZE  100
# define BLOCK_SIZE  10 

// MATH def
//# define PI 3.14159265359
# define PI 3.14159265358979323846 

// constants distances
# define MAX_DISTANCE (double)((unsigned long long)-1)
# define REAL_MAX_DIST (WIN_HEIGHT * 5) 

// raycasting
# define RAY_WIDTH 1
# define FOV (60 * (PI / 180))
# define RAY_NUM (WIN_WIDTH / RAY_WIDTH)
# define ANGLE_INC (FOV / RAY_NUM)
# define ZOOM 1 // zoom-out with number more then 1 /// zoom-in when with numbers between 0 and 1
# define SCREEN_MID (WIN_HEIGHT / 2.0)

// movement 
# define MOV_PITCH_SPEED 600
# define PLAYER_SPEED 1

// rotation
# define ROTATION_SPEED_DEG 1 // degree
# define ROTATION_SPEED_INC (PI / 2)
# define ROTATION_SPEED_MAX (PI * 10)
# define ROTATION_SPEED_MIN (PI / 10)

// AIM (crosshair)
# define AIM_COLOR COLOR_WHITE
# define AIM_SIZE 12
# define AIM_CENTER_GAP 4 
# define AIM_THICK  2

// ---------- X11 event codes & masks ----------
#define ON_KEYDOWN      2
#define ON_KEYUP        3
#define ON_MOUSEDOWN    4
#define ON_MOUSEUP      5
#define ON_MOUSEMOVE    6
#define ON_ENTER        7
#define ON_EXPOSE       12
#define ON_DESTROY      17

#define MASK_KEYPRESS           (1L<<0)
#define MASK_KEYRELEASE         (1L<<1)
#define MASK_BUTTONPRESS        (1L<<2)
#define MASK_BUTTONRELEASE      (1L<<3)
#define MASK_POINTERMOTION      (1L<<6)
#define MASK_ENTERWINDOW        (1L<<4)

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
  KEY_SPDOWN = '-',
  KEY_MUP = 'w',
  KEY_MRIGHT = 'd',
  KEY_MDOWN = 's',
  KEY_MLEFT = 'a' 
}	t_keys;


#endif
