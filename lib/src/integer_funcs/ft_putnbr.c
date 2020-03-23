/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:30:24 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/07 21:02:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num(int n)
{
	if (n < -9 || n > 9)
	{
		print_num(n / 10);
		print_num(n % 10);
	}
	else
	{
		if (n < 0)
			ft_putchar((char)(-1 * n + 48));
		else
			ft_putchar((char)(n + 48));
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	print_num(n);
}
