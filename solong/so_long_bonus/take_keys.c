/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:14:04 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 13:38:50 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_0(t_data *map, int *c)
{	
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (map->map[y][x - 1] == 'C')
	{
		map->map[y][x - 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y][x - 1] == '0')
	{
		map->map[y][x - 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y][x - 1] == 'E' && *c == 0)
		ft_game_msg(1);
	if (map->map[y][x - 1] == 'F')
		ft_game_msg(2);
}

void	key_1(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (map->map[y + 1][x] == 'C')
	{
		map->map[y + 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y + 1][x] == '0')
	{
		map->map[y + 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y + 1][x] == 'E' && *c == 0)
		ft_game_msg(1);
	if (map->map[y + 1][x] == 'F')
		ft_game_msg(2);
}

void	key_2(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (map->map[y][x + 1] == 'C')
	{
		map->map[y][x + 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y][x + 1] == '0')
	{
		map->map[y][x + 1] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y][x + 1] == 'E' && *c == 0)
		ft_game_msg(1);
	if (map->map[y][x + 1] == 'F')
		ft_game_msg(2);
}

void	key_13(t_data *map, int *c)
{
	int		x;
	int		y;

	get_index(map, &x, &y);
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (map->map[y - 1][x] == 'C')
	{
		map->map[y - 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (map->map[y - 1][x] == '0')
	{
		map->map[y - 1][x] = 'P';
		map->map[y][x] = '0';
		count_moves(map);
	}
	if (map->map[y - 1][x] == 'E' && *c == 0)
		ft_game_msg(1);
	if (map->map[y - 1][x] == 'F')
		ft_game_msg(2);
}

int	take_key(int key, t_data *m)
{
	if (key == 0)
		key_0(m, &m->c);
	if (key == 1)
		key_1(m, &m->c);
	if (key == 2)
		key_2(m, &m->c);
	if (key == 13)
		key_13(m, &m->c);
	if (key == 53)
		exit (0);
	return (key);
}
