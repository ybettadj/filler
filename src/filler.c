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

int		put_coord(struct s_stru s, int i, int j)
{
	ft_putnbr(i - s.countup);
	ft_putchar(' ');
	ft_putnbr(j - s.countleft);
	ft_putchar('\n');
	return (0);
}

int		player1(struct s_stru s)
{
	int zone;

	zone = check_zone(s);
	cut_piece(&s);
	if (zone == 1)
		return (place_piece_bd(s));
	else if (zone == 2)
		return (place_piece_bg(s));
	else if (zone == 3)
		return (place_piece_hd(s));
	else if (zone == 4)
		return (place_piece_hg(s));
	return (0);
}

int		main(int argc, char const **argv)
{
	struct s_stru s;

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
			return (0);
	}
	return (0);
}
