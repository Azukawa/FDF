/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:11 by esukava           #+#    #+#             */
/*   Updated: 2020/10/30 12:37:12 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		call_sec(t_program *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	draw_sec(p);
}

void		call_isom(t_program *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	draw_isom(p);
}

void		zoom(int k, t_program *p)
{
	if (k == 0 && p->unit >= 10)
	{
		p->unit = p->unit - 5;
		p->h_amp = (p->unit / 6) + p->scale;
		call_isom(p);
	}
	if (k == 6)
	{
		p->unit = p->unit + 5;
		p->h_amp = (p->unit / 6) + p->scale;
		call_isom(p);
	}
}

void		scale(int k, t_program *p)
{
	if (k == 1)
	{
		p->scale++;
		p->h_amp = (p->unit / 6) + p->scale;
		call_isom(p);
	}
	if (k == 7)
	{
		p->scale--;
		p->h_amp = (p->unit / 6) + p->scale;
		call_isom(p);
	}
}

int			key_callback(int keycode, t_program *p)
{
	static int	i;

	if (keycode == 1 || keycode == 7)
		scale(keycode, p);
	if (keycode == 0 || keycode == 6)
		zoom(keycode, p);
	if (keycode == 49)
	{
		if (i % 2 == 0)
			call_sec(p);
		else
			call_isom(p);
		i++;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
	}
	return (0);
}
