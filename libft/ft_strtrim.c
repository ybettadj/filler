/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:26:44 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:26:45 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*c1;
	char			*dest;
	unsigned int	i;
	size_t			l;

	i = 0;
	c1 = (char*)s;
	if (!s)
		return (NULL);
	while (c1[i] == ' ' || c1[i] == '\t' || c1[i] == '\n')
		i++;
	l = ft_strlen(c1) - 1;
	while (l > i && (c1[l] == ' ' || c1[l] == '\t' || c1[l] == '\n'))
		l--;
	if (l < i)
		return (dest = ft_strdup(""));
	return (dest = ft_strsub(c1, i, l - (size_t)i + 1));
}
