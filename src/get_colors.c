/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:05:23 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 16:49:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_save_rgb(char *line, int *arr, t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (j < 3)
	{
		while (line[i] != '\n' && line[i] != ',')
			i++;
		str = ft_substr(line, 0, i);
		if (ft_isdigit_str(str) == 1 && ft_count_num(str) == 1)
			arr[j] = ft_atoi(str);
		else
			data->eflag = 2;
		free(str);
		if (arr[j] > MAX_RGB || arr[j] < MIN_RGB)
			data->eflag = 2;
		line += i + 1;
		i = 0;
		j++;
	}
}

void	ft_get_colors(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == 'F')
	{
		i = 1;
		if (data->map.frgb[0] != -1)
			data->eflag = 2;
		if (ft_count_commas(line) != 2)
			data->eflag = 2;
		if (data->eflag == 0)
			ft_save_rgb(line + i, data->map.frgb, data);
	}
	else if (line[i] == 'C')
	{
		i = 1;
		if (data->map.crgb[0] != -1)
			data->eflag = 2;
		if (ft_count_commas(line) != 2)
			data->eflag = 2;
		if (data->eflag == 0)
			ft_save_rgb(line + i, data->map.crgb, data);
	}
}
