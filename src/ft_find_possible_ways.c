/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_falkerson_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:35:11 by sroland           #+#    #+#             */
/*   Updated: 2020/03/15 22:24:39 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	nulify_flow(t_graph *world)
{
	t_list		*room;
	t_list		*edge;

	room = world->rooms;
	while (room)
	{
		edge = ((t_room *)room->content)->edges;
		while (edge)
		{
			((t_edge *)edge->content)->flow = 0;
			((t_edge *)edge->content)->residual =
				((t_edge *)edge->content)->weight;
			edge = edge->next;
		}
		room = room->next;
	}
	return (1);
}

int	nulify_parents_and_is_visited(t_graph *world)
{
	t_list		*room;

	room = world->rooms;
	while (room)
	{
		((t_room *)room->content)->is_visited = 0;
		((t_room *)room->content)->parent = NULL;
		room = room->next;
	}
	return (0);
}

int	ft_find_possible_ways(t_data *data)
{
	t_list	*new;

	nulify_flow(&data->graph);
	nulify_parents_and_is_visited(&data->graph);
	while (bfs_find_next_path(&data->graph) == 1)
	{
		if (!(new = ft_calc(&data->graph)))
			return (0);
		ft_lstadd_back(&data->list_of_options, new);
	}
	return (1);
}
