/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:05:02 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/05 22:18:32 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
#define SO_LONG_H

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
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const	char *s);
char	*ft_strchr(char *s, int c);
void	ft_putstr(char *s);
int     ft_count_line(char *s);
int     ft_strcmp(char *s, char *p);
void    ft_error(void);
char    **ft_read_map(char *s, int fd);
int     ft_check_map(char **map,char *s);
int     ft_check_walles(char **map,int *k);
int     ft_check_countent(char *s,t_data map);
int	ft_mapelines(t_data *n);

#endif