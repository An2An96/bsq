/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:05:31 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 19:05:32 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include <stdio.h>

int		ft_valid_first_line(char *str)
{
	int i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] != '\n' && (str[i] >= '0' && str[i] <= '9'))
	{
		g_nbr *= 10;
		g_nbr += (int)str[i] - '0';
		i++;
	}
	if (g_nbr <= 0)
		return (0);
	g_empty = str[i++];
	g_obstacle = str[i++];
	g_full = str[i++];
	return (str[i] == '\n' ? i + 1 : 0);
}

int		ft_valid_char(char c, int **obstacle_count, int *width_temp)
{
	if (c != '\n')
	{
		if (c == g_obstacle)
			(**obstacle_count)++;
		else if (c != g_empty)
			return (0);
		(*width_temp)++;
	}
	else if (c == '\n')
	{
		if (g_size[1] == 0)
			g_size[0] = *width_temp;
		else if (*width_temp != g_size[0])
			return (0);
		(*width_temp) = 0;
		g_size[1]++;
	}
	return (1);
}

int		ft_validate(char *str, int *pos, int *obstacle_count, int end_line)
{
	int i;
	int width_temp;

	i = 0;
	if (*pos == 0 && g_size[1] == 0)
		if ((i = ft_valid_first_line(str)) == 0)
			return (0);
	width_temp = (*pos);
	while (str[i] != '\0')
	{
		if (ft_valid_char(str[i], &obstacle_count, &width_temp) == 0)
			return (0);
		i++;
	}
	(*pos) = width_temp;
	if (end_line)
	{
		if (g_size[1] != g_nbr)
			return (0);
		g_obstacle_map = (int*)malloc(*obstacle_count + 1 * sizeof(int));
	}
	return (1);
}

int		ft_read_file_validate(char *filename)
{
	int		fd;
	int		read_length;
	int		pos;
	int		obstacle_count;
	char	buf[BUF_SIZE];

	if ((fd = ft_read_file(filename)) == -1)
		return (0);
	pos = 0;
	obstacle_count = 0;
	while ((read_length = read(fd, buf, BUF_SIZE)))
	{
		buf[read_length] = '\0';
		if (!ft_validate(buf, &pos, &obstacle_count, (read_length < BUF_SIZE)))
		{
			ft_putstr("map error\n");
			return (0);
		}
	}
	ft_close_file(fd);
	return (1);
}
