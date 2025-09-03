/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:34:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 10:16:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

// colors
# include "colors.h"

// window components
# define WIN_WIDTH 1600
# define WIN_HEIGHT 800
# define MAX_MAP_WIDTH 200
# define MAX_MAP_HEIGHT 200
# define PLAYER_COLOR 0xff0000

// MAP
# define MAP_SIZE 100
# define BLOCK_SIZE 10

// MATH def
//# define PI 3.14159265359
# define PI 3.14159265358979323846

// constants distances
# define MAX_DISTANCE 18446744073709551615.0

// raycasting
# define RAY_WIDTH 1
# define FOV 1.0471975512 // (60 * (PI / 180))
/* zoom-out with number more then 1
 zoom-in when with numbers between 0 and 1 */
# define ZOOM 2

// movement
# define MOV_PITCH_SPEED 600
# define PLAYER_SPEED 1

// rotation
# define ROTATION_SPEED_DEG 1              // degree
# define ROTATION_SPEED_INC 1.57079632679  // PI/2
# define ROTATION_SPEED_MAX 31.4159265359  // (PI * 10)
# define ROTATION_SPEED_MIN 0.314159265359 //(PI / 10)

// AIM (crosshair)
# define AIM_COLOR 0x00ff00
# define AIM_SIZE 12
# define AIM_CENTER_GAP 4
# define AIM_THICK 2

// wall horizontal and vertical colors
# define HOR_COLOR COLOR_YELLOW
# define VER_COLOR COLOR_BLUE
# define DOOR_COLOR COLOR_PINK

// ---------- X11 event codes & masks ----------
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_ENTER 7
# define ON_EXPOSE 12
# define ON_DESTROY 17

// jumping
# define JUMP_HEIGHT 50.0 // pixels
# define JUMP_SPEED 5.0   // initial upward speed
# define GRAVITY 0.1      // pulls down

//# define MASK_KEYPRESS (1L << 0)
//# define MASK_KEYRELEASE (1L << 1)
//# define MASK_BUTTONPRESS (1L << 2)
//# define MASK_BUTTONRELEASE (1L << 3)
//# define MASK_POINTERMOTION (1L << 6)
//# define MASK_ENTERWINDOW (1L << 4)

// player animation images
# define ANIMTION_ORDER "0123432343210"
# define TEX_PLA_COUNT 5
# define PLAYER_IMG_1 "./textures/egg/egg_0_back.xpm"
# define PLAYER_IMG_2 "./textures/egg/egg_1_look_middle_right.xpm"
# define PLAYER_IMG_3 "./textures/egg/egg_2_look_right.xpm"
# define PLAYER_IMG_4 "./textures/egg/egg_3_eye_middle_closed.xpm"
# define PLAYER_IMG_5 "./textures/egg/egg_4_eye_closed.xpm"
# define DOOR_IMG "./textures/laiser2.xpm"

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
	KEY_MOUSE_LEFT = 1,
	KEY_MOUSE_RIGHT = 3,
	KEY_RSUP = ']',
	KEY_RSDOWN = '[',
	KEY_SPUP = '=',
	KEY_SPUP2 = '+',
	KEY_SPDOWN = '-',
	KEY_MUP = 'w',
	KEY_MRIGHT = 'd',
	KEY_MDOWN = 's',
	KEY_MLEFT = 'a',
	KEY_SPACE = ' ',
	KEY_OPEN_DOOR = 'e',
}	t_keys;

#endif
