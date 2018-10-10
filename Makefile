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
SRCS=srcs/main.c srcs/utils.c srcs/ft_validate.c srcs/bsq_utils.c srcs/bsq_output.c srcs/bsq_main.c
INCLUDES=includes

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I$(INCLUDES) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all