#include "read.h"

int	ft_valid_first_line(char *str)
{
	int i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] != '\n' && (str[i] >= '0' && str[i] <= '9'))
	{
		g_size[1] *= 10;
		g_size[1] += (int)str[i] - '0';
		i++;
	}
	g_empty = str[i++];
	g_obstacle = str[i++];
	g_full = str[i++];
	return (str[i] == '\n' ? i + 1 : 0);
}

int	ft_validate(char *str, int *width, int *height, int *pos, int *obstacle_count)
{
	int i;
	int width_temp;

	i = 0;
	if (*pos == 0 && *height == 0)
	{
		i = ft_valid_first_line(str);
		if (i == 0)
		{
			return (0);
		}
	}
	width_temp = (*pos);
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			if (str[i] == g_obstacle)
				obstacle_count++;
			else if (str[i] != g_empty)
				return (0);
			width_temp++;
		}
		else if (str[i] == '\n')
		{
			if (*height == 0)
				*width = width_temp;
			else if (width_temp != *width)
				return (0);
			width_temp = 0;
			(*height)++;
		}
		i++;
	}
	(*pos) = width_temp;
	return (1);
}

void	ft_read_obstacles_map(char *str, int *height, int *pos, int *map_idx)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			(*height)++;
		}
		else if (*height > 0)
		{
			if (str[i] == g_obstacle)
			{
				g_obstacle_map[(*map_idx)++] = *pos;
			}
			(*pos)++;
		}
		i++;
	}
	g_obstacle_map[*map_idx] = END_ARRAY;
}

void	ft_read_file(char *name, int type_read)
{
	int		fd;
	int		read_length;
	char	buf[BUFFER_SIZE];

	int width;
	int height;
	int pos;
	int obstacle_count;
	int map_idx;

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr("Error open file.\n");
		return ;
	}
	width = 0;
	height = 0;
	pos = 0;
	obstacle_count = 0;
	map_idx = 0;
	while ((read_length = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_length] = '\0';
		if (type_read == READ_VALIDATE)
		{
			if (ft_validate(buf, &width, &height, &pos, &obstacle_count) == 0)
			{
				ft_putstr("Error validate.\n");
				exit(0);
			}
			if (read_length < BUFFER_SIZE)
			{
				if (g_size[1] != height)
				{
					ft_putstr("Error height.\n");
					exit(0);
				}
				g_size[0] = width;
				g_size[1] = height;
				
				g_obstacle_map = malloc(obstacle_count + 1 * sizeof(int));
			}
		}
		else if (type_read == READ_CONSIDER)
		{
			ft_read_obstacles_map(buf, &height, &pos, &map_idx);
		}
	}
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed closing");
}