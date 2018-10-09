#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 16:01:34 by rschuppe          #+#    #+#              #
#    Updated: 2018/10/09 16:01:35 by rschuppe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=bsq
SRCS=srcs/main.c srcs/ft_putstr.c srcs/ft_validate.c srcs/ft_find_biggest_square.c
INCLUDES=includes

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I$(INCLUDES) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all