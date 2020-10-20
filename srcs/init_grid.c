/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:22:54 by esukava           #+#    #+#             */
/*   Updated: 2020/10/20 18:28:26 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**init_grid(void)
{
	int **grid;
	int i;

	i = 0;
	grid = (int**)malloc(sizeof(int*) * 100000);
	while (i < 1000)
		grid[i++] = (int*)malloc(sizeof(int) * 100000);
	return (grid);
}
