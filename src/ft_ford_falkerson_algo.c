/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_falkerson_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:35:11 by sroland           #+#    #+#             */
/*   Updated: 2020/03/04 21:20:12 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			nulify_flow(t_graph *world)
{
	t_list		*room;
	t_list		*edge;

	room = world->rooms;
	while (room)
	{
		edge = ((t_room *)room->content)->edges;
		while (edge)
		{
			((t_edge *)edge)->flow = 0;
			((t_edge *)edge)->residual = ((t_edge *)edge)->weight;
			edge = edge->next;
		}
		room = room->next;
	}
	return (1);
}

int			nulify_parents_and_is_visited(t_graph *world)
{
	t_list		*room;

	room = world->rooms;
	while (room)
	{
		((t_room *)room->content)->is_visited = 0;
		((t_room *)room->content)->parent = NULL;
	}
	return (0);
}

int			ford_falkerson(t_graph *world)
{
	int		i;

	i = 0;
	nullify_flow(world);
	nulify_parents_and_is_visited(world);
	while (bfs_find_next_path(world) == 1)
		i++;
	return (i);
}
