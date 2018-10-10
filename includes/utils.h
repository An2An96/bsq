/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:29:20 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 16:29:21 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_read_file(char *filename);
void	ft_close_file(int fd);

#endif
