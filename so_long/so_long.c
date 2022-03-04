/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:04:40 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/04 21:21:42 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void coint_collect(t_data *data,int *c)
{
	int i;
	i = 0;
	int j;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if(data->map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
	return ;
}
void take_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->img_p_1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/b1.xpm",&data->a,&data->b);
	data->img_p_2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/b2.xpm", &data->a, &data->b);
	data->img_c_d = mlx_xpm_file_to_image(data->mlx_ptr, "./img/cdoor1.xpm", &data->a, &data->b);
	data->img_d = mlx_xpm_file_to_image(data->mlx_ptr, "./img/door.xpm", &data->a, &data->b);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "./img/collect.xpm", &data->a, &data->b);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm", &data->a, &data->b);
	data->img_ground = mlx_xpm_file_to_image(data->mlx_ptr, "./img/ground.xpm", &data->a, &data->b);
	data->mlx_win = mlx_new_window(data->mlx_ptr, 5*26, 13*26, "so_long");
}
void draw_map(t_data *data)
{
	int j;
	//void	*mlx_win;
	data->mlx_ptr = mlx_init();
	data->i = 0;
	// data->mlx_win = mlx_new_window(data->mlx_ptr, 5*26, 13*26, "so_long");
	while (data->map[data->i])
	{
		j = 0;
		while (data->map[data->i][j])
		{
			if(data->map[data->i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_w, data->i*26, j*26);
			if(data->map[data->i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ground, data->i*26, j*26);
			if(data->map[data->i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_c, data->i*26, j*26);
			if(data->map[data->i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_d, data->i*26, j*26);
			if(data->map[data->i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_p_1, data->i*26, j*26);
			j++;
		}
		data->i++;	
	}
	// mlx_loop(data->mlx_ptr);
}
void get_index(t_data *map,int *x,int *y)
{
	//*x = 0;
	while(map->map[*x])
	{
		while (map->map[*x][*y])
		{
			//*y = 0;
			if(map->map[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}
int take_key(int key, t_data *m)
{
	int x;
	int y;
	x = 0;
	y = 0;
	int c;
	// void *mlx_win;
	//m->mlx_win = mlx_new_window(m->mlx_ptr, 5*26, 13*26, "so_long");
	coint_collect(m,&c);
	get_index(m,&x,&y);
	if(key == 2)
	{
		printf("d");
		if(m->map[x][y+1] != '1')
		{
			if(m->map[x][y+1] == 'C')
			{
				m->map[x][y+1] = 'P';
				m->map[x][y] = '0';
				c--;
				// mlx_destroy_window(m->mlx_ptr, m->mlx_win);
				// draw_map(m);
			}
			if(m->map[x][y+1] == '0')
			{
				m->map[x][y+1] = 'P';
				m->map[x][y] = '0';
				// mlx_destroy_window(m->mlx_ptr, m->mlx_win);
				// draw_map(m);
			}
			if(m->map[x][y+1] == 'E')
			{
				if(c == 0)
					return 0;
			}
			// mlx_destroy_window(m->mlx_ptr, m->mlx_win);
			// draw_map(m);	
		}
	}
	return(0);
}
int main(int ac, char **av)
{
	int a;
	int b;
	t_data data;
	int i;
	int j = 4;
	char *s;
	int fd;
	void	*mlx_win;
	void *img;
	i = 0;
	if(ac != 2)
	{
		write(2,"Error\n",6);
		exit(1);
	}
	s = ft_strchr(av[1],'.');
	if(ft_strcmp(s,".ber") != 0)
		return 0;
	fd = open(av[1],O_RDONLY);
	if(fd == -1)
		return 0;
	s = malloc(1);
	s[0] = '\0';
	data.map = ft_read_map(s,fd);
	i = 0;
	while(data.map[i])
	{
		printf("%s\n",data.map[i++]);
	}
	take_img(&data);
	data.mlx_ptr = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx_ptr, 5*26, 13*26, "so_long");
	draw_map(&data);
	mlx_hook(data.mlx_win ,02 ,1L<<0,take_key ,&data);
	// mlx_loop_hook(data.mlx_ptr, draw_map, &data);
	// mlx_loop(data.mlx_ptr);
}