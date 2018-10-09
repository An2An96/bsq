/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:05:08 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/03 21:05:09 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		ft_putstr(buf);
	}
	if (close(fd) == -1 && fd == 3)
		ft_putstr("Failed closing");
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
