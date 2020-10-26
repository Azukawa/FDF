/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:42:32 by esukava           #+#    #+#             */
/*   Updated: 2020/07/23 13:22:56 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;
	unsigned char	cc;

	cc = (unsigned char)c;
	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (csrc[i] == cc)
		{
			cdst[i] = csrc[i];
			return (&cdst[i + 1]);
		}
		cdst[i] = csrc[i];
		i++;
	}
	return (NULL);
}
