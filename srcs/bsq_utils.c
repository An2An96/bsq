/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:46:53 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 16:46:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_point_inside_square(int field_size[2],
	int point, int square_lu, int square_rd)
{
	int point_x;
	int point_y;

	point_x = point % field_size[0];
	point_y = point / field_size[0];
	if (point_x >= (square_lu % field_size[0])
		&& point_x <= (square_rd % field_size[0])
		&& point_y >= (square_lu / field_size[0])
		&& point_y <= (square_rd / field_size[0]))
	{
		return (1);
	}
	return (0);
}

int	ft_reduce_square(int field_size[2],
	int obstacle_pos, int start_pos, int *end_pos)
{
	int obstacle[2];
	int start[2];
	int diff;

	obstacle[0] = obstacle_pos % field_size[0];
	obstacle[1] = obstacle_pos / field_size[0];
	start[0] = start_pos % field_size[0];
	start[1] = start_pos / field_size[0];
	if ((obstacle[0] - start[0]) > (obstacle[1] - start[1]))
		diff = obstacle[0] - start[0];
	else
		diff = obstacle[1] - start[1];
	*end_pos = (start_pos + (diff - 1)) + ((diff - 1) * field_size[0]);
	return (diff);
}

int	ft_get_offset_right(int field_size[2], int obstacle_pos)
{
	int obstacle[2];

	obstacle[0] = obstacle_pos % field_size[0];
	obstacle[1] = obstacle_pos / field_size[0];
	if (obstacle[0] + 1 < field_size[0])
		return (obstacle[0] + 1);
	else
		return (-1);
}

int	ft_get_offset_down(int field_size[2], int obstacle_pos)
{
	int obstacle[2];

	obstacle[0] = obstacle_pos % field_size[0];
	obstacle[1] = obstacle_pos / field_size[0];
	if (obstacle[1] + 1 < field_size[1])
		return ((obstacle[1] + 1) * field_size[0]);
	else
		return (-1);
}
