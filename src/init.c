/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:50:56 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 17:38:16 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_s_image_data(t_data *data)
{
	data->img.bpp = 32;
	data->img.llen = WIN_WIDTH;
}

void	ft_init_s_mlx_data(t_data *data)
{
	data->mlx.mlx_connection = NULL;
	data->mlx.mlx_window = NULL;
	data->mlx.window_height = WIN_HEIGHT;
	data->mlx.window_width = WIN_WIDTH;
}

void	ft_init_s_map_data(t_data *data)
{
	data->map.map = NULL;
	data->map.cub = NULL;
	data->map.temp = NULL;
	data->map.crgb[0] = -1;
	data->map.crgb[1] = -1;
	data->map.crgb[2] = -1;
	data->map.frgb[0] = -1;
	data->map.frgb[1] = -1;
	data->map.frgb[2] = -1;
	data->map.no_path = NULL;
	data->map.so_path = NULL;
	data->map.ea_path = NULL;
	data->map.we_path = NULL;
	data->map.map_height = 0;
	data->map.no_of_players = 0;
	data->map.isinmap = 0;
	data->map.right = 0;
	data->map.left = 0;
	data->map.forwards = 0;
	data->map.backwards = 0;
	data->map.rot_left = 0;
	data->map.rot_right = 0;
	data->map.fd = 0;
	data->map.count = 0;
	data->map.buff = NULL;
}

void	ft_init_s_ray_data(t_data *data)
{
	data->ray.p_dir_x = 0;
	data->ray.p_dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0;
	data->ray.p_pos_x = 0;
	data->ray.p_dir_y = 0;
	data->ray.mov_s = 0.01;
	data->ray.rot_s = 0.01;
}

void	ft_init_s_data(t_data *data)
{
	ft_init_s_mlx_data(data);
	ft_init_s_map_data(data);
	ft_init_s_image_data(data);
	ft_init_s_ray_data(data);
	data->eflag = 0;
}
