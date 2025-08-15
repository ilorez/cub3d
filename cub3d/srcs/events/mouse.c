
#include "../../includes/container.h"
#include <stdio.h>

int	ft_mouse_click(int key, int x, int y, t_data *data)
{
  (void) x, (void) y , (void) data;
	if (key == KEY_VIEW_LEFT)
      printf("left\n");
  else if (key == KEY_VIEW_RIGHT)
      printf("right\n");
	return (0);
}

int on_mouse_enter(t_data *data)
{
  if (!(data->mouse.lock))
    lock_mouse(data);
  return (0);
}

int on_mouse_move(int x, int y, t_data *d)
{
  int dx, dy;
  //printf("mouse has moved to : x=>%d,y=>%d\n", x, y);
  dx = x - WIN_WIDTH/2;
  dy = y - WIN_HEIGHT/2;
  // ignore move less then 1 by using int type
  d->mouse.dx_accum += dx; 
  d->mouse.dy_accum += dy; 
  mlx_mouse_move(d->mlx, d->win, WIN_WIDTH/2, WIN_HEIGHT/2);
  d->mouse.ignore_next_move = 1;
  return (0);
}


