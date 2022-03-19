/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:04:40 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 13:45:44 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check(int ac, char **av)
{
	char	*s;

	if (ac != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_strrchr(av[1], '.') == 0)
		ft_error(3);
	s = ft_strrchr(av[1], '.');
	if (ft_strcmp(s, ".ber") != 0)
		ft_error(3);
}

int	ft_exit(void)
{
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	ft_check(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(1);
	data.map = ft_read_map(fd);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, ft_strlen(data.map[0]) * 32, \
	ft_mapelines(&data) * 32, "so_long");
	take_img(&data);
	count_collect(&data);
	draw_map(&data);
	mlx_hook(data.mlx_win, 2, 0, &take_key, &data);
	mlx_hook(data.mlx_win, 17, 0, &ft_exit, &data);
	mlx_loop_hook(data.mlx_ptr, draw_map, &data);
	mlx_loop(data.mlx_ptr);
}
