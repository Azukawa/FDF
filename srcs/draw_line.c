/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:21:01 by esukava           #+#    #+#             */
/*   Updated: 2020/10/20 18:27:28 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			diagonal_distance(int p0x, int p0y, int p1x, int p1y)
{
	float res;

	res = sqrt(pow((p0x - p1x), 2) + pow((p0y - p1y), 2));
	return (res);
}

float		lerp_1d(float start, float end, float t)
{
	return (start + t * (end - start));
}

t_point_2d	lerp_2d(t_point_2d start, t_point_2d end, float t)
{
	t_point_2d ret;

	ret.x = lerp_1d(start.x, end.x, t);
	ret.y = lerp_1d(start.y, end.y, t);
	return (ret);
}

void		round_point(float *x, float *y)
{
	*x = round(*x);
	*y = round(*y);
}

void		draw_line(t_program *p)
{
	float		n;
	float		step;
	float		t;
	t_point_2d	ret0;

	n = diagonal_distance(p->start.x, p->start.y, p->end.x, p->end.y);
	t = 0;
	step = 0;
	while (step <= n)
	{
		if (n == 0)
			t = 0.0;
		else
			t = step / n;
		ret0 = lerp_2d(p->start, p->end, t);
		round_point(&ret0.x, &ret0.y);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, ret0.x, ret0.y, p->color);
		step++;
	}
}
