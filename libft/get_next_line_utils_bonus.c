/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:32:43 by bperraud          #+#    #+#             */
/*   Updated: 2022/02/06 15:32:43 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, const char *src, long n)
{
	unsigned int	i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0' && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		while (i <= n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

char	**ft_split_gnl(char const *str, const char c)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(3 * sizeof(char *));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			dest[0] = malloc((i + 1) * sizeof(char));
			dest[1] = malloc((BUFFER_SIZE - i + 1) * sizeof(char));
			if (!dest[0] || !dest[1])
				return (NULL);
			ft_strncpy(dest[0], str, i);
			ft_strncpy(dest[1], str + i, BUFFER_SIZE - i);
			break ;
		}
		i++;
	}
	dest[2] = NULL;
	return (dest);
}
