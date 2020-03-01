/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:59:54 by cdarci            #+#    #+#             */
/*   Updated: 2020/01/26 21:11:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_list
{
	void			*content;
	unsigned long	content_size;
	struct s_list	*next;
}					t_list;

#endif
