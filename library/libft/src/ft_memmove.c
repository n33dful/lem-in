/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:57:31 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 17:36:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	if (src == dst)
		return (dst);
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (src > dst)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			dst2[i] = src2[i];
	}
	return (dst);
}
