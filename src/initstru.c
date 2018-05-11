/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstru.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 23:26:24 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/26 23:26:25 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void 	initstru(struct s_stru *s)
{
	s->info = NULL;

	s->map = NULL;
	s->map_size_x = 0;
	s->map_size_y = 0;	

	s->piece = NULL;
	s->piece_x = 0;
	s->piece_y = 0;
	s->piece_x_ini = 0;
	s->piece_y_ini = 0;
	s->countleft = 0;
	s->countup = 0;
	s->good = 0;

	s->count_zone = 0;

	s->player = 0;

	s->stop = 0;
}
