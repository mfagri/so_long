/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:10:54 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/19 14:52:06 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy(char *s, t_data **map)
{
	static int	f;

	if (s[(*map)->i] == 'F')
		f++;
	return (f);
}

int	ft_check_countent(char *s, t_data *map)
{
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->i = 0;
	map->z = 0;
	while (s[map->i])
	{
		if (check_all(s, map))
			return (1);
		if (s[map->i] == 'P')
			map->p++;
		if (s[map->i] == 'C')
			map->c++;
		if (s[map->i] == '0')
			map->z++;
		if (s[map->i] == 'E')
			map->e++;
		ft_enemy(s, &map);
		map->i++;
	}
	if (map->p != 1 || map->e == 0 || map->c == 0
		|| map->z == 0 || ft_enemy(s, &map) == 0)
		return (1);
	return (0);
}

int	ft_check_walles(char **map, int *k)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[0][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1')
				return (1);
			if (map[*k - 1][j] != '1')
				return (1);
			if (map[i][ft_strlen(*map) - 1] != '1')
				return (1);
			if (ft_strlen(map[i]) - 1 != ft_strlen(map[*k - 1]) - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char **map, char *s)
{
	int		i;
	int		c;
	t_data	m;

	i = 0;
	c = ft_count_line(s)+1;
	while (map[i])
		i++;
	if (i != c)
		return (1);
	if (ft_check_walles(map, &c))
		return (1);
	if (ft_check_countent(s, &m))
		return (1);
	return (0);
}

char	**ft_read_map(int fd)
{
	t_data	m;
	char	*buf;
	char	*s;

	buf = (char *)malloc(sizeof(char) * (2));
	if (!buf)
		return (NULL);
	m.c = 1;
	while (m.c > 0)
	{
		m.c = read(fd, buf, 1);
		if (m.c == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[m.c] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	m.map = ft_split(s, '\n');
	if (ft_check_map(m.map, s))
		ft_error(2);
	free(s);
	return (m.map);
}
