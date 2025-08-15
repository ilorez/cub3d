
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
  if (!data->mouse.lock)
    lock_mouse(data);
  return (0);
}

int on_mouse_move(int x, int y, t_data *d)
{
  (void)d;
  printf("mouse has moved to : x=>%d,y=>%d\n", x, y);
  return (0);
}


