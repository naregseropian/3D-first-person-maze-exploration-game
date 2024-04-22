#include "cub3D.h"

int	ft_check_argv(int ac, char **av)
{
	int	av_len;

	if (ac != 2)
	{
		printf("Please enter a file\n");
		return (1);
	}
	av_len = ft_strlen(av[1]);
	if (!av_len)
	{
		printf("Please enter a valid .cub file\n");
		return (1);
	}
	if (ft_strncmp(av[1] + av_len - 4, ".cub", 4) != 0)
	{
		printf("Please enter a valid .cub file\n");
		return (1);
	}
	return (0);
}
