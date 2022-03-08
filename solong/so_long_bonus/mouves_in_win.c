/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves_in_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:08:09 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/08 22:57:29 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	long int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1 ;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*b;
	long		l;

	l = n;
	len = ft_len(l);
	b = (char *)malloc((len + 1) * sizeof(char));
	if (!b)
		return (NULL);
	b[len--] = '\0';
	if (l == 0)
		b[0] = '0';
	if (l < 0)
	{
		b[0] = '-';
		l = l * -1;
	}
	while (l > 0)
	{
		b[len--] = (l % 10) + 48;
		l = l / 10;
	}
	return (b);
}

char *mouves_in_win(t_data *data)
{
    char *s;
    char *nb;
    char *movement;
    
    s = "movement : ";
    nb = ft_itoa(data->moves);
    movement = ft_strjoin(s,nb);
    return (movement);
}
