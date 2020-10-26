/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:53:54 by esukava           #+#    #+#             */
/*   Updated: 2020/07/11 17:06:29 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (len)
		{
			len--;
			((char*)dst)[len] = ((char*)src)[len];
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
