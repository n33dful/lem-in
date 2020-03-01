/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:29:43 by sroland           #+#    #+#             */
/*   Updated: 2020/03/01 20:47:35 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_number(char *str)
{
	int			flag;

	flag = 0;
	while (*str != '\0')
	{
		if (!(*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ' ||
			*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
			return (0);
		if (flag == 0 && ft_isdigit(*str))
			flag = 2;
		if (flag == 1 && !(*str >= '0' && *str <= '9'))
			return (0);
		else if (flag == 1)
			flag = 2;
		if (*str == '-' || *str == '+')
			flag = 1;
		str++;
	}
	return (flag == 2 ? 1 : 0);
}

int				ft_atoi_status(char **str, int *result)
{
	int					sign;
	long long int		res;

	sign = 1;
	res = 0;
	while (ft_isspace((int)**str) != 0)
		(*str)++;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		(*str)++;
		sign = -1;
	}
	while (ft_isdigit(**str) != 0)
	{
		res = res * 10 + sign * (**str - '0');
		(*str)++;
		if (res > INT_MAX || res < INT_MIN)
			return (-1);
	}
	*result = (int)res;
	return ((ft_isspace(**str) || **str == '\0') ? 0 : -1);
}
