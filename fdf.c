/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:04:00 by esukava           #+#    #+#             */
/*   Updated: 2020/10/12 19:21:24 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../_libft/libft.h"

typedef struct			s_program
{
	void		*mlx_ptr;
	void		*win_ptr;

}						t_program;

int			deal_key(int key, void *param)
{
	static int		x = 250;
	static int		y = 250;

	mlx_pixel_put(program->mlx_ptr, program->win_ptr, 300, 250, 0xFFFFFF);
	ft_putchar('x');
	return(0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Dope!");
	mlx_pixel_put(program->mlx_ptr, program->win_ptr, 300, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}

