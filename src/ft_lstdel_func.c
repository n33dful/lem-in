/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:19:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:16:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstdel_func(void *content, size_t content_size)
{
	if (content_size > 0)
	{
		if (content_size == sizeof(t_way))
			ft_lstdel(&((t_way *)content)->direction, ft_lstdel_func);
		if (content_size == sizeof(t_bandwidth))
			ft_lstdel(&((t_bandwidth *)content)->roads, ft_lstdel_func);
		ft_memdel(&content);
	}
}
