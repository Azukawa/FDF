/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:56:51 by esukava           #+#    #+#             */
/*   Updated: 2020/07/24 11:27:04 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*str;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i2] != '\0')
	{
		str[i] = s1[i2];
		i++;
		i2++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		str[i] = s2[i2];
		i++;
		i2++;
	}
	return (str);
}
