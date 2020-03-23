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
	t_way	*way;

	if (content_size > 0)
	{
		way = content;
		ft_lstdel(&way->direction, ft_contentdel);
		ft_memdel(&content);
	}
}

void	ft_bandwidthdel(void *content, size_t content_size)
{
	t_bandwidth	*bandwidth;

	if (content_size > 0)
	{
		bandwidth = content;
		ft_lstdel(&bandwidth->roads, ft_waydel);
		ft_memdel(&content);
	}
}
