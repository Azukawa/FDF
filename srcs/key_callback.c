/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:11 by esukava           #+#    #+#             */
/*   Updated: 2020/10/20 18:28:48 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_callback(int keycode, t_program *p)
{
	static int		i;

	if (keycode == 49)
	{
		if (i % 2 == 0)
		{
			mlx_clear_window(p->mlx_ptr, p->win_ptr);
			draw_sec(p);
		}
		else
		{
			mlx_clear_window(p->mlx_ptr, p->win_ptr);
			draw_isom(p);
		}
		i++;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
	}
	return (0);
}
