/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 06:32:50 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/26 06:32:51 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		newtour(struct s_stru *s, int *i)
{
	if (s->tour == 0)
	{
		s->map_size_x = size_map_x(*s);
		s->map_size_y = size_map_y(*s);
		s->map = (char **)malloc(sizeof(char *) * (s->map_size_x + 1));
	}
	if (s->tour >= 2 && s->tour < s->map_size_x + 2)
	{
		s->map[*i] = ft_strsub(s->info1, 4, s->map_size_y + 1);
		*i += 1;
	}
	if (s->tour == s->map_size_x + 2)
	{
		s->piece_x_ini = size_piece_x(*s);
		s->piece_y_ini = size_piece_y(*s);
		s->piece = (char **)malloc(sizeof(char *) * (s->piece_x_ini + 1));
	}
}

void		new_info(struct s_stru *s)
{
	char	*line;
	char	**tab;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (get_next_line(0, &line) > 0)
	{
		s->info1 = line;
		newtour(&(*s), &i);
		if (s->tour > s->map_size_x + 2 &&
			s->tour <= s->map_size_x + s->piece_x_ini + 2)
		{
			s->piece[x] = ft_strdup(s->info1);
			x++;
		}
		s->tour++;
		if (s->tour > s->piece_x_ini + s->map_size_x + 2 && s->piece_x_ini != 0)
		{
			ft_strdel(&line);
			break ;
		}
	}
}
