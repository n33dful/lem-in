/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:05:59 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 16:52:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t res;
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(dst);
	res = ft_strlen(src);
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (res);
}
