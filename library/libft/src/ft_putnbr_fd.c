/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:24:29 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/08 16:21:00 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num_fd(int n, int fd)
{
	if (n < -9 || n > 9)
	{
		print_num_fd(n / 10, fd);
		print_num_fd(n % 10, fd);
	}
	else
	{
		if (n < 0)
			ft_putchar_fd((char)(-1 * n + 48), fd);
		else
			ft_putchar_fd((char)(n + 48), fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	print_num_fd(n, fd);
}
