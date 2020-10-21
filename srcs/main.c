/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:55 by esukava           #+#    #+#             */
/*   Updated: 2020/10/21 14:41:26 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	unit original value is 30;
**	h_amp original value is (unit / 6)
** ------------------------------------
*/

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_program	p;

	p.grid = init_grid();
	p.unit = 20;
	p.scale = 1;
	p.h_amp = (p.unit / 6) + p.scale;
	p.start.x = 250;
	p.start.y = 300;
	p.color = 0xffa500;
	p.resox = 1000;
	p.resoy = 700;
	p.origin = 500;
	read_file(argv[1], &p);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, p.resox, p.resoy, "Virtual reality");
	draw_isom(&p);
	mlx_key_hook(p.win_ptr, key_callback, &p);
	mlx_loop(p.mlx_ptr);
}
