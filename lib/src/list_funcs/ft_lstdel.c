/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:38:53 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/12 15:28:50 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	if (alst && del)
	{
		while (*alst)
		{
			current = *alst;
			del(current->content, current->content_size);
			*alst = (*alst)->next;
			free(current);
			current = NULL;
		}
		current = NULL;
	}
	(*alst) = NULL;
}
