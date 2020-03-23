/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:45:01 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/06 19:59:21 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0 || !(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
