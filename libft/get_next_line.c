/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:18:48 by esukava           #+#    #+#             */
/*   Updated: 2020/10/16 15:44:52 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concat(char **line, char *buf)
{
	char		*temp;

	temp = NULL;
	if (*line == NULL)
		temp = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(*line, buf);
		ft_strdel(line);
	}
	*line = ft_strdup(temp);
	ft_strdel(&temp);
	return (*line);
}

int		seeknewline(const char *s)
{
	int			i;

	i = 0;
	if (s)
	{
		while (s[i] != '\n' && s[i] != '\0')
			i++;
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

int		gnlpt2(char **rem, char **line)
{
	int			n;
	char		*temp;

	if (*rem && *rem[0] != '\0')
	{
		if ((n = seeknewline(*rem)) == -1)
			*line = ft_strdup(*rem);
		else
		{
			*line = ft_strndup(*rem, n);
			if (*rem + n + 1 != '\0')
			{
				temp = ft_strdup(*rem + n + 1);
				ft_strdel(rem);
				*rem = ft_strdup(temp);
				ft_strdel(&temp);
			}
			else
				ft_strdel(rem);
			return (1);
		}
		ft_strdel(rem);
	}
	return (0);
}

int		gnlpt3(const int *fd, char **line, char **rem)
{
	int		n;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(*fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if ((n = seeknewline(buf)) == -1)
			*line = concat(line, buf);
		else
		{
			*rem = ft_strdup(buf + n + 1);
			buf[n] = '\0';
			*line = concat(line, buf);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *rem[FD_MAX];
	int			n;

	n = 0;
	if (fd < 0 || fd >= FD_MAX || line == NULL)
		return (-1);
	*line = NULL;
	if (gnlpt2(&rem[fd], line) == 1)
		return (1);
	ft_strdel(&rem[fd]);
	n = gnlpt3(&fd, line, &rem[fd]);
	if (n == 1 || n == -1)
		return (n);
	if (*line != NULL)
		return (1);
	return (0);
}
