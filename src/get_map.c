/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:12:39 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 17:21:01 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_map(char *s, t_data *data)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_gnl_strchr(s, '1') != NULL || ft_gnl_strchr(s, '0') != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == 'S' || s[i] == 'N' || s[i] == 'E' || s[i] == 'W')
				data->map.no_of_players++;
			if (s[i] != ' ' && s[i] != '0' && s[i] != '1' \
				&& s[i] != 'S' && s[i] != 'N' && s[i] != 'E' \
				&& s[i] != 'W' && s[i] != '\n')
			{
				if (data->map.isinmap == 1)
					data->eflag = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_get_map(char *s, t_data *data)
{
	static int	static_height = 0;

	if (ft_is_map(s, data) == 1)
	{
		if (data->map.frgb[0] == -1 || data->map.crgb[0] == -1 || \
			data->map.no_path == NULL || data->map.so_path == NULL || \
			data->map.ea_path == NULL || data->map.we_path == NULL)
		{
			data->eflag = 2;
		}
		static_height = static_height + 1;
	}
	data->map.map_height = static_height;
}
