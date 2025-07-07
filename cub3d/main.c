# include "./includes/container.h"

int	ft_create_mlx_window(t_data *data)
{
	data->mlx = mlx_init();
	//if (!data->mlx)
	//	ft_handel_exit(data, ERR_MLX_CONNECTION_FIELED);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	data->img_data.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_data.addr = ft_mlx_get_data_addr(&data->img_data);
	mlx_hook(data->win, 17, 1L, ft_destroy_event, data);
	mlx_hook(data->win, 2, 1L, ft_key_hook, data);
	//mlx_mouse_hook(data->win, ft_handle_mouse_click, data);
	//mlx_loop_hook(data->mlx, ft_loop_hook, data);
	return (true);
}
int main()
{
  t_data data;
  ft_create_mlx_window(&data);
	mlx_loop(data.mlx);
}

