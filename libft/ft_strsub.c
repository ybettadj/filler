/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:26:31 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:26:32 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*c1;

	i = 0;
	if (!(c1 = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s != NULL && i < len)
	{
		c1[i] = s[start];
		i++;
		start++;
	}
	c1[i] = '\0';
	return (c1);
}
