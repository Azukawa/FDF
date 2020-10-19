/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:04:00 by esukava           #+#    #+#             */
/*   Updated: 2020/10/19 21:03:55 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "_libft/libft.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

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
	int			**grid;
	int			gridx;
	int			gridy;
}						t_program;

int			diagonal_distance(int p0x, int p0y, int p1x, int p1y)
{
	float res;

	res = sqrt(pow((p0x - p1x), 2) + pow((p0y - p1y), 2));

	return(res);
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

void			ft_putintarr(int *arr, int x)
{
	int		i;
	i	=	0;
	while(i < x)
	{
		ft_putnbr(arr[i++]);
		ft_putchar(' ');
	}
}

//int			symbols_in_line()
//{
//
//}

int			*line_to_grid(char *line, int *grid, int *line_len)
{
	int i;
	int j;
	int a;
	char buf[50];
	int	ret[50];
	i = 0;
	j = 0;
	a = 0;
	while (line[i] != '\0')
	{
		if(line[i] != ' ')
			buf[j++] = line[i++];
		else
		{
			buf[j] = '\0';
			grid[a] = ft_atoi(buf);
			a++;
			i++;
			j = 0;
			ft_bzero(buf, 50);
		}
	}
	buf[j] = '\0';
    grid[a] = ft_atoi(buf);
    a++;
	*line_len = a;
//	ft_putintarr(grid, *line_len);
	return(NULL);
}

int			read_file(char *str, t_program *p)
{
	int		fd;
	int		ret;
	char	*output;
	int		i;

	i = 0;
	output = NULL;

	fd = open(str, O_RDONLY);
	while((ret = get_next_line(fd, &output)) > 0)
	{
		line_to_grid(output, p->grid[i], &p->gridx);
		free(output);
//		ft_putintarr(p->grid[i], p->line_len);
//		ft_putchar('Y');
//		ft_putchar('\n');
		i++;
	}
	p->gridy = i;
	return(0);
}

int		**init_grid()
{
	int **grid;
	int i;
	i = 0;

	grid = (int**)malloc(sizeof(int*) * 100000);
	while(i < 1000)
		grid[i++] = (int*)malloc(sizeof(int) * 100000);
	return(grid);
}

void	draw_left(t_program *p, int i, int j, int x, int y)
{
		p->end.x = x;		/*This block draws horizontal*/
		p->end.y = y - (p->grid[j][i] * 5);
		if(i > 0)
			draw_line(p);
		p->start.x = p->end.x;
		p->start.y = p->end.y;
	

}

void	draw_up(t_program *p, int i, int j, int x, int y)
{		
		int		temp_startx;
		int		temp_starty;
		int		temp_endx;
		int		temp_endy;

		temp_startx = p->start.x;
		temp_starty = p->start.y;
		temp_endx = p->end.x;
		temp_endy = p->end.y;
		
		p->end.x = x + 30;
		p->end.y = (y - 15) - (p->grid[j - 1][i] * 5);
		p->start.x = x;
		p->start.y = y - (p->grid[j][i] * 5);
			draw_line(p);

		
		p->start.x = temp_startx;
		p->start.y = temp_starty;
		p->end.x = temp_endx;
		p->end.y = temp_endx;	
	
}

void	draw_grid(t_program *p)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		origin;
	int		unit;
	
	unit = 30;
	origin = 200;
	x = origin;
	y = origin - 150;
	i = 0;
	j = 0;

	while(j < p->gridy)
	{
		while (i < p->gridx)
		{
			mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y, 0xFFFFFF);
		//	mlx_pixel_put(p->mlx_ptr, p->win_ptr, x, y + p->grid[j][i], p->color);
			
			if(j > 1)	
				draw_up(p, i, j, x, y);

			draw_left(p, i, j, x, y);



			x = x + unit;
			y = y + (unit / 2);
			i++;
		}
		y = (origin - 150) + (j * (unit / 2));
		x = origin - (j * unit);
		i = 0;
		j++;
	}
	ft_putstr("xxx");
}

int		main(int argc, char **argv)
{
	t_program	program;
	program.grid = init_grid();

	program.start.x = 250;
	program.start.y = 300;
	program.color = 0xffa500;	

	read_file(argv[1], &program);

	program.mlx_ptr = mlx_init();
	program.win_ptr = mlx_new_window(program.mlx_ptr, 1000, 700, "Dope!");

	draw_grid(&program);
//	mlx_key_hook(program.win_ptr, key_callback, &program);
	mlx_mouse_hook(program.win_ptr, mouse_callback, &program);
	mlx_loop(program.mlx_ptr);

}

