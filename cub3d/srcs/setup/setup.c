/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
+:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:19:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 15:44:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/setup.h"

static void	ft_setup_pl_animation(t_pl_animation *pa);
static void	ft_setup_player(t_data *data, t_intcor cor, double angle);
static void	ft_setup_mouse(t_data *data);
static int	ft_create_mlx_window(t_data *data);

// print_2d_array((int **)data->map->grid, data->map->rows,
// data->map->columns);

void	ft_setup(t_data *data, t_cub_data *info)
{
	data->map = &(info->map);
	data->map_info = info;
	data->is_running = 1;
	ft_setup_mouse(data);
	ft_setup_player(data, info->pos, info->angle);
	ft_setup_pl_animation(&data->pa);
	data->lastf = 0;
	ft_create_mlx_window(data);
	load_all_textures(data);
}

static void	ft_setup_pl_animation(t_pl_animation *pa)
{
	int	i;

	pa->frame_count = ft_strlen(ANIMTION_ORDER) - 1;
	i = -1;
	while (++i < pa->frame_count)
		pa->frame_order[i] = ANIMTION_ORDER[i] - '0';
	pa->i = 0;
	pa->duration = 3000;
	pa->last_frame = ft_time_now();
	pa->is_animating = 0;
}

// speed per second
// print_t_player(data->p);
static void	ft_setup_player(t_data *data, t_intcor cor, double angle)
{
	data->p.pos.x = cor.y * BLOCK_SIZE + BLOCK_SIZE / 2.0;
	data->p.pos.y = cor.x * BLOCK_SIZE + BLOCK_SIZE / 2.0;
	data->p.angle = angle;
	data->p.size = 2;
	data->p.dx = 0;
	data->p.dy = 0;
	data->p.dh = 0;
	data->p.dv = 0;
	data->p.rs = ROTATION_SPEED_DEG * (PI);
	data->p.speed = (BLOCK_SIZE * 2) * PLAYER_SPEED;
	data->p.sp_inc = BLOCK_SIZE / 2.0;
	data->p.sp_max = BLOCK_SIZE * 10.0;
	data->p.sp_min = BLOCK_SIZE / 10.0;
	data->p.pitch = WIN_HEIGHT / 2.0;
	data->p.jump.offset = 0.0;
	data->p.jump.velocity = 0.0;
	data->p.jump.is = 0;
}

static int	ft_create_mlx_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_handel_exit(data, ERR_MLX_FIELDCON);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "PLATO");
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->map->data.img = mlx_new_image(data->mlx, MAP_SIZE, MAP_SIZE);
	data->map->data.addr = ft_mlx_get_data_addr(&data->map->data);
	data->img.addr = ft_mlx_get_data_addr(&data->img);
	data->img.w = WIN_WIDTH;
	data->img.h = WIN_HEIGHT;
	mlx_hook(data->win, 17, 0L, ft_destroy_event, data);
	mlx_hook(data->win, ON_KEYDOWN, (1L << 0), ft_key_press, data);
	mlx_hook(data->win, ON_KEYUP, (1L << 1), ft_key_release, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);
	mlx_hook(data->win, ON_MOUSEMOVE, (1L << 6), on_mouse_move, data);
	mlx_hook(data->win, ON_ENTER, (1L << 4), on_mouse_enter, data);
	mlx_mouse_hook(data->win, ft_mouse_click, data);
	return (true);
}

static void	ft_setup_mouse(t_data *data)
{
	data->mouse.ignore_next_move = 1;
	data->mouse.lock = 0;
	data->mouse.dx_accum = 0;
	data->mouse.dy_accum = 0;
}
