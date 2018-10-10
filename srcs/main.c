/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:38:23 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 18:38:24 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_clear_global(void)
{
	if (g_obstacle_map)
		free(g_obstacle_map);
	g_obstacle_map = NULL;
	g_nbr = 0;
	g_size[0] = 0;
	g_size[1] = 0;
}

int		main(int argc, char **argv)
{
	int i;
	int square_start_pos;
	int square_size;

	ft_clear_global();
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_read_file_validate(argv[i])
				&& ft_read_file_consider(argv[i]))
			{
				square_size = ft_find_biggest_square(g_obstacle_map,
					g_size, &square_start_pos);
				ft_display_result(g_obstacle_map, g_size,
					square_start_pos, square_size);
				ft_clear_global();
			}
			i++;
		}
	}
	return (0);
}
