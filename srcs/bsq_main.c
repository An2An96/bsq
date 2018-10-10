/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_biggest_square.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:59:16 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/09 15:59:17 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_obstacles(int start_pos,
	int *diagonal, int biggest[2], int *obstacle_idx)
{
	int i;
	int square_size;

	i = 0;
	biggest[BSQ_SIZE] = -1;
	while (g_obstacle_map[i] != END_ARRAY)
	{
		if (ft_is_point_inside_square(g_size,
			g_obstacle_map[i], start_pos, *diagonal))
		{
			square_size = ft_reduce_square(g_size,
				g_obstacle_map[i], start_pos, &(*diagonal));
			if (biggest[BSQ_SIZE] == -1 || square_size < biggest[BSQ_SIZE])
			{
				biggest[BSQ_SIZE] = square_size;
				biggest[BSQ_START] = start_pos;
			}
			*obstacle_idx = i;
		}
		i++;
	}
	return (square_size);
}

void	ft_find_next_obstacle(int *start_pos, int obstacle_idx[2])
{
	int i;

	if (obstacle_idx[1] != -1)
	{
		*start_pos = (*start_pos % g_size[0])
			+ (g_size[0] * (g_obstacle_map[obstacle_idx[0]] / g_size[0] + 1));
		obstacle_idx[0] = obstacle_idx[1];
	}
	else
	{
		i = (obstacle_idx[0] >= 0 ? (obstacle_idx[0] + 1) : 0) - 1;
		while (++i >= -1 && g_obstacle_map[i] != END_ARRAY)
		{
			if ((g_obstacle_map[i] % g_size[0] >= *start_pos % g_size[0])
				&& (g_obstacle_map[i] / g_size[0]
				> g_obstacle_map[obstacle_idx[0]] / g_size[0]))
			{
				obstacle_idx[0] = i;
				return ;
			}
		}
		obstacle_idx[0] = -1;
	}
}

void	ft_check_biggest(int start_pos, int square_size,
	int biggest[2], int biggest_tmp[2])
{
	if (biggest_tmp[BSQ_SIZE] == -1)
	{
		biggest_tmp[BSQ_SIZE] = square_size;
		biggest_tmp[BSQ_START] = start_pos;
	}
	if (biggest[BSQ_SIZE] == -1 || biggest_tmp[BSQ_SIZE] > biggest[BSQ_SIZE])
	{
		biggest[BSQ_SIZE] = biggest_tmp[BSQ_SIZE];
		biggest[BSQ_START] = biggest_tmp[BSQ_START];
	}
}

int		ft_is_biggest_square(int *s_pos)
{
	int square_size;
	int diagonal;
	int biggest_tmp[2];
	int biggest[2];
	int obstacle_idx[2];

	obstacle_idx[0] = -2;
	biggest[BSQ_SIZE] = -1;
	biggest_tmp[BSQ_SIZE] = -1;
	while (obstacle_idx[0] != -1)
	{
		obstacle_idx[1] = -1;
		if ((square_size = MIN(g_size[0] - (*s_pos % g_size[0]),
			g_size[1] - (*s_pos / g_size[0]))) <= 0)
			break ;
		diagonal = *s_pos + square_size - 1 + (g_size[0] * (square_size - 1));
		ft_check_obstacles(*s_pos, &diagonal, biggest_tmp, &obstacle_idx[1]);
		ft_check_biggest(*s_pos, square_size, biggest, biggest_tmp);
		ft_find_next_obstacle(&(*s_pos), obstacle_idx);
	}
	*s_pos = biggest[BSQ_START];
	return (biggest[BSQ_SIZE]);
}

int		ft_find_biggest_square(int *obstacle_map,
	int field_size[2], int *biggest_start)
{
	int i;
	int cur_pos;
	int cur_size;
	int biggest_size;

	i = -1;
	cur_size = 0;
	cur_pos = 0;
	biggest_size = ft_is_biggest_square(&cur_pos);
	*biggest_start = cur_pos;
	while (++i >= 0 && obstacle_map[i] != END_ARRAY)
	{
		if ((cur_pos = ft_get_offset_right(field_size, obstacle_map[i])) != -1)
			cur_size = ft_is_biggest_square(&cur_pos);
		ft_set_biggest(&biggest_size, &(*biggest_start), cur_pos, cur_size);
		if ((cur_pos = ft_get_offset_down(field_size, obstacle_map[i])) != -1)
			cur_size = ft_is_biggest_square(&cur_pos);
		ft_set_biggest(&biggest_size, &(*biggest_start), cur_pos, cur_size);
	}
	return (biggest_size);
}
