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

# define BUF_SIZE    32 + 1

void	ft_read_obstacles_map(char *str, int read_params[2], int *map_idx);
int		ft_validate(char *str, int *pos, int *obstacle_count, int end_line);
int		ft_read_file_validate(char *filename);
int		ft_read_file_consider(char *filename);

#endif
