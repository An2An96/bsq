#ifndef BSQ_H
# define BSQ_H

# define END_ARRAY      (-65536)

//# define MIN(a, b)              a < b ? a : b
# define MIN(x, y)      (y ^ ((x ^ y) & -(x < y)))

void	ft_display_result(int *obstacle_map, int field_size[2], int biggest_start, int biggest_size);

#endif
