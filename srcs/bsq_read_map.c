/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 21:49:52 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 21:49:53 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "bsq.h"

void	ft_read_obstacles_map(char *str, int read_params[2], int *map_idx)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			read_params[0]++;
		else if (read_params[0] > 0)
		{
			if (str[i] == g_obstacle)
				g_obstacle_map[(*map_idx)++] = read_params[1];
			read_params[1]++;
		}
		i++;
	}
	g_obstacle_map[*map_idx] = END_ARRAY;
}

int		ft_read_file_consider(char *filename)
{
	int		fd;
	int		read_length;
	int		read_params[2];
	int		map_idx;
	char	buf[BUF_SIZE];

	if ((fd = ft_read_file(filename)) == -1)
		return (0);
	read_params[0] = 0;
	read_params[1] = 0;
	map_idx = 0;
	while ((read_length = read(fd, buf, BUF_SIZE)))
	{
		buf[read_length] = '\0';
		ft_read_obstacles_map(buf, read_params, &map_idx);
	}
	ft_close_file(fd);
	return (1);
}
