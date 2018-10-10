/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 22:48:38 by rschuppe          #+#    #+#             */
/*   Updated: 2018/10/10 22:48:38 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	int		length;
	char	*result;

	length = ft_strlen(dest) + ft_strlen(src);
	result = (char*)malloc(length + 1 * sizeof(char));
	if (result)
	{
		i = 0;
		while (dest && dest[i] != '\0')
		{
			result[i] = dest[i];
			i++;
		}
		j = 0;
		while (src[j] != '\0')
			result[i++] = src[j++];
		result[i] = '\0';
		if (dest)
			free(dest);
	}
	return (result);
}
