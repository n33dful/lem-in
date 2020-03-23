/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:28:13 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/08 18:50:21 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while ((unsigned char)haystack[i] != '\0' && i < len)
	{
		if ((unsigned char)haystack[i] == (unsigned char)needle[0])
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			{
				if (ft_strlen(needle) + i > len)
					i++;
				else
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
