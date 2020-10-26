/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:34:49 by esukava           #+#    #+#             */
/*   Updated: 2020/07/24 16:36:28 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_findstart(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	return (i);
}

static int		ft_findend(char const *s)
{
	size_t	i;
	size_t	endcount;

	i = 0;
	endcount = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		endcount++;
	}
	return (endcount);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	startcount;
	size_t	endcount;
	size_t	strlen;
	char	*str;

	strlen = ft_strlen(s);
	endcount = ft_findend(s);
	startcount = ft_findstart(s);
	i = startcount;
	if (!s)
		return (NULL);
	if (startcount == strlen)
		return ("");
	if (s[startcount] == '\0')
		return (0);
	if (!(str = ft_strnew((strlen - (startcount + endcount)))))
		return (NULL);
	while (i < (strlen - endcount) && s[startcount] != '\0')
	{
		str[i - startcount] = s[i];
		i++;
	}
	str[i - startcount] = '\0';
	return (str);
}
