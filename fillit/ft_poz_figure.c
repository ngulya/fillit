/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poz_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 18:40:01 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/26 20:00:57 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_min_value(int *point, int n)
{
	int			min;

	min = *point;
	while (n--)
	{
		if (*point < min)
			min = *point;
		point++;
	}
	return (-min);
}

static void		ft_poz_basic(t_point *pp, int cnt)
{
	int			x_min;
	int			y_min;
	int			i;

	i = 0;
	x_min = (ft_min_value(pp->x, cnt));
	y_min = (ft_min_value(pp->y, cnt));
	while (cnt--)
	{
		pp->y[i] += y_min;
		pp->x[i] += x_min;
		i++;
	}
}

void			ft_poz_figure(t_point *pp, char *buf)
{
	int			x;
	int			y;
	int			cnt;

	cnt = 0;
	y = 0;
	while (*buf)
	{
		x = 0;
		while (*buf != '\n' && *buf)
		{
			if (*buf++ == 'x')
			{
				pp->x[cnt] = x;
				pp->y[cnt++] = y;
			}
			x++;
		}
		y++;
		buf++;
	}
	ft_poz_basic(pp, cnt);
}
