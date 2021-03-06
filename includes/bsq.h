/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:54:09 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 16:54:10 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "utils.h"

# define END_ARRAY      (-65536)
# define BSQ_START		0
# define BSQ_SIZE		1

# define MIN(x, y)      (y ^ ((x ^ y) & -(x < y)))

char	g_empty;
char	g_obstacle;
char	g_full;
int		g_nbr;
int		*g_obstacle_map;
int		g_size[2];

void	ft_set_biggest(int *biggest_size,
	int *biggest_start, int cur_pos, int cur_size);
int		ft_is_point_inside_square(int field_size[2],
	int point, int square_lu, int square_rd);
int		ft_reduce_square(int field_size[2],
	int obstacle_pos, int start_pos, int *end_pos);
int		ft_get_offset_right(int field_size[2], int obstacle_pos);
int		ft_get_offset_down(int field_size[2], int obstacle_pos);
void	ft_display_result(int *obstacle_map,
	int field_size[2], int biggest_start, int biggest_size);
int		ft_is_biggest_square(int *start_pos);
int		ft_find_biggest_square(int *obstacle_map,
	int field_size[2], int *biggest_start);

#endif
