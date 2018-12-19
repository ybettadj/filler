/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:18 by ybettadj          #+#    #+#             */
/*   Updated: 2018/12/19 16:07:26 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		size_map_x(struct s_stru s)
{
	int		i;
	int		k;
	char	*str;
	int		size;

	i = 0;
	k = 0;
	size = 0;
	str = ft_strnew(10000);
	while (ft_isdigit(s.info1[i]) != 1)
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
		str[k++] = s.info1[i++];
	size = ft_atoi(str);
	ft_strdel(&str);
	return (size);
}

int		size_map_y(struct s_stru s)
{
	int		i;
	int		k;
	char	*str;
	int		size;

	i = 0;
	k = 0;
	str = ft_strnew(6);
	while (ft_isdigit(s.info1[i]) != 1)
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
		i++;
	while (ft_isdigit(s.info1[i]) != 1)
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
		str[k++] = s.info1[i++];
	size = ft_atoi(str);
	ft_strdel(&str);
	return (size);
}

int		size_piece_x(struct s_stru s)
{
	int		i;
	int		k;
	char	*str;
	int		size;

	i = 0;
	k = 0;
	size = 0;
	str = ft_strnew(6);
	while (ft_isdigit(s.info1[i]) != 1)
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
	{
		str[k] = s.info1[i];
		k++;
		i++;
	}
	size = ft_atoi(str);
	ft_strdel(&str);
	return (size);
}

int		size_piece_y(struct s_stru s)
{
	int		i;
	int		k;
	char	*str;
	int		size;

	i = 0;
	k = 0;
	size = 0;
	str = ft_strnew(6);
	while (ft_isdigit(s.info1[i]) != 1)
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
		i++;
	while (ft_isdigit(s.info1[i]) != 1)
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
		str[k++] = s.info1[i++];
	size = ft_atoi(str);
	ft_strdel(&str);
	return (size);
}
