/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_world_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:33:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/04 21:13:53 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

	rooms = world->rooms;
	while (rooms)
	{
		if (rooms == world->start_room)
			ft_putendl("#start");
		if (rooms == world->end_room)
			ft_putendl("#end");
		room = rooms->content;
		ft_putstr(room->name);
		ft_putchar(' ');
		ft_putnbr(room->x);
		ft_putchar(' ');
		ft_putnbr(room->y);
		ft_putchar('\n');
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
