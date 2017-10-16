/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:19:07 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/27 15:43:32 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_change_xy(t_tetromino *pt, int x, int y)
{
	int			cnt;
	int			xmin;
	int			ymin;

	xmin = 200;
	ymin = 200;
	cnt = 0;
	while (cnt != 4)
	{
		if (pt->pt_xy.x[cnt] < xmin)
			xmin = pt->pt_xy.x[cnt];
		if (pt->pt_xy.y[cnt] < ymin)
			ymin = pt->pt_xy.y[cnt];
		cnt++;
	}
	cnt = 0;
	while (cnt < 4)
	{
		pt->pt_xy.x[cnt] += (x - xmin);
		pt->pt_xy.y[cnt++] += (y - ymin);
	}
}

static void		ft_buf_reset(char *buf, t_tetromino *pt)
{
	if (*buf)
	{
		if (*buf == '\n')
			buf++;
		if (*buf == pt->letter)
			*buf = '.';
		ft_buf_reset(buf + 1, pt);
	}
}

static void		ft_buf_save(char *buf, t_tetromino *pt)
{
	int			i;
	int			x;
	int			y;

	y = 0;
	i = 0;
	while (*buf)
	{
		x = 0;
		while (*buf != '\n')
		{
			if (pt->pt_xy.x[i] == x\
				&& pt->pt_xy.y[i] == y)
			{
				*buf = pt->letter;
				i++;
			}
			buf++;
			x++;
		}
		buf++;
		y++;
	}
}

static int		ft_buf_check(char *buf, t_tetromino *pt)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	y = 0;
	while (*buf)
	{
		x = 0;
		while (*buf != '\n')
		{
			if (pt->pt_xy.x[i] == x\
				&& pt->pt_xy.y[i] == y && *buf != '.')
				return (FALSE);
			else if (pt->pt_xy.x[i] == x\
				&& pt->pt_xy.y[i] == y)
				i++;
			x++;
			buf++;
		}
		buf++;
		y++;
	}
	return (!(i < 4));
}

int				ft_buf_update(char *buf, t_tetromino *pt, int sq)
{
	int			y;
	int			x;

	y = 0;
	if (pt == NULL)
		return (TRUE);
	while (y < sq)
	{
		x = 0;
		while (x < sq)
		{
			ft_change_xy(pt, x, y);
			if (ft_buf_check(buf, pt))
			{
				ft_buf_save(buf, pt);
				if (ft_buf_update(buf, pt->next, sq))
					return (TRUE);
				ft_buf_reset(buf, pt);
			}
			x++;
		}
		y++;
	}
	return (FALSE);
}
