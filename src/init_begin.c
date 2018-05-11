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

int 	which_player(struct s_stru s)
{
	if (s.info1[10] == '1')
		return (1);
	else
		return (2);
}

int 	size_map_x(struct s_stru s)
{
	int i;
	int k;
	char *str;
	int size;

	i = 0;
	k = 0;
	size = 0;
	str = ft_strnew(6);

	while (ft_isdigit(s.info1[i]) != 1)	
		i++;
	while (ft_isdigit(s.info1[i]) == 1)
		str[k++] = s.info1[i++];
	size = ft_atoi(str);
	return (size);
}

int 	size_map_y(struct s_stru s)
{
	int i;
	int k;
	char *str;
	int size;
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
	return (size);
}

int 	size_piece_x(struct s_stru s)
{
	int i;
	int k;
	char *str;
	int size;

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
	return (size);
}

int 	size_piece_y(struct s_stru s)
{
	int i;
	int k;
	char *str;
	int size;

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
	return (size);
}

int 	start_info(struct s_stru *s)
{
	char	*line;
	char	**tab;
	int mark;
	int fd;
	int i;
	int x;

	i = 0;
	x = 0;
	mark = 0;
	while (get_next_line(0, &line) > 0)
	{
		s->info1 = line;
		if (s->tour == 0 )
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
		if (s->tour == 1)
		{
			s->map_size_x = size_map_x(*s);
			s->map_size_y = size_map_y(*s);
			s->map = (char **)malloc(sizeof(s->map) * (s->map_size_x + 2));
		}
		if (s->tour >= 3 && s->tour < s->map_size_x + 3)
		{
			s->map[i] = ft_strsub(s->info1, 4, s->map_size_y + 1);
			i++;
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
			s->piece[x] = ft_strdup(s->info1);
			x++;
		}
		mark++;
		s->tour++;
		if (s->tour > s->piece_x_ini + s->map_size_x + 3 && s->piece_x_ini != 0)
			return (0);
	}
	return (0);
}

/*	**start_info(const char **argv)
{
	char	*line;
	char	**tab;
	int fd;
	int i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	tab = (char **)malloc(sizeof(tab) * (i + 1));
	fd = open(argv[1], O_RDONLY);
	ft_strdel(&line);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		tab[i++] = ft_strdup(line);
	return (tab);
}*/
