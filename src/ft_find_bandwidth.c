/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bandwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:18:49 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_reset_active_directions(t_list *elem)
{
	t_direction	*way;

	if (elem)
	{
		way = elem->content;
		if (way)
			way->active = 1;
	}
}

t_list			*ft_find_bandwidth(t_graph *world)
{
	t_bandwidth	bandwidth;
	t_direction	*direction;
	int			turns_required;
	int			ants;

	if (!world)
		return (NULL);
	ants = world->total_ants;
	turns_required = 0;
	bandwidth.directions = ft_find_directions(world);
	while (ants)
	{
		ants -= ft_keep_best_directions(bandwidth.directions, ants);
		turns_required++;
	}
	ft_lstiter(bandwidth.directions, ft_reset_active_directions);
	direction = bandwidth.directions->content;
	turns_required += direction->len - 1;
	bandwidth.turns_required = turns_required;
	return (ft_lstnew(&bandwidth, sizeof(t_bandwidth)));
}
