/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 19:00:50 by student           #+#    #+#             */
/*   Updated: 2020/03/31 19:01:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_name(const char *name)
{
	size_t	i;

	i = 0;
	while (name[i])
	{
		if (name[i] < 33 || name[i] == '-' || name[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_edge_format(const char *line)
{
	int		exit_code;
	char	**arr;

	arr = NULL;
	exit_code = 1;
	if (ft_strchr(line, '-') != ft_strrchr(line, '-'))
		exit_code = 0;
	else if (!(arr = ft_strsplit(line, '-')))
		exit_code = 0;
	else if (!arr[0] || !ft_check_name(arr[0]))
		exit_code = 0;
	else if (!arr[1] || !ft_check_name(arr[1]))
		exit_code = 0;
	ft_arrdel((void *)(&arr));
	return (exit_code);
}

static int	ft_room_format(const char *line)
{
	int		exit_code;
	char	**arr;
	char	*ptr;

	arr = NULL;
	exit_code = 1;
	if (!(ptr = ft_strchr(line, ' ')))
		exit_code = 0;
	else if (!(ptr = ft_strchr(ptr + 1, ' ')))
		exit_code = 0;
	else if ((ptr = ft_strchr(ptr + 1, ' ')))
		exit_code = 0;
	else if (!(arr = ft_strsplit(line, ' ')))
		exit_code = 0;
	else if (!arr[0] || !ft_check_name(arr[0]))
		exit_code = 0;
	else if (!arr[1] || ft_isinteger(arr[1]) != 1)
		exit_code = 0;
	else if (!arr[2] || ft_isinteger(arr[2]) != 1)
		exit_code = 0;
	ft_arrdel((void *)(&arr));
	return (exit_code);
}

int			ft_read_line_format(const char *read_line)
{
	if (!read_line || read_line[0] == 'L')
		return (incorrect_format);
	else if (ft_room_format(read_line))
		return (room_format);
	else if (ft_edge_format(read_line))
		return (edge_format);
	else
		return (incorrect_format);
}
