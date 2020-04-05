/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/31 18:58:49 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	ft_coordinate_matches(int x, int y, t_list *start_ptr)
{
	t_room	*room;
	size_t	count;

	count = 0;
	while (start_ptr)
	{
		room = start_ptr->content;
		if (room->x == x && room->y == y)
			count++;
		start_ptr = start_ptr->next;
	}
	return (count);
}

static int		ft_check_coordinates(t_list *rooms)
{
	t_room	*room;
	t_list	*start_ptr;

	start_ptr = rooms;
	while (rooms)
	{
		room = rooms->content;
		if (ft_coordinate_matches(room->x, room->y, start_ptr) > 1)
			return (0);
		rooms = rooms->next;
	}
	return (1);
}

int				ft_check_graph(t_data *data)
{
	if (data->graph.total_ants <= 0)
		return (0);
	if (!data->graph.start_room || !data->graph.end_room)
		return (0);
	if (!data->graph.rooms)
		return (0);
	if (!ft_check_coordinates(data->graph.rooms))
		return (0);
	return (1);
}
