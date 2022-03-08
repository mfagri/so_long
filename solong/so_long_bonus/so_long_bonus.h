/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:05:02 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/08 20:26:03 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>

typedef struct t_data
{
	char **map;
	int c;
	int p;
	int e;
	int z;
	int i;
	int a;
	int b;
	int moves;
	void *img_ground;
	void *img_c;
	void *img_d;
	void *img_c_d;
	void *img_w;
	void *img_p_1;
	void *img_p_2;
	void *mlx_ptr;
	void *mlx_win;
}t_data;

typedef struct t_keys
{
	int key;
}t_keys;

char	*get_next_line(int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const	char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putstr(char *s);
int     ft_count_line(char *s);
int     ft_strcmp(char *s, char *p);
void    ft_error(int n);
void	ft_game_msg(int n);
char    **ft_read_map(char *s, int fd);
int     ft_check_map(char **map,char *s);
int     ft_check_walles(char **map,int *k);
int     ft_check_countent(char *s,t_data map);
int		ft_mapelines(t_data *n);
void	get_index(t_data *map,int *x,int *y);
void	take_img(t_data *data);
int		draw_map(t_data *data);
void	draw_map_2(t_data *data,int j);
void	mouve_player_2(t_data *m);
int		take_key(int key, t_data *m);
void	get_index(t_data *map,int *x,int *y);
void	count_collect(t_data *data);
void	count_moves(t_data *data);
void	key_0(t_data *map, int *c);
void	key_1(t_data *map, int *c);
void	key_2(t_data *map, int *c);
void	key_13(t_data *map,int *c);
#endif