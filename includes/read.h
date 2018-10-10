/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:56:03 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 16:56:04 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "utils.h"
# include "bsq.h"

# define BUFFER_SIZE    32
# define READ_VALIDATE	0
# define READ_CONSIDER	1

char	g_empty;
char	g_obstacle;
char	g_full;
int		g_nbr;

void	ft_read_file(char *name, int type_read);

#endif
