#ifndef READ_H
# define READ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "utils.h"
# include "bsq.h"

# define BUFFER_SIZE    32
# define READ_VALIDATE	0
# define READ_CONSIDER	1

char	g_empty;
char	g_obstacle;
char	g_full;
int		g_nbr;
int     g_size[2];

int		*g_obstacle_map;

void    ft_read_file(char *name, int type_read);

#endif
