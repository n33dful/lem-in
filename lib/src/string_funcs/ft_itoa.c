/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:20:39 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/16 11:41:26 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_convert_to_str(int n, int i, char *str)
{
	if (n % 10 < 0)
		str[i] = (char)(-1 * (n % 10) % 10 + 48);
	else
		str[i] = (char)(n % 10 + 48);
	i--;
	n /= 10;
	while (n != 0)
	{
		if (n % 10 < 0)
			str[i] = (char)(-1 * (n % 10) % 10 + 48);
		else
			str[i] = (char)(n % 10 + 48);
		i--;
		n /= 10;
	}
}

static size_t	ft_numlen(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	size_t			size;
	char			*str;
	int				i;

	size = ft_numlen(n);
	if (!(str = ft_strnew(size + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		size++;
	}
	i = size - 1;
	ft_convert_to_str(n, i, str);
	str[size] = '\0';
	return (str);
}
