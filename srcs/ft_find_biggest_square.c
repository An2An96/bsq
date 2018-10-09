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

int     is_point_inside_square(int point, int square_lu, int square_rd)
{

}

void    ft_find_biggest_square(int *obstacle_map, int field_size[2], int start_pos)
{
    int i;
    int square_size;
    int diagonal;

    square_size = MAX(field_size[0] - (start_pos % field_size[0]), field_size[1] - (start_pos / field_size[1]));

    i = 0;
    while (obstacle_map[i] != -1)
    {
        diagonal = start_pos + square_size - 1 + (field_size[0] * (square_size - 1));
        if (is_point_inside_square(obstacle_map[i], start_pos, diagonal))
        {
            
        }
    }
}
