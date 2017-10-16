/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 18:36:24 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/27 16:46:50 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check(char *b, int i)
{
	if ((i + 1) < 19 && b[i + 1] == '#')
	{
		b[i + 1] = 'x';
		ft_check(b, i + 1);
	}
	if ((i - 1) >= 0 && b[i - 1] == '#')
	{
		b[i - 1] = 'x';
		ft_check(b, i - 1);
	}
	if ((i + 5) < 19 && b[i + 5] == '#')
	{
		b[i + 5] = 'x';
		ft_check(b, i + 5);
	}
	if ((i - 5) >= 0 && b[i - 5] == '#')
	{
		b[i - 5] = 'x';
		ft_check(b, i - 5);
	}
}

static int		ft_check_map(char *buf, int n)
{
	int			cnt;
	int			row;

	row = 4;
	cnt = 0;
	n == 19 ? n++ : n;
	if (*(buf + --n) == '\n')
	{
		while (row)
			if (*(buf + (5 * row-- - 1)) != '\n')
				return (FALSE);
		*(buf + n) = '\0';
		while (*buf)
		{
			if (*buf != '#' && *buf != '.' && *buf != '\n')
				return (FALSE);
			if (*buf == '#')
				cnt++;
			buf++;
		}
		if (cnt == 4)
			return (TRUE);
	}
	return (FALSE);
}

static int		ft_check_figure(char *buf)
{
	int			i;
	int			cnt;

	cnt = 0;
	i = 0;
	while (buf[i] != '#')
		i++;
	buf[i] = 'x';
	ft_check(buf, i);
	while (*buf)
		if (*buf++ == 'x')
			cnt++;
	if (cnt == 4)
		return (TRUE);
	else
		return (FALSE);
}

static void		ft_read(t_queue *pq, char *f, char *buf)
{
	int			fd;
	int			n;
	t_point		x_y;
	char		key;
	int			cnt;

	key = 'A';
	cnt = 0;
	fd = open(f, O_RDONLY);
	if (fd == -1)
		ft_error("Err: open failed somwhere");
	while ((n = read(fd, buf, BUF_SIZE)) > 0)
	{
		cnt = n;
		if (!ft_check_map(buf, n) || !ft_check_figure(buf))
			ft_error("error");
		ft_poz_figure(&x_y, buf);
		if (!ft_add_queue(pq, x_y, key++))
			ft_error("error");
	}
	if (!(cnt % 21))
		ft_error("error");
	if (close(fd) == -1)
		ft_error("Err: close failed somewhere");
}

int				main(int argc, char **argv)
{
	char		buf[200];
	t_queue		pq;
	t_tetromino	*ptet;

	pq.front = NULL;
	pq.rear = NULL;
	pq.cnt_fig = 0;
	if (argc != 2)
		ft_error("Usage:. ./fillit [map.fillit]");
	ft_read(&pq, argv[--argc], buf);
	ptet = pq.front;
	if (!ptet)
		ft_error("error");
	ft_res_buf(buf, &pq);
	while (!(pq.cnt_fig == 0))
		ft_del_queue(&pq);
	return (0);
}
