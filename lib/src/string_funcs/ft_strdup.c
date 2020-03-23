/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:39:42 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/06 19:34:05 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	char	*link;
	int		i;

	i = 0;
	lenght = ft_strlen(s1);
	if (!(link = ft_strnew(lenght)))
		return (NULL);
	while (s1[i] != '\0')
	{
		link[i] = s1[i];
		i++;
	}
	link[i] = '\0';
	return (link);
}
