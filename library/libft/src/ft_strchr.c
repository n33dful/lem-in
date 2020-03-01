/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:44:11 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 17:34:31 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while ((char)s[i] != '\0')
	{
		if ((char)s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
