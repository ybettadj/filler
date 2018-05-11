/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:17:29 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:17:30 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t len)
{
	unsigned char	str[len];

	if (len < 134217728)
	{
		ft_memcpy(str, (unsigned char *)s2, len);
		ft_memcpy((unsigned char *)s1, str, len);
		return ((unsigned char *)s1);
	}
	return (NULL);
}
