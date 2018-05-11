/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:26:16 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:26:20 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t f;

	i = 0;
	f = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		f = 0;
		while (haystack[i + f] == needle[f])
		{
			if (needle[f + 1] == '\0')
				return ((char*)haystack + i);
			f++;
		}
		i++;
	}
	return (0);
}
