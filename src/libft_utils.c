/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:39:17 by cb                #+#    #+#             */
/*   Updated: 2024/03/02 18:46:38 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int		i;
	char	*p1;
	char	*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	i = 0;
	while ((p1[i] || p2[i]) && i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

int	ft_n_words(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**ft_split(char *s, char c)
{
	char	**pptr;
	int		i;
	int		j;
	int		k;	

	pptr = (char **)malloc(sizeof(char *) * (ft_n_words(s, c) + 1));
	if (!pptr)
		return (0);
	i = 0;
	k = 0;
	while (k < ft_n_words(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			j++;
			i++;
		}
		pptr[k] = ft_substr((s + (i - j)), 0, j);
		k++;
	}
	pptr[k] = 0;
	return (pptr);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
