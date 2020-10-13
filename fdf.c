/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:04:00 by esukava           #+#    #+#             */
/*   Updated: 2020/10/13 17:03:07 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../_libft/libft.h"

typedef struct			s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			color;
	int			mx;
	int			my;

}						t_program;

int			deal_mouse(int lol, int x, int y,  t_program *p)
{
	p->mx = x;
	p->my = y;
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->mx, p->my, p->color++);
	return(0);

}

int			deal_key(int keycode, t_program *p)
{

	mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x++, p->y++, p->color++);
	ft_putnbr(p->x);
	ft_putchar('\n');
	return(0);
}

int		main()
{
	t_program	program;
	program.x = 250;
	program.y = 300;
	program.color = 0x808080;

	program.mlx_ptr = mlx_init();
	program.win_ptr = mlx_new_window(program.mlx_ptr, 500, 500, "Dope!");
//	mlx_pixel_put(program.mlx_ptr, program.win_ptr, 300, 250, 0xFFFFFF);
	mlx_key_hook(program.win_ptr, deal_key, &program);
	mlx_mouse_hook(program.win_ptr, deal_mouse, &program);
	mlx_loop(program.mlx_ptr);
}

