/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:44:52 by esukava           #+#    #+#             */
/*   Updated: 2020/07/23 12:27:23 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t x;

	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		x = 0;
		while (*(needle + x) == *(haystack + x))
		{
			x++;
			if (!(*(needle + x)))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
