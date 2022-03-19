/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utls2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:21:33 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 19:27:22 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_index_enemy(t_data *map, int *x, int *y)
{
	*y = 0;
	while (map->map[*y])
	{
		*x = 0;
		while (map->map[*y][*x])
		{
			if (map->map[*y][*x] == 'F')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	get_index(t_data *map, int *x, int *y)
{
	*y = 0;
	while (map->map[*y])
	{
		*x = 0;
		while (map->map[*y][*x])
		{
			if (map->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	count_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->c = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c++;
			j++;
		}
		i++;
	}
	return ;
}

void	count_moves(t_data *data)
{
	int			x;
	int			y;
	static int	n;
	static int	w;

	get_index(data, &x, &y);
	if (n != x || w != y)
	{
		data->moves++;
		n = x;
		w = y;
	}
}

void	ft_game_msg(int n, t_data *data)
{
	if (n == 1)
	{
		write(1, "you win !\n", 11);
		ft_free_map(data);
		exit (0);
	}
	if (n == 2)
	{
		write(1, "game over !\n", 13);
		ft_free_map(data);
		exit (0);
	}
	ft_free_map(data);
}
