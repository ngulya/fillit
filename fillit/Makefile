#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngulya <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 17:01:03 by ngulya            #+#    #+#              #
#    Updated: 2016/12/27 18:06:22 by ngulya           ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fillit
SRC		=	ft_add_queue.c\
			ft_buf_update.c\
			ft_error.c\
			ft_poz_figure.c\
			ft_del_queue.c\
			ft_res_buf.c\
			ft_putchar.c\
			ft_putendl.c\
			ft_putstr.c\
			main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	gcc -I $(FLAGS)  $(OBJ) -o $(NAME)

%.o: %.c
	gcc -I fillit.h -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all