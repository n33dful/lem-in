/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:16:15 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 16:58:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (len > ft_strlen(src))
	{
		while ((unsigned char)src[i] != '\0')
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dst[i] = (unsigned char)src[i];
			i++;
		}
	}
	return (dst);
}
