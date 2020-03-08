/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:28:31 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/08 20:11:07 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*ptr;

	if (alst && *alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		ptr = (*alst)->next;
		free((*alst));
		*alst = ptr;
	}
}
