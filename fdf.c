/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:04:00 by esukava           #+#    #+#             */
/*   Updated: 2020/10/15 18:27:14 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../_libft/libft.h"
#include <math.h>

typedef struct			s_point_2d
{
	float 	x;
	float	y;
}						t_point_2d;

typedef struct			s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point_2d	start;
	t_point_2d	end;
	int			color;
}						t_program;

int			diagonal_distance(int p0x, int p0y, int p1x, int p1y)
{
	float res;

	res = sqrt(pow((p0x - p1x), 2) + pow((p0y - p1y), 2));

	return(res);
}

/**put this function in libftlibrary**/
int			ft_abs(int n)
{
	if(n < 0)
		n = n * -1;
	return(n);
}

float			lerp_1d(float start, float end,  float t)
{
	return(start + t * (end - start));
}

t_point_2d			lerp_2d(t_point_2d start, t_point_2d end, float t)
{
	t_point_2d ret;
	
	ret.x = lerp_1d(start.x, end.x, t);
	ret.y = lerp_1d(start.y, end.y, t);
	
	return(ret);
}

void			round_point(float *x, float *y)
{
	*x = round(*x);
	*y = round(*y);
}

void			draw_line(t_program *p)
{
	float		n = diagonal_distance(p->start.x, p->start.y, p->end.x, p->end.y);
	float		step;
	float		t;
	t_point_2d	ret0;

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
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, ret0.x, ret0.y, p->color++);
		step++;
	}
}

int			mouse_callback(int button, int x, int y,  t_program *p)
{
	p->end.x = x;
	p->end.y = y;
	draw_line(p);
	p->start.x = x;
	p->start.y = y;
	return(0);
}

int			key_callback(int keycode, t_program *p)
{

	mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->start.x++, p->start.y++, p->color++);
	ft_putchar('\n');
	return(0);
}

int		main()
{
	t_program	program;

	program.start.x = 250;
	program.start.y = 300;
	program.color = 0x000000;

	program.mlx_ptr = mlx_init();
	program.win_ptr = mlx_new_window(program.mlx_ptr, 500, 500, "Dope!");
//	mlx_pixel_put(program.mlx_ptr, program.win_ptr, 300, 250, 0xFFFFFF);
	mlx_key_hook(program.win_ptr, key_callback, &program);
	mlx_mouse_hook(program.win_ptr, mouse_callback, &program);
	mlx_loop(program.mlx_ptr);
}

