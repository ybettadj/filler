/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:34:10 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/26 01:34:12 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int 	check_pieceonmap(struct s_stru s, int i, int j, int *same)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < s.piece_x)
	{
		while (y < s.piece_y)
		{
			if (s.map[i + x][j + y] != '.' )
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

int 	put_coord(struct s_stru s, int i, int j)
{
	ft_putnbr(i - s.countup);
	ft_putchar(' ');
	ft_putnbr(j - s.countleft);
	ft_putchar('\n');
	return (0);
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
			{
				int k;

				k = 0;
				/*while (s.map[k])
				{
					ft_strdel(&s.map[k]);
					k++;
				}*/
				return (put_coord(s, i, j));
			}
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

int		player1(struct s_stru s)
{
	int zone;

	zone = check_zone(s);
	cut_piece(&s);
	if (zone == 1) // (je suis en haut a gauche de l'adversaire)
		return (place_piece_bd(s));
	else if (zone == 2) //(je suis en haut a droite de l'adversaire)
		return(place_piece_bg(s));
	else if (zone == 3) // (je suis en bas a gauche de l'adversaire)
		return (place_piece_hd(s));
	else if (zone == 4) // (je suis en bas a droite de l'adversaire)
		return (place_piece_hg(s));
	//initstru(&(*s));
	return (0);
}

int 	main(int argc, char const **argv)
{
	int i;

	i = 0;
	struct s_stru s;
	int fd;
			
	initstru(&s);
	start_info(&s);
	player1(s);
	while (1)
	{
		s.countup = 0;
		s.countleft = 0;
		s.tour = 0;
		s.piece_x = 0;
		s.piece_y = 0;
		s.piece_x_ini = 0;
		s.piece_y_ini = 0;
		s.piece = NULL;
		new_info(&s);
		if (player1(s) == 1)
			return(0);
	}
	return 0;
}
