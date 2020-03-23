/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:45:27 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 16:49:25 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_point(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	return (i);
}

static size_t	ft_end_point(char const *s)
{
	size_t	len;
	size_t	i;

	if (!s || !(len = ft_strlen(s)))
		return (0);
	i = len - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_end_point(s);
	start = ft_start_point(s);
	if (!s || !(result = ft_strnew(start <= end ? end - start + 1 : 0)))
		return (NULL);
	while (start <= end)
		result[i++] = (char)s[start++];
	result[i] = '\0';
	return (result);
}
