#include "main.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_read_file(argv[1], READ_VALIDATE);
		ft_read_file(argv[1], READ_CONSIDER);
		
		// int i = 0;
		// printf("size: %d %d\n", g_size[0], g_size[1]);
		// while (g_obstacle_map[i] != END_ARRAY)
		// {
		// 	printf("obstacle %d: (%d; %d)\n", i, g_obstacle_map[i] % g_size[0], g_obstacle_map[i] / g_size[0]);
		// 	i++;
		// }

		ft_find_biggest_square(g_obstacle_map, g_size);
	}
	return (0);
}
