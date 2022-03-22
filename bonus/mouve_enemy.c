/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:05:06 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 19:36:51 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	mouve_right(t_data *data)
{
	int	x;
	int	y;

	get_index_enemy(data, &x, &y);
	if (data->map[y][x + 1] != '1')
	{
		if (data->map[y][x + 1] == '0')
		{
			data->map[y][x + 1] = 'F';
			data->map[y][x] = '0';
		}
		if (data->map[y][x + 1] == 'P')
			ft_game_msg(2, data);
		if (data->map[y][x + 1] == 'C' || data->map[y][x + 1] == 'E')
			return ;
	}
}

void	mouve_left(t_data *data)
{
	int	x;
	int	y;

	get_index_enemy(data, &x, &y);
	if (data->map[y][x - 1] != '1')
	{
		if (data->map[y][x - 1] == '0')
		{
			data->map[y][x - 1] = 'F';
			data->map[y][x] = '0';
		}
		if (data->map[y][x - 1] == 'P')
			ft_game_msg(2, data);
		if (data->map[y][x - 1] == 'C' || data->map[y][x - 1] == 'E')
			return ;
	}
}

void	ft_enemy_mouve(t_data *data)
{
	static int	r;

	if (r == 100 || r == 150 || r == 200 || r == 250)
	{
		mouve_right(data);
	}
	else if (r == 300 || r == 350 || r == 400 || r == 450)
	{
		mouve_left(data);
	}
	r++;
	if (r == 451)
		r = 0;
}
