/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_falkerson_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:35:11 by sroland           #+#    #+#             */
/*   Updated: 2020/03/08 19:59:38 by cdarci           ###   ########.fr       */
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

void		algo_magic(t_graph *world)
{
	t_calc	*calc;

	calc = ft_calc(world);
	printf("ants will pass it for %d turn(s)\n", calc->turns);
	ft_push_ants(calc, world);
	//ft_lstdel(&calc->roads, ft_roomdel);
	free(calc);
}

int			ford_falkerson(t_graph *world)
{
	int		i;

	i = 0;
	nulify_flow(world);
	nulify_parents_and_is_visited(world);
	printf("\n\nstarting iterations\n");
	while (bfs_find_next_path(world) == 1)
	{
		i++;
		algo_magic(world);
	}
	return (i);
}
