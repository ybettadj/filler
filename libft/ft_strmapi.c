/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:24:16 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:24:18 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mem;

	i = 0;
	if (!s || !f)
		return (NULL);
	mem = ft_strnew(ft_strlen(s));
	if (mem == NULL)
		return (NULL);
	while (s[i])
	{
		mem[i] = (*f)(i, s[i]);
		i++;
	}
	return (mem);
}
