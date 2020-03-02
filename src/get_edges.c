/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/02 19:54:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int  ft_check_format(const char *line)
{
	size_t	i;

	i = 0;
    if (!line)
        return (0);
    if (line[0] == 'L')
        return (0);
    if (ft_strchr(line, '-') != ft_strrchr(line, '-'))
        return (0);
	while (ft_isalnum(line[i]))
		i++;
	if (line[i] != '-')
		return (0);
	else
		i++;
	while (ft_isalnum(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	return (1);
}

static int	ft_arrdel(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		ft_strdel(&(arr[i++]));
	free(arr);
	arr = NULL;
	return (0);
}

static int		ft_check_edge(char **room_names, t_list *rooms)
{
	t_list	*lst_of_edges;
	t_room	*room;
	t_edge	*edge;
	char	*check;

	while (rooms)
	{
		room = rooms->content;
		if (room->name == room_names[0] || room->name == room_names[1])
		{
			check = room_names[room->name == room_names[0] ? 1 : 0];
			lst_of_edges = room->edges;
			while (lst_of_edges)
			{
				edge = lst_of_edges->content;
				if (ft_strequ(edge->to->name, check))
					return (0);
				lst_of_edges = lst_of_edges->next;
			}
		}
		rooms = rooms->next;
	}
	return (1);
}

static int		ft_search_room(void *cont, t_list *lst)
{
	t_room	*room;
	char	*name;

	name = cont;
	room = lst->content;
	if (ft_strequ(name, room->name))
		return (1);
	return (0);
}

static t_list	*ft_lstfind(t_list *list, void *what, int (*with)(void *, t_list *))
{
	while (list)
	{
		if (with(what, list))
			return (list);
		list = list->next;
	}
	return (NULL);
}

static int	ft_add_edge(char **room_names, t_list *rooms)
{
	t_list	*room_one;
	t_list	*room_two;
	t_room	*room;
	t_list	*new;
	t_edge	edge;

	if (!(room_one = ft_lstfind(rooms, room_names[0], ft_search_room)))
		return (0);
	if (!(room_two = ft_lstfind(rooms, room_names[1], ft_search_room)))
		return (0);
	edge.weight = 0;
	edge.residual = 0;
	edge.flow = 0;
	edge.to = room_one->content;
	if (!(new = ft_lstnew(&edge, sizeof(t_edge))))
		return (0);
	room = room_two->content;
	ft_lstadd_back(&(room->edges), new);
	edge.to = room_two->content;
	if (!(new = ft_lstnew(&edge, sizeof(t_edge))))
		return (0);
	room = room_one->content;
	ft_lstadd_back(&(room->edges), new);
	return (1);
}

int			get_edges(t_graph *world, char *line)
{
	t_list	*rooms;
	char	**room_names;

	rooms = world->rooms;
	if (!ft_check_format(line))
		return (0);
	if (!(room_names = ft_strsplit(line, '-')))
		return (0);
	if (!ft_check_edge(room_names, rooms))
		return (ft_arrdel(room_names));
	if (!ft_add_edge(room_names, rooms))
		return (ft_arrdel(room_names));
	ft_arrdel(room_names);
	return (1);
}
