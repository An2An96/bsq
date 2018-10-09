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

#include "main.h"

int     ft_is_point_inside_square(int field_size[2], int point, int square_lu, int square_rd)
{
    int point_x;
    int point_y;

    point_x = point % field_size[0];
    point_y = point / field_size[1];
    if (point_x >= (square_lu % field_size[0]) && point_x <= (square_rd % field_size[0])
        && point_y >= (square_lu / field_size[1]) && point_y <= (square_rd / field_size[1]))
    {
        return (1);
    }
    return (0);
}

int    ft_reduce_square(int field_size[2], int obstacle_pos, int start_pos, int *end_pos)
{
    int obstacle[2];
    int start[2];
    int diff;

    obstacle[0] = obstacle_pos % field_size[0];
    obstacle[1] = obstacle_pos / field_size[1];
    start[0] = start_pos % field_size[0];
    start[1] = start_pos / field_size[1];

    if ((obstacle[0] - start[0]) > (obstacle[1] - start[1]))
        diff = obstacle[0] - start[0];
    else
        diff = obstacle[1] - start[1];
    *end_pos = (start_pos + (diff - 1)) + ((diff - 1) * field_size[0]);
    return (diff);
}

int    ft_is_biggest_square(int *obstacle_map, int field_size[2], int start_pos)
{
    printf("====== ft_is_biggest_square ======\npoint %d\n", start_pos);

    int i;
    int square_size;
    int diagonal;
    int new_size;
    int big_size;

    printf("%d > %d?", field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[1]));
    square_size = MIN(field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[1]));
    diagonal = start_pos + square_size - 1 + (field_size[0] * (square_size - 1));

    i = 0;
    big_size = -1;
    while (obstacle_map[i] != END_ARRAY)
    {
        printf("test: %d %d %d\n", start_pos, square_size, field_size[0]);
        if (ft_is_point_inside_square(field_size, obstacle_map[i], start_pos, diagonal))
        {
            printf("point %d inside square %d - %d\n", obstacle_map[i], start_pos, diagonal);
            new_size = ft_reduce_square(field_size, obstacle_map[i], start_pos, &diagonal);
            big_size = big_size < new_size ? new_size : big_size;
            printf("new pos square: %d, size: %d\n", diagonal, new_size);
        }
        i++;
    }
    if (big_size == -1)
        big_size = square_size;
    printf("Big size: %d\n=======================\n", big_size);
    return (big_size);
}

int     ft_get_offset_right(int field_size[2], int obstacle_pos)
{
    int obstacle[2];

    obstacle[0] = obstacle_pos % field_size[0];
    obstacle[1] = obstacle_pos / field_size[1];
    if (obstacle[0] + 1 < field_size[0])
        return (obstacle[0] + 1);
    else
        return (-1);
}

int     ft_get_offset_down(int field_size[2], int obstacle_pos)
{
    int obstacle[2];

    obstacle[0] = obstacle_pos % field_size[0];
    obstacle[1] = obstacle_pos / field_size[1];
    if (obstacle[1] + 1 < field_size[1])
        return ((obstacle[1] + 1) * field_size[0]);
    else
        return (-1);
}

int    ft_find_biggest_square(int *obstacle_map, int field_size[2])
{
    int i;
    int cur_pos;
    int cur_size;
    int big_size;

    i = 0;
    big_size = ft_is_biggest_square(obstacle_map, field_size, 0);
    while (obstacle_map[i] != END_ARRAY)
    {
        if ((cur_pos = ft_get_offset_right(field_size, obstacle_map[i])) != -1)
        {
            printf("====== ft_find_biggest_square ======\nright pos: %d\n", cur_pos);
            cur_size = ft_is_biggest_square(obstacle_map, field_size, cur_pos);    
        }
        if (cur_size > big_size)
            big_size = cur_size;
        if ((cur_pos = ft_get_offset_down(field_size, obstacle_map[i])) != -1)
        {
            printf("====== ft_find_biggest_square ======\ndown pos: %d\n", cur_pos);
            cur_size = ft_is_biggest_square(obstacle_map, field_size, cur_pos);
        }
        if (cur_size > big_size)
            big_size = cur_size;
        i++;
    }
    printf("BIG SIZE: %d\n", big_size);
    return (big_size);
}