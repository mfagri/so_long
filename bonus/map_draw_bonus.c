/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:08:01 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 14:06:57 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	take_img(t_data *data)
{
	data->img_p_1 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/v1.xpm", &data->a, &data->b);
	data->img_p_2 = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/enemy1.xpm", &data->a, &data->b);
	data->img_c_d = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/opendoor1.xpm", &data->a, &data->b);
	data->img_d = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/cdoor.xpm", &data->a, &data->b);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/collect1.xpm", &data->a, &data->b);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/Blue_1.xpm", &data->a, &data->b);
	data->img_ground = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./img/Green.xpm", &data->a, &data->b);
}

void	mouve_player_2(t_data *m)
{
	static int	i;
	static int	j;

	if (i % 10 == 0)
	{
		if (j)
		{
			j = 0;
			m->img_p_1 = mlx_xpm_file_to_image(m->mlx_ptr, \
				"./img/v1.xpm", &m->a, &m->b);
			m->img_p_2 = mlx_xpm_file_to_image(m->mlx_ptr, \
				"./img/enemy1.xpm", &m->a, &m->b);
		}
		else
		{
			j = 1;
			m->img_p_1 = mlx_xpm_file_to_image(m->mlx_ptr, \
				"./img/v2.xpm", &m->a, &m->b);
			m->img_p_2 = mlx_xpm_file_to_image(m->mlx_ptr, \
				"./img/enemy2.xpm", &m->a, &m->b);
		}
	}
	if (i == 100000)
		i = 0;
	i++;
}

void	draw_map_2(t_data *data, int j)
{
	mouves_in_win(data);
	if (data->map[data->i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, \
			data->mlx_win, data->img_w, j * 32, data->i * 32);
	if (data->map[data->i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, \
			data->mlx_win, data->img_ground, j * 32, data->i * 32);
	if (data->map[data->i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, \
			data->mlx_win, data->img_c, j * 32, data->i * 32);
	if (data->map[data->i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, \
			data->mlx_win, data->img_d, j * 32, data->i * 32);
	if (data->map[data->i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, \
			data->mlx_win, data->img_p_1, j * 32, data->i * 32);
	if (data->map[data->i][j] == 'F')
		mlx_put_image_to_window(data->mlx_ptr, \
			data->mlx_win, data->img_p_2, j * 32, data->i * 32);
}

int	draw_map(t_data *data)
{
	int	j;

	data->i = 0;
	mouve_player_2(data);
	ft_enemy_mouve(data);
	while (data->map[data->i])
	{
		j = 0;
		while (data->map[data->i][j])
		{
			draw_map_2(data, j);
			j++;
		}
		data->i++;
	}
	return (0);
}
