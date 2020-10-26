/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:25:16 by esukava           #+#    #+#             */
/*   Updated: 2020/07/24 11:27:30 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	i2;
	char	*str;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	if (!(str = ft_strnew((len))))
		return (NULL);
	while (i2 < start)
		i2++;
	while (i < len)
	{
		str[i] = s[i2];
		i++;
		i2++;
	}
	return (str);
}
