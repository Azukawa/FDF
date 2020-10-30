/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:22:11 by esukava           #+#    #+#             */
/*   Updated: 2020/10/29 11:43:26 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putintarr(int *arr, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		ft_putnbr(arr[i++]);
		ft_putchar(' ');
	}
}

int			line_to_grid(char *line, int *grid, int *line_len)
{
	t_point xy;
	char	buf[25];

	xy.i = 0;
	xy.j = 0;
	xy.x = 0;
	while (line[xy.i] != '\0')
	{
		if (xy.j > 25)
			return (0);
		if (line[xy.i] != ' ' && xy.j <= 25)
			buf[xy.j++] = line[xy.i];
		else if (line[xy.i - 1] != ' ')
		{
			buf[xy.j] = '\0';
			grid[xy.x++] = ft_atoi1000(buf);
			xy.j = 0;
			ft_bzero(buf, 25);
		}
		xy.i++;
	}
	buf[xy.j] = '\0';
	grid[xy.x++] = ft_atoi1000(buf);
	*line_len = xy.x;
	return (1);
}

int			read_file(char *str, t_program *p)
{
	int		fd;
	int		ret;
	char	*output;
	int		i;

	i = 0;
	output = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		if (line_to_grid(output, p->grid[i], &p->gridx) == 0)
		{
			free(output);
			return (0);
		}
		free(output);
		i++;
	}
	p->gridy = i;
	return (1);
}
