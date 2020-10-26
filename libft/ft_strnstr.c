/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:45 by esukava           #+#    #+#             */
/*   Updated: 2020/07/16 16:23:39 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t x;

	i = 0;
	x = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0' && ((i + x) < len))
	{
		i = 0;
		while (haystack[x + i] == needle[i] && (i + x) < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[x]);
		}
		x++;
	}
	return (NULL);
}
