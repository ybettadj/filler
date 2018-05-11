/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:23:33 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:23:36 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		string1;
	int		string2;
	int		total;
	char	*tab;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	string1 = ft_strlen((char*)s1);
	string2 = ft_strlen((char*)s2);
	total = string1 + string2;
	tab = (char*)malloc(sizeof(*tab) * (total + 1));
	if (!tab)
		return (NULL);
	total = 0;
	while (total < string1)
		tab[i++] = s1[total++];
	total = 0;
	while (total < string2)
		tab[i++] = s2[total++];
	tab[i] = '\0';
	return (tab);
}
