/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:07:33 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:07:39 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	if (alst && del)
	{
		current = (*alst);
		del(current->content, current->content_size);
		(*alst) = (*alst)->next;
		free(current);
		current = NULL;
	}
}
