/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:02:10 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/12 12:31:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1);
	if (n > ft_strlen(s2))
	{
		while ((unsigned char)s2[i] != '\0')
		{
			s1[i + size] = (unsigned char)s2[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			s1[i + size] = (unsigned char)s2[i];
			i++;
		}
	}
	s1[i + size] = '\0';
	return (s1);
}
