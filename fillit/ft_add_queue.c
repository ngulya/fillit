/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 19:00:51 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/27 15:05:53 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_queue_is_empty(t_queue *pq)
{
	return (pq->cnt_fig == 0);
}

static int		ft_queue_is_full(t_queue *pq)
{
	return (pq->cnt_fig == MAXQUEUE);
}

static void		ft_copy_to_tetromino(t_tetromino *pt, t_point x_y)
{
	pt->pt_xy = x_y;
}

int				ft_add_queue(t_queue *pq, t_point x_y, char key)
{
	t_tetromino	*pnew;

	if (ft_queue_is_full(pq))
		return (FALSE);
	pnew = (t_tetromino *)malloc(sizeof(t_tetromino));
	if (pnew == NULL)
	{
		ft_error("Err: problem whith memory allocation");
	}
	ft_copy_to_tetromino(pnew, x_y);
	pnew->letter = key;
	pnew->next = NULL;
	if (ft_queue_is_empty(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->cnt_fig++;
	return (TRUE);
}
