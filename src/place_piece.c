/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:58:05 by ybettadj          #+#    #+#             */
/*   Updated: 2018/12/19 15:58:13 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		check_pieceonmap(struct s_stru s, int i, int j, int *same)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < s.piece_x)
	{
		while (y < s.piece_y)
		{
			if (s.map[i + x][j + y] != '.')
			{
				if (s.map[i + x][j + y] == s.c && s.piece[x][y] == '*')
					*same += 1;
				else if (s.map[i + x][j + y] == s.a && s.piece[x][y] == '*')
					s.stop++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (s.stop);
}

int		place_piece_hd(struct s_stru s)
{
	int i;
	int j;
	int same;

	i = 0;
	j = s.map_size_y - s.piece_y;
	same = 0;
	while (i <= s.map_size_x - s.piece_x)
	{
		while (j >= 0)
		{
			s.stop = check_pieceonmap(s, i, j, &same);
			if (same == 1 && s.stop == 0)
				return (put_coord(s, i, j));
			same = 0;
			s.stop = 0;
			j--;
		}
		j = s.map_size_y - s.piece_y;
		i++;
	}
	return (1);
}

int		place_piece_bd(struct s_stru s)
{
	int i;
	int j;
	int same;

	i = s.map_size_x - s.piece_x;
	j = s.map_size_y - s.piece_y;
	same = 0;
	s.stop = 0;
	while (i >= 0)
	{
		while (j >= 0)
		{
			s.stop = check_pieceonmap(s, i, j, &same);
			if (same == 1 && s.stop == 0)
				return (put_coord(s, i, j));
			same = 0;
			s.stop = 0;
			j--;
		}
		j = s.map_size_y - s.piece_y;
		i--;
	}
	return (1);
}

int		place_piece_hg(struct s_stru s)
{
	int i;
	int j;
	int same;

	i = 0;
	j = 0;
	same = 0;
	while (i <= s.map_size_x - s.piece_x)
	{
		while (j <= s.map_size_y - s.piece_y)
		{
			s.stop = check_pieceonmap(s, i, j, &same);
			if (same == 1 && s.stop == 0)
				return (put_coord(s, i, j));
			same = 0;
			s.stop = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		place_piece_bg(struct s_stru s)
{
	int i;
	int j;
	int same;

	i = s.map_size_x - s.piece_x;
	j = 0;
	same = 0;
	while (i >= 0)
	{
		while (j <= s.map_size_y - s.piece_y)
		{
			s.stop = check_pieceonmap(s, i, j, &same);
			if (same == 1 && s.stop == 0)
				return (put_coord(s, i, j));
			same = 0;
			s.stop = 0;
			j++;
		}
		j = 0;
		i--;
	}
	return (1);
}
