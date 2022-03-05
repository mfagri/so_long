/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:04:40 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/05 22:23:52 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void count_collect(t_data *data)
{
	int i;
	i = 0;
	int j;
	j = 0;
	data->c = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if(data->map[i][j] == 'C')
				data->c++;
			j++;	
		}
		i++;
	}
	return ;
}
void take_img(t_data *data)
{
	data->img_p_1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/b1.xpm",&data->a,&data->b);
	data->img_p_2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/b2.xpm", &data->a, &data->b);
	data->img_c_d = mlx_xpm_file_to_image(data->mlx_ptr, "./img/door.xpm", &data->a, &data->b);
	data->img_d = mlx_xpm_file_to_image(data->mlx_ptr, "./img/bab.xpm", &data->a, &data->b);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "./img/collect.xpm", &data->a, &data->b);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm", &data->a, &data->b);
	data->img_ground = mlx_xpm_file_to_image(data->mlx_ptr, "./img/ground.xpm", &data->a, &data->b);
	
}
void draw_map(t_data *data)
{
	int j;
	
	data->i = 0;
	while (data->map[data->i])
	{
		j = 0;
		while (data->map[data->i][j])
		{
			if(data->map[data->i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_w, j*26, data->i*26);
			if(data->map[data->i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ground, j*26, data->i*26);
			if(data->map[data->i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_c, j*26, data->i*26);
			if(data->map[data->i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_d, j*26, data->i*26);
			if(data->map[data->i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_p_1, j*26, data->i*26);
			j++;
		}
		data->i++;	
	}
	printf("%d\n",data->moves);
}
void get_index(t_data *map,int *x,int *y)
{
	*y = 0;
	while(map->map[*y])
	{
		*x = 0;
		while (map->map[*y][*x])
		{
			if(map->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void key_0(t_data *map ,int *c)
{
	int x;
	int y;
	
	get_index(map,&x,&y);
	char *line = map->map[y];
	if(*c == 0)
		map->img_d = map->img_c_d;
	if(line[x -1] == 'C')
	{
		line[x - 1] = 'P';
		line[x] = '0';
		(*c)--;
	}
	if(line[x - 1] == '0')
	{
		line[x - 1] = 'P';
		line[x] = '0';
	}
	if((line[x - 1] == 'E')&&( *c == 0))
		exit (0);
	
}
void key_2(t_data *map,int *c)
{
	int x;
	int y;
	
	get_index(map,&x,&y);
	char *line = map->map[y];
	if(*c == 0)
		map->img_d = map->img_c_d;
	if(line[x + 1] == 'C')
	{
		line[x + 1] = 'P';
		line[x] = '0';
		(*c)--;
	}
	if(line[x + 1] == '0')
	{
		line[x + 1 ] = 'P';
		line[x] = '0';
	}
	if((line[x + 1] == 'E')&&( *c == 0))
		exit (0);
}
void key_13(t_data *map,int *c)
{
		int x;
		int y;
		
		get_index(map,&x,&y);
		char *line = map->map[y];
		char *line2 = map->map[y - 1];
		if(*c == 0)
			map->img_d = map->img_c_d;
		if(line2[x] == 'C')
		{
			line2[x] = 'P';
			line[x] = '0';
			(*c)--;
		}
		if(line2[x] == '0')
		{
			line2[x] = 'P';
			line[x] = '0';
		}
		if((line2[x] == 'E')&&( *c == 0))
			exit (0);
}
void key_1(t_data *map,int *c)
{
	int x;
	int y;
	
	get_index(map,&x,&y);
	char *line = map->map[y];
	char *line2 = map->map[y + 1];
	if(*c == 0)
		map->img_d = map->img_c_d;
	if(line2[x] == 'C')
	{
		line2[x] = 'P';
		line[x] = '0';
		(*c)--;
	}
	if(line2[x] == '0')
	{
		line2[x] = 'P';
		line[x] = '0';
	}
	if((line2[x] == 'E')&&( *c == 0))
		exit (0);		
}

int take_key(int key, t_data *m)
{
		m->moves++;
		if (key == 0)
		{
		key_0(m,&m->c);
		draw_map(m);
		}
		if (key == 1)
		{
		key_1(m,&m->c);
		draw_map(m);
		}
		if (key == 2)
		{
		key_2(m,&m->c);
		draw_map(m);
		}
		if (key == 13)
		{
		 key_13(m,&m->c);
		draw_map(m);
		}
		if (key == 53)
			exit (0);
		return (key);
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
	// i = 0;
	// while(data.map[i])
	// {
	// 	printf("%s\n",data.map[i++]);
	// }
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, ft_strlen(data.map[0])*26, ft_mapelines(&data)*26, "so_long");
	take_img(&data);
	count_collect(&data);
	draw_map(&data);
	mlx_hook(data.mlx_win , 2, 0, &take_key, &data);
	//mlx_key_hook(data.mlx_win, take_key, &data);
	//mlx_loop_hook(data.mlx_ptr,take_key,&data);
	mlx_loop(data.mlx_ptr);
}