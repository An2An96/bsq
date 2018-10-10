#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>

# include "read.h"
# include "utils.h"

//# define GET_CELL_VAL(field, pos)   ((field[pos / 8] >> (8 - pos % 8 - 1)) & 1)

int		ft_find_biggest_square(int *obstacle_map, int field_size[2]);

#endif
