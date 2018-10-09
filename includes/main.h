#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>

# define GET_CELL(field, pos)	((field[pos / 8] >> (8 - pos % 8 - 1)) & 1)

#endif
