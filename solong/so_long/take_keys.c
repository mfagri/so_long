/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:14:04 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 12:09:43 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_0(t_data *map, int *c)
{
	int		x;
	int		y;
	char	*line;

	get_index(map, &x, &y);
	line = map->map[y];
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (line[x -1] == 'C')
	{
		line[x - 1] = 'P';
		line[x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (line[x - 1] == '0')
	{
		line[x - 1] = 'P';
		line[x] = '0';
		count_moves(map);
	}
	if (line[x - 1] == 'E' && *c == 0)
		ft_game_msg(1);
}

void	key_1(t_data *map, int *c)
{
	char	*line2;
	char	*line;
	int		x;
	int		y;

	get_index(map, &x, &y);
	line = map->map[y];
	line2 = map->map[y + 1];
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (line2[x] == 'C')
	{
		line2[x] = 'P';
		line[x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (line2[x] == '0')
	{
		line2[x] = 'P';
		line[x] = '0';
		count_moves(map);
	}
	if (line2[x] == 'E' && *c == 0)
		ft_game_msg(1);
}

void	key_2(t_data *map, int *c)
{
	char	*line;
	int		x;
	int		y;

	get_index(map, &x, &y);
	line = map->map[y];
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (line[x + 1] == 'C')
	{
		line[x + 1] = 'P';
		line[x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (line[x + 1] == '0')
	{
		line[x + 1] = 'P';
		line[x] = '0';
		count_moves(map);
	}
	if (line[x + 1] == 'E' && *c == 0)
		ft_game_msg(1);
}

void	key_13(t_data *map, int *c)
{
	char	*line;
	char	*line2;
	int		x;
	int		y;

	get_index(map, &x, &y);
	line = map->map[y];
	line2 = map->map[y - 1];
	if (*c == 0)
		map->img_d = map->img_c_d;
	if (line2[x] == 'C')
	{
		line2[x] = 'P';
		line[x] = '0';
		count_moves(map);
		(*c)--;
	}
	if (line2[x] == '0')
	{
		line2[x] = 'P';
		line[x] = '0';
		count_moves(map);
	}
	if (line2[x] == 'E' && *c == 0)
		ft_game_msg(1);
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
