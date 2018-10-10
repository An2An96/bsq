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

int	ft_read_file_validate(char *filename);
int	ft_read_file_consider(char *filename);

#endif
