/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:23:36 by esukava           #+#    #+#             */
/*   Updated: 2020/10/31 10:42:24 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_left_isom(t_program *p, t_point xy)
{
	p->end.x = xy.x;
	p->end.y = xy.y - (p->grid[xy.j][xy.i] * p->h_amp);
	if (xy.i > 0)
		draw_line(p);
	p->start.x = p->end.x;
	p->start.y = p->end.y;
}

void	draw_up_isom(t_program *p, t_point xy)
{
	int		temp_startx;
	int		temp_starty;
	int		temp_endx;
	int		temp_endy;

	temp_startx = p->start.x;
	temp_starty = p->start.y;
	temp_endx = p->end.x;
	temp_endy = p->end.y;
	p->end.x = xy.x + p->unit;
	p->end.y = (xy.y - (p->unit / 2)) - (p->grid[xy.j - 1][xy.i] * p->h_amp);
	p->start.x = xy.x;
	p->start.y = xy.y - (p->grid[xy.j][xy.i] * p->h_amp);
	draw_line(p);
	p->start.x = temp_startx;
	p->start.y = temp_starty;
	p->end.x = temp_endx;
	p->end.y = temp_endy;
}

void	draw_isom(t_program *p)
{
	t_point xy;

	xy.x = p->origin;
	xy.y = p->origin - 450;
	xy.i = 0;
	xy.j = 0;
	while (xy.j < p->gridy)
	{
		while (xy.i < p->gridx)
		{
			if (xy.j > 0)
				draw_up_isom(p, xy);
			draw_left_isom(p, xy);
			xy.x = xy.x + p->unit;
			xy.y = xy.y + (p->unit / 2);
			xy.i++;
		}
		xy.y = (p->origin - 450) + ((xy.j + 1) * (p->unit / 2));
		xy.x = p->origin - ((xy.j + 1) * p->unit);
		xy.i = 0;
		xy.j++;
	}
}
