/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:14:26 by ybettadj          #+#    #+#             */
/*   Updated: 2017/11/21 20:14:32 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg_n_count(int *i, int *n, int *count, int *y)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*y = 1;
	}
	while (*count != 0)
	{
		*count = *count / 10;
		*i = *i + 1;
	}
}

char		*ft_itoa(int n)
{
	int		i;
	int		y;
	int		count;
	char	*tab;

	i = 0;
	y = 0;
	count = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == -0)
		return (ft_strdup("0"));
	ft_neg_n_count(&i, &n, &count, &y);
	if (!(tab = (char*)malloc(sizeof(char) * (i + y + 1))))
		return (NULL);
	tab[i + y] = '\0';
	while (i != 0)
	{
		tab[i + y - 1] = n % 10 + '0';
		i--;
		n = n / 10;
	}
	if (y == 1)
		tab[0] = '-';
	return (tab);
}
