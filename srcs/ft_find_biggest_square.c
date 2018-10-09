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

void    ft_find_biggest_square(int *obstacle_map, int field_size[2], int start_pos)
{
    int i;
    int square_size;
    int diagonal;
    int new_size;

    //printf("%d > %d?", field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[1]));
    square_size = MIN(field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[1]));
    diagonal = start_pos + square_size - 1 + (field_size[0] * (square_size - 1));

    i = 0;
    while (obstacle_map[i] != -1)
    {
        //printf("test: %d %d %d\n", start_pos, square_size, field_size[0]);
        if (ft_is_point_inside_square(field_size, obstacle_map[i], start_pos, diagonal))
        {
            printf("point %d inside square %d - %d\n", obstacle_map[i], start_pos, diagonal);
            new_size = ft_reduce_square(field_size, obstacle_map[i], start_pos, &diagonal);
            square_size = square_size < new_size ? new_size : square_size;
            printf("new pos square: %d, size: %d\n", diagonal, new_size);
        }
        i++;
    }
    printf("Big size: %d", square_size);
}
