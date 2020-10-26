/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:25:55 by esukava           #+#    #+#             */
/*   Updated: 2020/10/23 16:57:07 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	unit original value is 30;
**	h_amp original value is (unit / 6)
** ------------------------------------
*/

#include "fdf.h"

void		ft_error(char *str)
{
	ft_putstr("ERROR: ");
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}

int		check_filetype(char *str)
{
	int		i;

	i = 0;
	i = ft_strlen(str);
	i = i - 4;
	if (!ft_strcmp(&str[i], ".txt") || !ft_strcmp(&str[i], ".fdf"))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_program	p;

	if (argc != 2)
		ft_error("Need 1 and only 1 argument.");
	if (check_filetype(argv[1]) == 0)
		ft_error("Wrong filetype. Only .txt and .fdf accepted.");
	p.grid = init_grid();
	p.unit = 30;
	p.scale = 1;
	p.h_amp = (p.unit / 6) + p.scale;
	p.start.x = 250;
	p.start.y = 300;
	p.color = 0xffa500;
	p.resox = 1000;
	p.resoy = 700;
	p.origin = 500;
	if (read_file(argv[1], &p) == 0)
		ft_error("Map content incorrect or file non-existent!");
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, p.resox, p.resoy, "Virtual reality");
	draw_isom(&p);
	mlx_key_hook(p.win_ptr, key_callback, &p);
	mlx_loop(p.mlx_ptr);
}
