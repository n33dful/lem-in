/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_atns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by sroland           #+#    #+#             */
/*   Updated: 2020/03/31 18:58:49 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_add_ants(t_graph *world, char *line, int *step)
{
	if (ft_isinteger(line) != 1)
		return (0);
	if (!ft_isdigit(line[ft_strlen(line) - 1]))
		return (0);
	world->total_ants = ft_atoi(line);
	if (world->total_ants <= 0)
		return (0);
	*step = 1;
	return (1);
}
