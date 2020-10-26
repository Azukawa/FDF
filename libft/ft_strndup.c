/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:55:57 by esukava           #+#    #+#             */
/*   Updated: 2020/08/14 11:45:53 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (s1[i] != '\0' && n)
	{
		s2[i] = s1[i];
		i++;
		n--;
	}
	s2[i] = '\0';
	return (s2);
}
