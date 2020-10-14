/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:04:00 by esukava           #+#    #+#             */
/*   Updated: 2020/10/14 16:21:35 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../_libft/libft.h"
#include <math.h>

typedef struct			s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			p0x;
	int			p0y;
	int			p1x;
	int			p1y;

	int			color;
}						t_program;

int			diagonal_distance(t_program *p);
{
	float res;

	res = sprt(pow((p->p0x - p->p1x), 2) + pow((p->p0y - p->p1y), 2));

	return();
}



/**put this function in libftlibrary**/
int			ft_abs(int n)
{
	if(n < 0)
		n = n * -1;
	return(n);
}

int			draw_line(t_program *p)
{
	int		points = [];
	int		n = diagonal_distance(p)


}

int			deal_mouse(int lol, int x, int y,  t_program *p)
{

	mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, p->color++);
	p->mx = x;
	p->my = y;
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

