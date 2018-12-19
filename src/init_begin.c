/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_begin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 05:49:58 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/26 05:50:00 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		which_player(struct s_stru s)
{
	int i;

	i = ft_strlen(s.info1);
	if (i >= 10 && s.info1[10] == '1')
		return (1);
	else
		return (2);
}

void	tour0(struct s_stru *s)
{
	if (s->tour == 0)
	{
		s->player = which_player(*s);
		if (s->player == 1)
		{
			s->c = 'O';
			s->a = 'X';
		}
		else
		{
			s->c = 'X';
			s->a = 'O';
		}
	}
}

void	othertour(struct s_stru *s, int *i, int *x)
{
	if (s->tour == 1)
	{
		s->map_size_x = size_map_x(*s);
		s->map_size_y = size_map_y(*s);
		s->map = (char **)malloc(sizeof(s->map) * (s->map_size_x + 2));
	}
	if (s->tour >= 3 && s->tour < s->map_size_x + 3)
	{
		s->map[*i] = ft_strsub(s->info1, 4, s->map_size_y + 1);
		*i += 1;
	}
	if (s->tour == s->map_size_x + 3)
	{
		s->piece_x_ini = size_piece_x(*s);
		s->piece_y_ini = size_piece_y(*s);
		s->piece = (char **)malloc(sizeof(s->piece) * (s->piece_x_ini + 2));
	}
	if (s->tour > s->map_size_x + 3 &&
			s->tour <= s->map_size_x + s->piece_x_ini + 3)
	{
		s->piece[*x] = ft_strdup(s->info1);
		*x += 1;
	}
}

int		start_info(struct s_stru *s)
{
	char	*line;
	int		i;
	int		x;
	char	*tmp;

	i = 0;
	x = 0;
	tmp = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		tmp = s->info1;
		s->info1 = line;
		free(tmp);
		tour0(&(*s));
		othertour(&(*s), &i, &x);
		s->tour++;
		if (s->tour > s->piece_x_ini + s->map_size_x + 3 && s->piece_x_ini != 0)
			return (0);
	}
	return (0);
}
