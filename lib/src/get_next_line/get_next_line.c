/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:18:27 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/19 21:48:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s || !(str = ft_strnew(len)))
		return (NULL);
	ft_strcpy(str, &s[start]);
	ft_strdel(&s);
	return (str);
}

static char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2 || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(s1), s2);
	ft_strdel(&s1);
	return (str);
}

static char	*read_line(const int fd, char *str)
{
	char	buf[GNL_BUF_SIZE + 1];
	int		ret;

	ret = 0;
	if (!str)
		str = ft_strnew(0);
	while (!ft_strchr(str, '\n') && (ret = read(fd, buf, GNL_BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin_free(str, buf);
	}
	if (ret < 0)
	{
		ft_strdel(&str);
		str = NULL;
	}
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*all[0];
	size_t		i;

	if (read(fd, NULL, 0) < 0 || !line || !(all[fd] = read_line(fd, all[fd])))
		return (-1);
	i = 0;
	while (all[fd][i] != '\n' && all[fd][i] != '\0')
		i++;
	if ((*line))
		ft_strdel(line);
	*line = ft_strsub(all[fd], 0, i);
	if (ft_strlen(all[fd]) == 0)
	{
		ft_strdel(&(all[fd]));
		return (0);
	}
	else if (all[fd][i] == '\0')
	{
		ft_strdel(&all[fd]);
		all[fd] = ft_strnew(0);
	}
	else
		all[fd] = ft_strsub_free(all[fd], i + 1, ft_strlen(all[fd] + i));
	return (1);
}
