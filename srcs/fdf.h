/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:19:18 by esukava           #+#    #+#             */
/*   Updated: 2020/10/30 18:06:18 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct			s_point
{
	int		x;
	int		y;
	int		i;
	int		j;
}						t_point;

typedef struct			s_point_2d
{
	float	x;
	float	y;
}						t_point_2d;

typedef struct			s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point_2d	start;
	t_point_2d	end;
	int			color;
	int			**grid;
	int			gridx;
	int			gridy;
	int			unit;
	int			h_amp;
	int			resox;
	int			resoy;
	int			origin;
	int			scale;
	int			keyi;
}						t_program;

void					draw_isom(t_program *p);
void					draw_sec(t_program *p);
void					draw_line(t_program *p);
int						**init_grid(void);
int						key_callback(int keycode, t_program *p);
int						read_file(char *str, t_program *p);
#endif
