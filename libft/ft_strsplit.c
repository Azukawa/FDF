/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:20:47 by esukava           #+#    #+#             */
/*   Updated: 2020/07/24 11:50:10 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **x)
{
	size_t	i;

	i = 0;
	while (x)
	{
		free(x[i]);
		i++;
	}
	free(x);
	return ;
}

static char	**ft_strsplitpt2(char **x, char const *s, char c)
{
	int		stri;
	int		strlen;
	int		i;

	i = 0;
	stri = 0;
	strlen = 0;
	while (s[stri])
	{
		if (s[stri++] != c)
			strlen++;
		if ((s[stri] == c && strlen > 0) || (s[stri] == '\0' && strlen > 0))
		{
			if (!(x[i++] = ft_strsub(s, stri - strlen, strlen)))
			{
				ft_free(x);
				return (NULL);
			}
			stri++;
			strlen = 0;
		}
		if (s[stri] == c && strlen < 1)
			stri++;
	}
	return (x);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wrds;
	char	**x;

	wrds = ft_countwords(s, c);
	s = ft_strctrim(s, c);
	if (!s)
		return (NULL);
	if (!(x = (char**)malloc(sizeof(char*) * (wrds) + 1)))
		return (NULL);
	x[wrds] = NULL;
	if (!(x = ft_strsplitpt2(x, s, c)))
		ft_free(x);
	return (x);
}
