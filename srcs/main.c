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

int	main(int argc, char **argv)
{
	int square_start_pos;
	int square_size;

	if (argc > 1)
	{
		ft_read_file(argv[1], READ_VALIDATE);
		ft_read_file(argv[1], READ_CONSIDER);
		square_size = ft_find_biggest_square(g_obstacle_map,
			g_size, &square_start_pos);
		ft_display_result(g_obstacle_map, g_size,
			square_start_pos, square_size);
	}
	return (0);
}
