
#include "../../includes/objects.h"

void render_filled_cercle(t_img_data img, t_cercl c)
{
    t_cor cor;
    int dx,dy;

    dy = -c.radius;
    while (dy <= c.radius)
    {
        dx = -c.radius;
        while (dx <= c.radius)
        {
            // used [(cor.x-center.x)^2 + (cor.y-center.y)^2]
            // used [(center.x + dx -center.x)^2 + (center.y + dy cor.y-center.y)^2]
            // used [(dx)^2 + (dy)^2]
            if (dx * dx + dy * dy <= c.radius * c.radius) // Inside the circle
            {
                cor.x = c.center.x + dx;
                cor.y = c.center.y + dy;
                ft_put_pixel(img, cor, c.color);
            }
            dx++;
        }
        dy++;
    }
}

void render_cercle(t_img_data img, t_cercl c)
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
