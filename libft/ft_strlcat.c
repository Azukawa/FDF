/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:06:43 by esukava           #+#    #+#             */
/*   Updated: 2020/07/05 15:17:53 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;
	int		srclen;
	int		dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	i2 = 0;
	if (dstsize > 0)
	{
		while (dst[i] != '\0')
			i++;
		while (src[i2] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i2];
			i++;
			i2++;
		}
		dst[i] = '\0';
	}
	if ((int)dstsize <= dstlen)
		return (srclen + dstsize);
	return (srclen + dstlen);
}
