#include "../../includes/objects.h"

int render_rect(t_img_data img, t_rect rect)
{
  t_cor cor;

	cor.x = rect.pos.x;
	while (cor.x < rect.pos.x + rect.width)
	{
		cor.y = rect.pos.y;
		while (cor.y < rect.pos.y + rect.height)
    {
      ft_put_pixel(img, cor, rect.color);
      cor.y++;
    }
		++(cor.x);
	}
	return (0);
}

