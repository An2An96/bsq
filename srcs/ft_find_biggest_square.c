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
    obstacle[1] = obstacle_pos / field_size[0];
    start[0] = start_pos % field_size[0];
    start[1] = start_pos / field_size[0];

    printf("\t\tft_reduce_square: obstacle (%d, %d), start (%d, %d)\n", obstacle[0], obstacle[1], start[0], start[1]);

    if ((obstacle[0] - start[0]) > (obstacle[1] - start[1]))
        diff = obstacle[0] - start[0];
    else
        diff = obstacle[1] - start[1];
    printf("\t\tdiff = %d\n", diff);
    *end_pos = (start_pos + (diff - 1)) + ((diff - 1) * field_size[0]);
    printf("\t\tend pos = %d\n", *end_pos);
    return (diff);
}

int    ft_is_biggest_square(int *obstacle_map, int field_size[2], int start_pos)
{
    printf("\t====== ft_is_biggest_square ======\n");

    int i;
    int square_size;
    int diagonal;
    //int new_size;
    int big_size;

    //printf("\tFIELD %d, %d", field_size[0], field_size[1]);
    printf("\t%d < %d?\n", field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[0]));
    square_size = MIN(field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[0]));
    //diagonal = start_pos + square_size - 1 + (field_size[0] * (square_size - 1));

    i = 0;
    big_size = -1;
    while (obstacle_map[i] != END_ARRAY)
    {
        diagonal = start_pos + square_size - 1 + (field_size[0] * (square_size - 1));
        printf("\ttest: start_pos = %d, square_size = %d, field width = %d\n", start_pos, square_size, field_size[0]);
        if (ft_is_point_inside_square(field_size, obstacle_map[i], start_pos, diagonal))
        {
            printf("\tpoint %d inside square %d - %d\n", obstacle_map[i], start_pos, diagonal);
            square_size = ft_reduce_square(field_size, obstacle_map[i], start_pos, &diagonal);
            //big_size = big_size < new_size ? new_size : big_size;
            printf("\tnew pos square: %d, size: %d\n", diagonal, -1);
        }
        i++;
    }
    if (big_size == -1)
        big_size = square_size;
    printf("\tBig size: %d\n=======================\n", big_size);
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
    obstacle[1] = obstacle_pos / field_size[0];
    //printf("obstacle %d %d %d\n", obstacle[0], obstacle[1], ((obstacle[1] + 1) * field_size[0]));
    if (obstacle[1] + 1 < field_size[1])
        return ((obstacle[1] + 1) * field_size[0]);
    else
        return (-1);
}

void    ft_display_result(int *obstacle_map, int field_size[2], int biggest_start, int big_size)
{
    int x;
    int y;
    int obs_idx;

    printf("start %d, size %d\n", biggest_start, big_size);
    int r_x_min = biggest_start % field_size[0];
    int r_y_min = biggest_start / field_size[0];
    int r_x_max = (r_x_min + big_size - 1);
    int r_y_max = (r_y_min + big_size - 1);

    y = 0;
    obs_idx = 0;
    printf("min: (%d, %d), max: (%d, %d)\n", r_x_min, r_y_min, r_x_max, r_y_max);
    printf("field: %d %d", field_size[0], field_size[1]);
    while (y < field_size[1])
    {
        x = 0;
        while (x < field_size[0])
        {
            if (obstacle_map[obs_idx] == y * field_size[0] + x)
            {
                ft_putchar('o');
                obs_idx++;
            }
            else if (x >= r_x_min && x <= r_x_max && y >= r_y_min && y <= r_y_max)
            {
                ft_putchar('x');
            }
            else
                ft_putchar('.');
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}

int     ft_find_biggest_square(int *obstacle_map, int field_size[2])
{
    printf("====== ft_find_biggest_square ======\n");
    int i;
    int cur_pos;
    int cur_size;
    int big_size;

    int biggest_start;

    i = 0;
    big_size = ft_is_biggest_square(obstacle_map, field_size, 0);
    while (obstacle_map[i] != END_ARRAY)
    {
        if ((cur_pos = ft_get_offset_right(field_size, obstacle_map[i])) != -1)
        {
            printf("right pos: %d\n", cur_pos);
            cur_size = ft_is_biggest_square(obstacle_map, field_size, cur_pos);    
        }
        if (cur_size > big_size)
        {
            big_size = cur_size;
            biggest_start = cur_pos;
        }
        if ((cur_pos = ft_get_offset_down(field_size, obstacle_map[i])) != -1)
        {
            printf("down pos: %d\n", cur_pos);
            cur_size = ft_is_biggest_square(obstacle_map, field_size, cur_pos);
        }
        if (cur_size > big_size)
        {
            big_size = cur_size;
            biggest_start = cur_pos;
        }
        i++;
    }
    printf("BIG SIZE: %d, START POS: %d\n", big_size, biggest_start);

    ft_display_result(obstacle_map, field_size, biggest_start, big_size);
    return (big_size);
}