/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:41:32 by esukava           #+#    #+#             */
/*   Updated: 2020/07/20 11:50:11 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		x;
	char	cc;

	cc = (char)c;
	x = ft_strlen(s);
	s = s + x;
	while (*s != cc)
	{
		if (x == 0)
			return (NULL);
		s--;
		x--;
	}
	return ((char *)s);
}
