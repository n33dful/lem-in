/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:07:47 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:07:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstswap(t_list *list)
{
	t_list	*pointer;

	pointer = list->next;
	list->next = pointer->next;
	pointer->next = list;
	return (pointer);
}

static t_list	*ft_sort(t_list *list, int (*func)(t_list *, t_list *))
{
	if (!list->next)
		return (list);
	if (func(list, list->next))
		list = ft_lstswap(list);
	list->next = ft_sort(list->next, func);
	return (list);
}

void			ft_lstsort(t_list **list, int (*func)(t_list *, t_list *))
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_lstlen((*list));
	while (i < len)
	{
		(*list) = ft_sort((*list), func);
		i++;
	}
}
