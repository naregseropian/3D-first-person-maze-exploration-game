/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:21:39 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 17:50:43 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void    ft_exit(t_data *data)
// {
//     if (data->img.img_ptr)
// 		mlx_destroy_image(data->mlx.mlx_connection, data->img.img_ptr);
// 	if (data->map.t[0].img_ptr)
// 		mlx_destroy_image(data->mlx.mlx_connection, data->map.t[0].img_ptr);
// 	if (data->map.t[1].img_ptr)
// 		mlx_destroy_image(data->mlx.mlx_connection, data->map.t[1].img_ptr);
// 	if (data->map.t[2].img_ptr)
// 		mlx_destroy_image(data->mlx.mlx_connection, data->map.t[2].img_ptr);
// 	if (data->map.t[3].img_ptr)
// 		mlx_destroy_image(data->mlx.mlx_connection, data->map.t[3].img_ptr);
// 	if (data->mlx.mlx_window)
// 		mlx_destroy_window(data->mlx.mlx_connection, data->mlx.mlx_window);
//     exit(1);
// }

void	ft_error(t_data *data, char *error_msg)
{
	int	i;

	i = -1;
	printf("%s\n", error_msg);
	if (data->map.temp)
		free(data->map.temp);
	if (data->map.no_path)
		free(data->map.no_path);
	if (data->map.so_path)
		free(data->map.so_path);
	if (data->map.ea_path)
		free(data->map.ea_path);
	if (data->map.we_path)
		free(data->map.we_path);
	if (data->map.map)
	{
		while (++i < data->map.map_height)
			free(data->map.map[i]);
	}
	if (data->map.map)
		free(data->map.map);
	// ft_exit(data);
	exit(0);
}
