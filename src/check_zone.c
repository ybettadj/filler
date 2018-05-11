/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 07:17:24 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/27 07:17:25 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int 	check_zone1(struct s_stru s)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;

	while (i <= s.map_size_x / 2)
	{
		while (j <= s.map_size_y / 2)
		{
			if (s.map[i][j] == s.c)
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}

int 	check_zone2(struct s_stru s)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	j = s.map_size_y - 1;
	while (i <= s.map_size_x / 2)
	{
		while (j >= s.map_size_y / 2)
		{
			if (s.map[i][j] == s.c)
				x++;
			j--;
		}
		j = s.map_size_y - 1;
		i++;
	}
	return (x);
}

int 	check_zone3(struct s_stru s)
{
	int i;
	int j;
	int x;

	i = s.map_size_x - 1;
	j = 0;
	x = 0;
	while (i >= s.map_size_x / 2)
	{
		while (j <= s.map_size_y / 2)
		{
			if (s.map[i][j] == s.c)
				x++;
			j++;
		}
		j = 0;
		i--;
	}
	return (x);
}

int 	check_zone4(struct s_stru s)
{
	int i;
	int j;
	int x;

	i = s.map_size_x - 1;
	j = s.map_size_y - 1;
	x = 0;
	while (i >= s.map_size_x / 2)
	{
		while (j >= s.map_size_y / 2)
		{
			if (s.map[i][j] == s.c)
				x++;
			j--;
		}
		j = s.map_size_y - 1;
		i--;
	}
	return (x);
}

int 	check_zone(struct s_stru s)
{
	int zone1;
	int zone2;
	int zone3;
	int zone4;
	zone1 = check_zone1(s);
	zone2 = check_zone2(s);
	zone3 = check_zone3(s);
	zone4 = check_zone4(s);
	if (zone1 >= zone2)
		if (zone1 >= zone3)
			if (zone1 >= zone4)
				return (1);
	if (zone2 >= zone1)
		if (zone2 >= zone3)
			if (zone2 >= zone4)
				return (2);
	if (zone3 >= zone1)
		if (zone3 >= zone2)
			if (zone3 >= zone4)
				return (3);
	if (zone4 >= zone1)
		if (zone4 >= zone2)
			if (zone4 >= zone3)
				return (4);
	return(0);
}
