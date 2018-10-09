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
SRCS=srcs/main.c srcs/ft_find_biggest_square.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)