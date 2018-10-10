/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:17:55 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 16:17:55 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_char(int is_obstacle, int is_square)
{
	if (is_obstacle)
		ft_putchar(g_obstacle);
	else if (is_square)
		ft_putchar(g_full);
	else
		ft_putchar(g_empty);
}

void	ft_display_result(int *obstacle_map,
	int field_size[2], int biggest_start, int biggest_size)
{
	int x;
	int y;
	int obs_idx;
	int square_min[2];
	int square_max[2];

	y = -1;
	obs_idx = 0;
	square_min[0] = biggest_start % field_size[0];
	square_min[1] = biggest_start / field_size[0];
	square_max[0] = square_min[0] + biggest_size - 1;
	square_max[1] = square_min[1] + biggest_size - 1;
	while (++y >= 0 && y < field_size[1])
	{
		x = -1;
		while (++x >= 0 && x < field_size[0])
		{
			ft_print_char((obstacle_map[obs_idx] == y * field_size[0] + x
				&& ++obs_idx),
				(x >= square_min[0] && x <= square_max[0]
				&& y >= square_min[1] && y <= square_max[1]));
		}
		ft_putchar('\n');
	}
}
