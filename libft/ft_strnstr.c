/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:25:41 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:25:43 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (ft_strlen(find) == 0)
		return ((char*)str);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == find[x])
		{
			while (str[i + x] == find[x] && x < ft_strlen((char*)find))
			{
				if ((i + x) >= len)
					return (NULL);
				if (x == ft_strlen(find) - 1)
					return ((char*)str + i);
				x++;
			}
		}
		x = 0;
		i++;
	}
	return (0);
}
