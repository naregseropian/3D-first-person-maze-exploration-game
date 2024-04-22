/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:05:15 by szalazar          #+#    #+#             */
/*   Updated: 2024/02/28 14:24:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != (char)c && str[i] != '\0')
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	ptr[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (ptr);
}
