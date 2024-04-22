/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:49:50 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 19:29:04 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_space_is_closed(t_data *data, char **map, int i, int j)
{
	if (map[i][j] != ' ')
		return (0);
	if (j < ft_strlen(map[i - 1]) && map[i - 1][j] == '0')
		ft_error(data, "Error : Map not closed spacecheck up\n");
	if (j < ft_strlen(map[i + 1]) && map[i + 1][j] == '0')
		ft_error(data, "Error : Map not closed spacecheck down\n");
	if (map[i][j - 1] == '0')
		ft_error(data, "Error : Map not closed spacecheck left\n");
	if (map[i][j + 1] == '0')
		ft_error(data, "Error : Map not closed spacecheck right\n");
	return (1);
}

void	ft_is_map_closed(t_data *data, char **map, int i, int j)
{
	if (ft_space_is_closed(data, map, i, j))
		return ;
	if (ft_strlen(map[i]) > ft_strlen(map[i - 1])
		&& j >= ft_strlen(map[i - 1]))
	{
		if (map[i][j] != '1')
			ft_error(data, "Error\nMap not closed multilvl R3\n");
	}
	if (j < ft_strlen(map[i - 1]) && map[i - 1][j] == ' ')
	{
		if (map[i][j] != '1')
			ft_error(data, "Error\nMap not closed multilvl R4\n");
	}
	if (ft_strlen(map[i]) > ft_strlen(map[i + 1])
		&& j >= ft_strlen(map[i + 1]))
	{
		if (map[i][j] != '1')
			ft_error(data, "Error\nMap not closed multilvl R5\n");
	}
	if (j < ft_strlen(map[i + 1]) && map[i + 1][j] == ' ')
	{
		if (map[i][j] != '1')
			ft_error(data, "Error\nMap not closed multilvl R6\n");
	}
}

int	ft_is_ones(t_data *data, int i, int j)
{
	--j;
	while (data->map.map[i][++j])
	{
		if (data->map.map[i][j] != '1' && data->map.map[i][j] != ' ')
			ft_error(data, "Error : Map not closed border R1\n");
	}
	return (0);
}

void	set_camera(t_data *data, double d_y, double p_x, double p_y)
{
	data->ray.p_dir_y = d_y;
	data->ray.plane_x = p_x;
	data->ray.plane_y = p_y;
}

int	init_player(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == 'N')
	{
		data->ray.p_dir_x = 0.00;
		set_camera(data, -1.00, 0.66, 0.00);
	}
	else if (data->map.map[i][j] == 'S')
	{
		data->ray.p_dir_x = 0.00;
		set_camera(data, 1.00, -0.66, 0.00);
	}
	else if (data->map.map[i][j] == 'E')
	{
		data->ray.p_dir_x = 1.00;
		set_camera(data, 0.00, 0.00, 0.66);
	}
	else if (data->map.map[i][j] == 'W')
	{
		data->ray.p_dir_x = -1.00;
		set_camera(data, 0.00, 0.00, -0.66);
	}
	else
		return (1);
	data->ray.p_pos_x = (double) j + 0.5;
	data->ray.p_pos_y = (double) i + 0.5;
	return (0);
}

void	ft_is_valid_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.map_height)
	{
		j = -1;
		while (data->map.map[i][++j] && data->map.map[i][j] == ' ')
			;
		if ((i == 0 || i == data->map.map_height - 1) && !ft_is_ones(data, i, j))
			continue ;
		if (data->map.map[i][j--] != '1')
			ft_error(data, "Error\nMap leftside not closed R2\n");
		if (data->map.map[i][ft_strlen(data->map.map[i]) - 1] != '1')
			ft_error(data, "Error\nMap right not closed R2\n");
		while (data->map.map[i][++j])
		{
			init_player(data, i, j);
			ft_is_map_closed(data, data->map.map, i, j);
		}
	}
}

int	ft_check_extra(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			printf("char = %d\n", str[i]);
			return 1;
		}
		i++;
	}
	return 0;
}

void    ft_parse_map(char *infile, t_data *data)
{
	data->map.fd = open(infile, O_RDONLY);
    data->map.temp = get_next_line(data->map.fd);
    while (data->map.temp)
    {
        if (data->map.isinmap == 1 && data->map.count < data->map.map_height && ft_is_empty_line(data->map.temp) == 0)
            data->eflag = 2;
        if ((data->map.isinmap = ft_is_map(data->map.temp, data)) == 1)
        {
            data->map.count++;
            data->map.buff = ft_strjoin(data->map.buff, data->map.temp);
        }
		if (data->map.isinmap == 0 && data->map.count == data->map.map_height)
		{
			if (ft_check_extra(data->map.temp) == 1)
				data->eflag = 2;
		}
        free(data->map.temp);
        data->map.temp = NULL;
        data->map.temp = get_next_line(data->map.fd);
    }
    data->map.map = ft_split(data->map.buff, '\n');
	free(data->map.buff);
    ft_is_valid_map(data);
    close(data->map.fd);
}

void	ft_get_info(t_data *data, int fd)
{
	char	*trimmed_line;

	trimmed_line = ft_strtrim(data->map.temp, "\n");
    ft_get_colors(data->map.temp, data);
    ft_get_textures(data->map.temp, data);
    ft_get_map(trimmed_line, data);
    free(data->map.temp);
    free(trimmed_line);
    trimmed_line = NULL;
    data->map.temp = NULL;
	data->map.temp = get_next_line(fd);
}

void    ft_parse_cub(char *infile, t_data *data)
{
    int		fd;

    if ((fd = open(infile, O_RDONLY)) < 0)
	    ft_error(data, "Error\nFailed to open .cub file");
    data->map.temp = get_next_line(fd);
	if (data->map.temp == NULL)
        ft_error(data, "Error\nMap is empty");
    while (data->map.temp)
		ft_get_info(data, fd);
	if (data->map.no_of_players != 1)
		data->eflag = 2;
    if (data->eflag == 2)
        ft_error(data, "Error\nParsing error");
    close(fd);
    ft_parse_map(infile, data);
    if (data->eflag == 2)
        ft_error(data, "Error\nParsing error");
    ft_mlx(data);
}
