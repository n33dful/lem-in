/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_search_tools.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by sroland           #+#    #+#             */
/*   Updated: 2020/03/31 18:58:49 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				delete_first_room(t_list **queue)
{
	t_list		*tmp;

	tmp = *queue;
	(*queue) = (*queue)->next;
	free(tmp);
}

t_room				*room_out(t_room *room)
{
	t_list			*edge;

	edge = room->edges;
	while (edge)
	{
		if (((t_edge *)edge->content)->flow == 1)
			return (((t_edge *)edge->content)->leads_to);
		edge = edge->next;
	}
	return (NULL);
}

int					room_inflow(t_room *room)
{
	t_list			*edge;
	int				count;

	edge = room->edges;
	count = 0;
	while (edge)
	{
		if (((t_edge *)edge->content)->flow == -1)
			count++;
		else if (((t_edge *)edge->content)->leads_to == room->parent &&
			((t_edge *)edge->content)->flow == 1)
			count--;
		edge = edge->next;
	}
	return (count);
}
