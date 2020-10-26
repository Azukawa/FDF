/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:34:49 by esukava           #+#    #+#             */
/*   Updated: 2020/07/24 12:11:10 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_findstart(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] == c)
	{
		i++;
	}
	return (i);
}

static int		ft_findend(char const *s, char c)
{
	int		i;
	int		endcount;

	i = 0;
	endcount = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == c)
	{
		i--;
		endcount++;
	}
	return (endcount);
}

char			*ft_strctrim(char const *s, char c)
{
	size_t	i;
	size_t	i2;
	size_t	startcount;
	size_t	endcount;
	char	*str;

	i = 0;
	i2 = 0;
	startcount = ft_findstart(s, c);
	i = startcount;
	if (!s)
		return (NULL);
	if (s[i] == '\0')
		return (ft_strnew(0));
	endcount = ft_findend(s, c);
	if (startcount == 0 && endcount == 0)
		return (str = ft_strdup(s));
	str = ft_strnew((ft_strlen(s) - (startcount + endcount)));
	while (i < (ft_strlen(s) - endcount))
		str[i2++] = s[i++];
	return (str);
}
