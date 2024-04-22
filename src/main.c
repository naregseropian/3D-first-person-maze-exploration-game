/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:41:42 by cb                #+#    #+#             */
/*   Updated: 2024/03/09 17:35:57 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_init_s_data(&data);
	if (ft_check_argv(ac, av) == 0)
		ft_parse_cub(av[1], &data);
	else
		return (0);
}
