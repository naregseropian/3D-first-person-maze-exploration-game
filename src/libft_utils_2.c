/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:35:08 by cb                #+#    #+#             */
/*   Updated: 2024/02/27 20:48:16 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strdup(char *s)
{
	char	*pointer;
	size_t	str_size;
	size_t	i;

	str_size = ft_strlen(s) + 1;
	i = 0;
	pointer = (char *)malloc(sizeof(char) * str_size);
	if (pointer == NULL || str_size == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		pointer[i] = s[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

static	int	ft_start(char *s1, char *set)
{
	int	start;
	int	count;

	start = 0;
	while (s1[start] != '\0')
	{
		count = 0;
		while (set[count] != '\0')
		{
			if (s1[start] == set[count])
				break ;
			count++;
		}
		if (set[count] == '\0')
			return (start);
		start++;
	}
	return (start);
}

static int	ft_end(char *s1, char *set)
{
	int	end;
	int	count;

	end = ft_strlen(s1) - 1;
	while (end != 0)
	{
		count = 0;
		while (set[count] != '\0')
		{
			if (s1[end] == set[count])
				break ;
			count ++;
		}
		if (set[count] == '\0')
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*p;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end || s1[i] == '\0')
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (p == (NULL))
		return (NULL);
	while (start <= end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
