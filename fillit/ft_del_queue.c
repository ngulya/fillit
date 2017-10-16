/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:23:29 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/27 15:10:20 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_del_queue(t_queue *pq)
{
	t_tetromino *pt;

	if (pq->cnt_fig == 0)
		return (FALSE);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->cnt_fig--;
	if (pq->cnt_fig == 0)
		pq->rear = NULL;
	return (TRUE);
}
