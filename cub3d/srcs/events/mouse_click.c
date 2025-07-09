
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

