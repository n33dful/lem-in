/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:19:28 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/12 13:06:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && (unsigned char)s1[i] != '\0' &&\
	(unsigned char)s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
