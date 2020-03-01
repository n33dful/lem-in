/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_world_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:33:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/01 20:20:05 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void		ft_print_room(t_list *rooms)
{
	t_room	*room;

	room = rooms->content;
	printf("%s %d, %d\n", room->name, room->x, room->y);
}

void		ft_world_print(t_graph *world)
{
	t_list	*rooms;
	t_room	*room;

	rooms = world->rooms;
	ft_putnbr((int)world->number_of_ants);
	ft_putchar('\n');
	ft_putendl("##start");
	ft_lstiter(world->rooms, ft_print_room);
}
