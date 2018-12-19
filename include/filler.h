/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 02:31:53 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/26 02:31:55 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct	s_stru
{
	char	**info;
	char	*info1;

	char	**map;
	int		map_size_x;
	int		map_size_y;	

	char	**piece;
	int 	piece_x;
	int 	piece_y;
	int 	piece_x_ini;
	int 	piece_y_ini;
	int 	countleft;
	int 	countup;
	
	int		count_zone;

	int 	player;

	char 	c;
	char	a;

	int 	stop;
	int 	tour;
	int 	marker;

}				t_stru;

void 	initstru(struct s_stru *s);
int 	start_info(struct s_stru *s);
void 	new_info(struct s_stru *s);
int 	which_player(struct s_stru s);
int 	size_map_x(struct s_stru s);
int 	size_map_y(struct s_stru s);
int 	size_piece_x(struct s_stru s);
int 	size_piece_y(struct s_stru s);

int 	check_zone1(struct s_stru s);
int 	check_zone2(struct s_stru s);
int 	check_zone3(struct s_stru s);
int 	check_zone4(struct s_stru s);
int 	check_zone(struct s_stru s);
int		cut_piece(struct s_stru *s);
int 	cut_right(struct s_stru *s, char **tab);
int 	cut_left(struct s_stru *s, char **tab);
int		check_pieceonmap(struct s_stru s, int i, int j, int *same);
int		place_piece_hd(struct s_stru s);
int		place_piece_bd(struct s_stru s);
int		place_piece_hg(struct s_stru s);
int		place_piece_bg(struct s_stru s);
int		put_coord(struct s_stru s, int i, int j);
int		size_map_x(struct s_stru s);
int		size_map_y(struct s_stru s);
int		size_piece_x(struct s_stru s);
int		size_piece_y(struct s_stru s);


#endif
