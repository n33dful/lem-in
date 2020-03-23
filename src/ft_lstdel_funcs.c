/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contentdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:19:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:16:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_contentdel(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

void	ft_waydel(void *content, size_t content_size)
{
	t_direction	*way;

	if (content_size > 0)
	{
		way = content;
		ft_lstdel(&way->way, ft_contentdel);
		ft_memdel(&content);
	}
}

void	ft_bandwidthdel(void *content, size_t content_size)
{
	t_bandwidth	*bandwidth;

	if (content_size > 0)
	{
		bandwidth = content;
		ft_lstdel(&bandwidth->directions, ft_waydel);
		ft_memdel(&content);
	}
}

void	ft_roomdel(void *content, size_t content_size)
{
	t_room	*room;

	if (content_size > 0)
	{
		room = content;
		ft_strdel(&room->name);
		ft_lstdel(&room->edges, ft_contentdel);
		room->parent = NULL;
		ft_memdel(&content);
	}
}
