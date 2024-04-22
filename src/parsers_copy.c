/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:49:50 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 16:49:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3D.h"

// int		ft_depart(char c, t_data *data, int i, int j)
// {
// 	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 	{
// 		if (data->map_data.player != 'x')
// 			data->eflag = 2;
// 		data->map_data.player = c;
// 		data->map_data.dx = i;
// 		data->map_data.dy = j;
// 		return (1);
// 	}
// 	return (0);
// }

// int		ft_copy_map(char *str, t_data *data)
// {
// 	static int	i = 0;
// 	int			j;

// 	j = 0;
// 	data->map_data.map[i] = NULL;
// 	if (!(data->map_data.map[i] = malloc(sizeof(char) * data->map_data.map_width + 1)))
// 		return (0);
// 	while (str[j] != '\0')
// 	{
// 		if (ft_depart(str[j], data, i, j) == 1)
// 			data->map_data.map[i][j] = '0';
// 		else if (str[j] == ' ')
// 			data->map_data.map[i][j] = '1';
// 		else
// 			data->map_data.map[i][j] = str[j];
// 		j++;
// 	}
// 	while (j <= (data->map_data.map_width - 1))
// 	{
// 		data->map_data.map[i][j] = '1';
// 		j++;
// 	}
// 	data->map_data.map[i][j] = '\0';
// 	i++;
// 	return (0);
// }

// void    ft_parse_map(char *infile, t_data *data)
// {
//     int     fd;
//     int     count;

//     count = 0;
//     fd = open(infile, O_RDONLY);
//     data->map_data.map = malloc(sizeof(char*) * data->map_data.map_height);
//     if (!data->map_data.map)
//         ft_error(data, "Error\nFailed to malloc map\n");
//     data->map_data.temp = get_next_line(fd);
//     while (data->map_data.temp)
//     {
//         if (data->map_data.isinmap == 1 && count < data->map_data.map_height && ft_is_empty_line(data->map_data.temp) == 0)
//             data->eflag = 2;
//         if ((data->map_data.isinmap = ft_is_map(data->map_data.temp, data)) == 1)
//         {
//             count++;
//             ft_copy_map(data->map_data.temp, data);
//         }
//         free(data->map_data.temp);
//         data->map_data.temp = NULL;
//         data->map_data.temp = get_next_line(fd);
//     }
//     close(fd);
// }

// void    ft_parse_cub(char *infile, t_data *data)
// {
//     int		fd;
//     char    *trimmed_line;

//     if ((fd = open(infile, O_RDONLY)) < 0)
// 	    ft_error(data, "Error\nFailed to open .cub file");
//     data->map_data.temp = get_next_line(fd);
// 	if (data->map_data.temp == NULL)
//         ft_error(data, "Error\nMap is empty");
//     while (data->map_data.temp)
//     {
//         trimmed_line = ft_strtrim(data->map_data.temp, "\n");
//         ft_get_colors(data->map_data.temp, data);
//         ft_get_textures(data->map_data.temp, data);
//         ft_get_map(trimmed_line, data);
//         free(data->map_data.temp);
//         free(trimmed_line);
//         trimmed_line = NULL;
//         data->map_data.temp = NULL;
// 		data->map_data.temp = get_next_line(fd);
//     }
//     if (data->eflag == 2)
//         ft_error(data, "Error\nParsing error");
//     close(fd);
//     ft_parse_map(infile, data);
//     if (data->eflag == 2)
//         ft_error(data, "Error\nParsing error");
//     ft_mlx(data);
// }
