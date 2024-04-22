/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:39:21 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 16:49:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_texture_file(char *infile, t_data *data)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		data->eflag = 2;
	else
		close(fd);
}

char	*ft_get_path_texture(char *str, char *texture, t_data *data)
{
	if (texture != NULL)
	{
		free(texture);
		data->eflag = 2;
	}
	ft_check_texture_file(str, data);
	return (str);
}

void	ft_get_textures(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O')
		data->map.no_path = ft_get_path_texture(ft_strtrim(line + 2, FAT), \
			data->map.no_path, data);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		data->map.so_path = ft_get_path_texture(ft_strtrim(line + 2, FAT), \
			data->map.so_path, data);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		data->map.ea_path = ft_get_path_texture(ft_strtrim(line + 2, FAT), \
			data->map.ea_path, data);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		data->map.we_path = ft_get_path_texture(ft_strtrim(line + 2, FAT), \
			data->map.we_path, data);
}
