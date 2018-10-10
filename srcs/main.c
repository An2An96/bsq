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
#include <stdio.h>

void	ft_clear_global(void)
{
	if (g_obstacle_map)
		free(g_obstacle_map);
	g_obstacle_map = NULL;
	g_nbr = 0;
	g_size[0] = 0;
	g_size[1] = 0;
}

void	ft_start_bsq(void)
{
	int square_start_pos;
	int square_size;

	square_size = ft_find_biggest_square(g_obstacle_map,
		g_size, &square_start_pos);
	ft_display_result(g_obstacle_map, g_size,
		square_start_pos, square_size);
	ft_clear_global();
}

void	ft_read_input_map(char *map)
{
	int pos;
	int obstacle_count;
	int read_params[2];
	int map_idx;

	pos = 0;
	obstacle_count = 0;
	if (!ft_validate(map, &pos, &obstacle_count, 1))
	{
		ft_putstr("map error\n");
		return ;
	}
	read_params[0] = 0;
	read_params[1] = 0;
	map_idx = 0;
	ft_read_obstacles_map(map, read_params, &map_idx);
	ft_start_bsq();
}

void	ft_read_input(void)
{
	char	buf[32];
	char	*res;
	int		read_length;

	res = NULL;
	while ((read_length = read(0, &buf, BUF_SIZE)))
	{
		buf[read_length] = '\0';
		res = ft_strcat(res, buf);
	}
	write(1, "readed 0\n", 7);
	if (res)
		ft_read_input_map(res);
}

int		main(int argc, char **argv)
{
	int i;

	ft_clear_global();
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_read_file_validate(argv[i])
				&& ft_read_file_consider(argv[i]))
			{
				ft_start_bsq();
			}
			i++;
		}
	}
	else
	{
		ft_read_input();
	}
	return (0);
}
