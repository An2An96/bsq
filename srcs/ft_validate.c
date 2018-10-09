char g_empty;
char g_obstacle;
char g_full;
int	g_nbr; // nbr == height


// int		ft_strlen(char *str)
// {
// 	int lenght;

// 	lenght = 0;
// 	while (str[lenght] != '\0')
// 	{
// 		if str[lenght] 
	
	
// 		lenght++;
// 	}
// 	return (lenght);


// }


// int	ft_valid_height(char *str, int *width, int *height)
// {
// 	int i;
// 	int width_temp;

// 	i = 0;
// 	width_temp = 0;
// 	*width = 0;
// 	*height = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\n')
// 		{
// 			if (*width == 0)
// 				*width = width_temp;
// 			else if (*width != width_temp)
// 				return (0);
// 			width_temp = 0;
// 		}
// 		else
// 		{
// 			if (width_temp++ == 0)
// 				(*height)++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }


int	ft_valid_first_line(char *str)
{
	int i;

	i = 0;
	if (str[i] >= '9' || str[i] <= '0')
		return(0);
	while (str[i] != '\n' && (str[i] >= '0') && (str[i] <= '9'))
	{
		g_nbr *= 10;
		g_nbr += (int)str[i] - '0';
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
	if (*height == 0)
	{
		i = ft_valid_first_line(str);
		if (i == 0)
		{
			return (0);
		}
	}
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			width_temp++;
		else if (str[i] == '\n')
		{
			if (*height == 0)
			{
				*width = width_temp;
			}
			else if (width_temp == *width)
			{
				return (0);
			}
			width_temp = 0;
			height++;
		}
		else if (str[i] == g_obstacle)
			obstacle_count++;
		else if (str[i] != g_empty)
			return (0);
		i++;
	}
	return (1);
}

void	ft_display_file(char *name)
{
	int		fd;
	int		read_length;
	char	buf[BUFFER_SIZE];

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr("Error open file.\n");
		return ;
	}
	while ((read_length = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_length] = '\0';
		if (ft_validate(char *str, &width, &height, &pos, &obstacle_count) == 0)
		{	
			ft_putstr("Error validate.\n");
			return (0);
		}
		if (read_size < 32 && g_nbr != height)
		{
			ft_putstr("Error height.\n");
			return (0);
		}
		ft_putstr(buf);
	}
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed closing");
}

// int		main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		ft_putstr("File name missing.\n");
// 	else if (argc > 2)
// 		ft_putstr("Too many arguments.\n");
// 	else
// 		ft_display_file(argv[1]);
// 	return (0);
// }

// int	main()
// {
// 	while(read_size = read(...))
// 	{
		
// 		}
// 	}
// }