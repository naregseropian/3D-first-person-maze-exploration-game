/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:39:34 by cb                #+#    #+#             */
/*   Updated: 2024/03/03 17:34:40 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_isspace(int c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

int	ft_count_commas(char *str)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			commas++;
		i++;
	}
	return (commas);
}

int	ft_isdigit(int c)
{
	size_t	arg;

	arg = c;
	if ((arg >= '0' && arg <= '9') || arg == ' ')
		return (1);
	return (0);
}

int ft_isdigit_str(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_isspace_str(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isspace(str[i]) == 1)
            return (0);
        i++;
    }
    return (1);
}

int ft_count_num(char *str)
{
    int i = 0;
    int count = 1;

    while (str[i] == ' ')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i] && str[i] != ' ')
        i++;
    if (str[i] == ' ')
    {
        while (str[i] == ' ')
            i++;
        if (str[i] >= '0' && str[i] <= '9')
        {
            count++;
            return count;
        }
        if (str[i] == '\0')
            return count;
    }
    return count;
}

int		ft_is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
