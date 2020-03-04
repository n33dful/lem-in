/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_falkerson_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:35:11 by sroland           #+#    #+#             */
/*   Updated: 2020/03/04 22:22:23 by sroland          ###   ########.fr       */
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
			((t_edge *)edge->content)->flow = 0;
			((t_edge *)edge->content)->residual =
				((t_edge *)edge->content)->weight;
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
		room = room->next;
	}
	return (0);
}

int			ford_falkerson(t_graph *world)
{
	int		i;

	i = 0;
	nulify_flow(world);
	nulify_parents_and_is_visited(world);
	printf("starting iterations\n");
	while (bfs_find_next_path(world) == 1)
	{
		i++;
		printf("i = %10d\n", i);
	}
	return (i);
}
