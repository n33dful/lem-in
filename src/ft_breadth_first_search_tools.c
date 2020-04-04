/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_search_tools.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konstantinzakharov <konstantinzakharov@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:59:46 by sroland           #+#    #+#             */
/*   Updated: 2020/04/04 03:00:36 by konstantinz      ###   ########.fr       */
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
