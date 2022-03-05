/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utls1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:14:52 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/04 22:35:18 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_count_line(char *s)
{
	int i;
	int c;
	i = 0;
	c = 0;
	while(s[i])
	{
		if(s[i] == '\n')
			c++;
		i++;
	}
	return(c);
}

int	ft_mapelines(t_data *n)
{
	int	i;

	i = 0;
	while (n->map[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s, char *p)
{
	int	i;

	i = 0;
	while (s[i] && p[i] && s[i] == p[i])
		i++;
	return (s[i] - p[i]);
}

void ft_error(void)
{
		write(1, "Error\n", 6);
		exit(1);
}
