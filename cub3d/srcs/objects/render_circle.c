
#include "../../includes/objects.h"

void draw_circle(t_img_data img, t_cercl c)
{
    double angle = 0;
    double angle_increment = 1.0 / c.radius; // Adjust for smoother or faster drawing
    t_cor cor;

    while (angle < 2 * M_PI) // Loop through 360 degrees
    {
        cor.x = c.center.x + (int)(c.radius * cos(angle));
        cor.y = c.center.y + (int)(c.radius * sin(angle));
        //if (cor.x >= 0 && cor.x < WIDTH && data->cor->y >= 0 && data->cor->y < HEIGHT) // Ensure the pixel is within bounds
        ft_put_pixel(img, cor, c.color);
        angle += angle_increment;
    }
}
