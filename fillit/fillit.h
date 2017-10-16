/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:37:39 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/27 18:39:29 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE 21
# define TRUE 1
# define FALSE 0
# define MAXQUEUE 26

typedef struct			s_point
{
	int					x[4];
	int					y[4];
}						t_point;

typedef struct			s_tetromino
{
	char				letter;
	t_point				pt_xy;
	struct s_tetromino	*next;
}						t_tetromino;

typedef struct			s_queue
{
	t_tetromino			*front;
	t_tetromino			*rear;
	int					cnt_fig;
}						t_queue;

void					ft_error(char const *str);
void					ft_poz_figure(t_point *pp, char *buf);
void					ft_putendl(char const *s);
void					ft_putstr(char const *s);
int						ft_queue_cnt_fig(t_queue *pq);
int						ft_add_queue(t_queue *pq, t_point x_y, char key);
int						ft_del_queue(t_queue *pq);
void					ft_putchar(char c);
void					ft_res_buf(char *buf, t_queue *pq);
int						ft_buf_update(char *buf, t_tetromino *pt, int min_sq);

void					ft_putstr(char const *s);

#endif
