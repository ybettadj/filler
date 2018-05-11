/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:23:47 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:23:49 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	char		*s;
	size_t		n;
	size_t		len;

	dest = dst;
	s = (char*)src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	len = dest - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*dest++ = *s;
			n--;
		}
		s++;
	}
	*dest = '\0';
	return (len + (s - src));
}
