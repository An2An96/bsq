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
 
int    ft_is_biggest_square(int *obstacle_map, int field_size[2], int *start_pos)
{
    int i;
    int square_size;
    int diagonal;
    int finded;

    int biggest_size_tmp;
    int biggest_start_pos_tmp;
 
    int biggest_start_pos;
    int biggest_size;
    int old_obstacle_idx;
    int cur_obstacle_idx;
 
    old_obstacle_idx = -2;
    biggest_size = -1;
    biggest_size_tmp = -1;
    while (old_obstacle_idx != -1)
    {
        cur_obstacle_idx = -1;
        if((square_size = MIN(field_size[0] - (*start_pos % field_size[0]), field_size[1] - (*start_pos / field_size[0]))) <= 0)
            break ;
        diagonal = *start_pos + square_size - 1 + (field_size[0] * (square_size - 1));
 
        i = 0;
        biggest_size_tmp = -1;
        while (obstacle_map[i] != END_ARRAY)
        {
            if (ft_is_point_inside_square(field_size, obstacle_map[i], *start_pos, diagonal))
            {
                square_size = ft_reduce_square(field_size, obstacle_map[i], *start_pos, &diagonal);
                if (biggest_size_tmp == -1 || square_size < biggest_size_tmp)
                {
                    biggest_size_tmp = square_size;
                    biggest_start_pos_tmp = *start_pos;
                }
                cur_obstacle_idx = i;
            }
            i++;
        }
        if (biggest_size_tmp == -1)
        {
            biggest_size_tmp = square_size;
            biggest_start_pos_tmp = *start_pos;
        }
        if (biggest_size == -1 || biggest_size_tmp > biggest_size)
        {
            biggest_size = biggest_size_tmp;
            biggest_start_pos = biggest_start_pos_tmp;
        }
        if (cur_obstacle_idx != -1)
        {
			*start_pos = (*start_pos % field_size[0]) + (field_size[0] * (obstacle_map[old_obstacle_idx] / field_size[0] + 1));
            old_obstacle_idx = cur_obstacle_idx;
        }
        else
        {
            i = old_obstacle_idx >= 0 ? (old_obstacle_idx + 1) : 0;
            finded = 0;
			while (obstacle_map[i] != END_ARRAY)
            {
                if ((obstacle_map[i] % field_size[0] >= *start_pos % field_size[0]) && (obstacle_map[i] / field_size[0] > obstacle_map[old_obstacle_idx] / field_size[0]))
                {
                    old_obstacle_idx = i;
                    finded = 1;
                    break ;
                }
                i++;
            }
            if (!finded)
                old_obstacle_idx = -1;
        }
    }
    *start_pos = biggest_start_pos;
    return (biggest_size);
}
 
int     ft_find_biggest_square(int *obstacle_map, int field_size[2])
{
    //printf("====== ft_find_biggest_square ======\n");
    int i;
    int cur_pos;
    int cur_size;
    int big_size;
 
    int biggest_start;
 
    i = 0;
	cur_size = 0;
    cur_pos = 0;
    big_size = ft_is_biggest_square(obstacle_map, field_size, &cur_pos);
	biggest_start = cur_pos;
    while (obstacle_map[i] != END_ARRAY)
    {
        if ((cur_pos = ft_get_offset_right(field_size, obstacle_map[i])) != -1)
        {
            //printf("right pos: %d\n", cur_pos);
            cur_size = ft_is_biggest_square(obstacle_map, field_size, &cur_pos);    
        }
        if (cur_size > big_size)
        {
            big_size = cur_size;
            biggest_start = cur_pos;
        }
        if ((cur_pos = ft_get_offset_down(field_size, obstacle_map[i])) != -1)
        {
            //printf("down pos: %d\n", cur_pos);
            cur_size = ft_is_biggest_square(obstacle_map, field_size, &cur_pos);
        }
        if (cur_size > big_size)
        {
            big_size = cur_size;
            biggest_start = cur_pos;
        }
        i++;
    }
    //printf("BIG SIZE: %d, START POS: %d\n", big_size, biggest_start);
 
    ft_display_result(obstacle_map, field_size, biggest_start, big_size);
    return (big_size);
}