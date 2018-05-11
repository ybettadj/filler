/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 05:39:39 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/27 05:39:41 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

char 	**sub_piece(struct s_stru *s, char **tab, int b)
{
	int mark;
	int i;
	char **tab2;

	mark = 0;
	i = 0;
	tab2 = (char **)malloc(sizeof(char *) * (s->piece_x + 1));
	while(tab[i] && i < s->piece_x)
	{
		tab2[mark] = ft_strsub(tab[i], b, s->piece_y);
		mark++;
		i++;
	}
	return (tab2);
}

int 	cut_left(struct s_stru *s, char **tab)
{
	int i;
	int mark;

	i = 0;
	mark = 0;
	while (i < s->piece_x)
	{
		if (tab[i][0] == '*')
			mark++;
		i++;
	}
	if (mark == 0)
	{
		s->countleft++;
		s->piece_y = s->piece_y_ini - 1;
		s->piece = sub_piece(&(*s), tab, 1);
		return(1);
	}
	s->piece = tab;
	return (0);
}

int 	cut_right(struct s_stru *s, char **tab)
{
	int i;
	int mark;

	i = 0;
	mark = 0;
	while (i < s->piece_x)
	{
		if (tab[i][s->piece_y - 1] == '*')
			mark++;
		i++;
	}
	if (mark == 0)
		mark = -1;
	if (mark == -1)
	{
		s->piece_y--;
		s->piece = sub_piece(&(*s), tab, 0);
		return (1);
	}
	s->piece = tab;
	return (0);
}

char  	**cut_bottom_top(struct s_stru *s, int i, int x, char **tab)
{
	int j;
	int mark;

	j = 0;
	mark = 0;
	while (i < s->piece_x_ini)
	{
		while(j < s->piece_y_ini && i < s->piece_x_ini)
		{
			if (s->piece[i][j] == '*')
			{
				tab[x] = ft_strdup(s->piece[i]);
				i++;
				x += 1;
				j = -1;
				s->marker += 1;
			}
			j++;
		}
		if (s->marker == 0)
			s->countup++;
		i++;
		j = 0;
	}
	return (tab);
}

int 	cut_piece(struct s_stru *s)
{
	int i;
	int j;
	int x;
	char **tab;

	i = 0;
	j = 0;
	x = 0;
	s->marker = 0;
	tab = (char **)malloc(sizeof(char *) * (s->piece_x_ini + 1));
	s->piece = cut_bottom_top(&(*s), i, x, tab);
	s->piece_y = s->piece_y_ini;
	s->piece_x = s->marker;
	while (cut_left(&(*s),s->piece) != 0)
		i++;
	while (cut_right(&(*s),s->piece) != 0)
		i++;
	return (0);
}
