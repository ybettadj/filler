/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:16:36 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:16:37 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	x;
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	i = 0;
	x = (unsigned char)c;
	while (i < n)
	{
		if ((*cdest++ = *csrc++) == x)
			return (cdest);
		i++;
	}
	return (NULL);
}
