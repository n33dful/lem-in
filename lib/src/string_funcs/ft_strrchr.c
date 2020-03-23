/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:48:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 17:22:10 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if ((char)s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
