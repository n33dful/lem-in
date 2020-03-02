/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_world_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:33:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/02 19:52:21 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	ft_print_edges(t_list *rooms)
{
	t_room	*room;
	t_edge	*edge;
	t_list	*edges;

	while (rooms)
	{
		room = rooms->content;
		edges = room->edges;
		while (edges)
		{
			edge = edges->content;
			printf("%s-%s\n", room->name, edge->to->name);
			edges = edges->next;
		}
		rooms = rooms->next;
	}
}

static void	ft_print_rooms(t_graph *world)
{
	t_list	*rooms;
	t_room	*room;

	room = world->start_room->content;
	printf("%s %d %d\n##start\n", room->name, room->x, room->y);
	room = world->end_room->content;
	printf("%s %d %d\n##end\n", room->name, room->x, room->y);
	rooms = world->rooms;
	while (rooms)
	{
		if (rooms != world->start_room && rooms != world->end_room)
		{
			room = rooms->content;
			printf("%s %d %d\n", room->name, room->x, room->y);
		}
		rooms = rooms->next;
	}
}

void		ft_world_print(t_graph *world)
{
	t_list	*rooms;
	t_room	*room;

	rooms = world->rooms;
	ft_putnbr(world->number_of_ants);
	ft_putchar('\n');
	ft_print_rooms(world);
	ft_print_edges(world->rooms);
}
