/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:52:58 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/02 19:58:25 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_edgedel(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

static void	ft_roomdel(void *content, size_t content_size)
{
	t_room	*room;

	if (content_size > 0)
	{
		room = content;
		ft_strdel(&room->name);
		ft_lstdel(&room->edges, ft_edgedel);
	}
	ft_memdel(&content);
}

void		ft_graphdel(t_graph *graph)
{
	ft_lstdel(&graph->rooms, ft_roomdel);
	graph->start_room = NULL;
	graph->end_room = NULL;
}
