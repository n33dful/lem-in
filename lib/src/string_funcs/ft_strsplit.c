/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:46:56 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 17:20:37 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static size_t	ft_w_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char		*ft_copyandmove(const char **s, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		new[i++] = *((*s)++);
	new[i] = '\0';
	return (new);
}

static char		**ft_error(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (ft_w_count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c && *s)
			s++;
		else if (!(arr[i++] = ft_copyandmove(&s, ft_w_len(s, c))))
			return (ft_error(arr, i - 1));
	}
	arr[i] = NULL;
	return (arr);
}
