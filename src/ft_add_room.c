/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konstantinzakharov <konstantinzakharov@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:47:33 by sroland           #+#    #+#             */
/*   Updated: 2020/04/01 16:08:07 by konstantinz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*ft_create_room(char *name, int type, int x, int y)
{
	t_list	*new_elem;
	t_room	room;

	new_elem = NULL;
	if (name && x >= 0 && y >= 0)
	{
		if (!(room.name = ft_strdup(name)))
			return (NULL);
		room.type = type;
		room.x = x;
		room.y = y;
		room.edges = NULL;
		room.parent = NULL;
		room.is_visited = 0;
		if (!(new_elem = ft_lstnew(&room, sizeof(t_room))))
			ft_strdel(&room.name);
	}
	return (new_elem);
}

static int		ft_room_exists(t_graph *world, char *name)
{
	t_list	*rooms;
	t_room	*room;

	rooms = world->rooms;
	while (rooms)
	{
		room = rooms->content;
		if (ft_strequ(room->name, name) == 1)
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

static int		ft_add(t_graph *world, int room_type, char **room_info)
{
	t_list	*new_room;
	int		x;
	int		y;

	x = ft_atoi(room_info[1]);
	y = ft_atoi(room_info[2]);
	if (!(new_room = ft_create_room(room_info[0], room_type, x, y)))
		return (0);
	ft_lstadd_back(&world->rooms, new_room);
	if (room_type == start_room && world->start_room)
		return (0);
	if (room_type == end_room && world->end_room)
		return (0);
	if (room_type == start_room)
		world->start_room = new_room;
	if (room_type == end_room)
		world->end_room = new_room;
	return (1);
}

int				ft_add_room(t_graph *world, char *line,
	int *step, int *room_type)
{
	int		exit_code;
	char	**room_info;

	exit_code = 1;
	room_info = NULL;
	if (line)
	{
		if (ft_read_line_format(line) != room_format)
		{
			(*step) = 2;
			exit_code = 0;
		}
		else if (!(room_info = ft_strsplit(line, ' ')))
			exit_code = 0;
		else if (ft_room_exists(world, room_info[0]))
			exit_code = 0;
		else if (!room_info[0] || !room_info[1] || !room_info[2])
			exit_code = 0;
		else if (!ft_add(world, (*room_type), room_info))
			exit_code = 0;
		ft_arrdel((void *)(&room_info));
		(*room_type) = ordinary_room;
		return (exit_code);
	}
	return (0);
}
