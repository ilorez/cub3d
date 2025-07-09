#include "../../includes/objects.h"

int render_rect(t_img_data img, t_rect rect)
{
  t_cor cor;

	cor.x = rect.pos.y;
	while (cor.x < rect.pos.y + rect.height)
	{
		cor.y = rect.pos.x;
		while (cor.y < rect.pos.x + rect.width)
    {
      ft_put_pixel(img, cor, rect.color);
      cor.y++;
    }
		++(cor.x);
	}
	return (0);
}

