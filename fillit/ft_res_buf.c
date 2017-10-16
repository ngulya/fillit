/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:31:47 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/27 16:48:08 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_min_square(int cnt_fig)
{
	int			sq;

	sq = 2;
	while (sq * sq < cnt_fig * 4)
		sq++;
	return (sq);
}

static void		ft_buf_prep(char *buf, int sq)
{
	int			x;
	int			y;
	int			cnt;

	cnt = 0;
	y = 0;
	while (y++ < sq)
	{
		x = 0;
		while (x++ < sq)
		{
			buf[cnt++] = '.';
		}
		buf[cnt++] = '\n';
	}
	buf[cnt] = '\0';
}

void			ft_res_buf(char *buf, t_queue *pq)
{
	int			flag;
	int			sq;

	sq = ft_min_square(pq->cnt_fig);
	flag = FALSE;
	while (!flag)
	{
		ft_buf_prep(buf, sq);
		flag = ft_buf_update(buf, pq->front, sq);
		sq++;
	}
	while (*buf)
		ft_putchar(*buf++);
}
