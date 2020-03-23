
#include "lem_in.h"

static int		ft_add_way_stop(t_list **rooms_way, t_room *room)
{
	t_list	*way_stop;

	if (!rooms_way || !room)
		return (0);
	if (!(way_stop = ft_lstnew(NULL, 0)))
	{
		ft_lstdel(rooms_way, ft_contentdel);
		return (0);
	}
	way_stop->content = room;
	ft_lstadd_back(rooms_way, way_stop);
	return (1);
}

static t_list	*ft_find_way(t_room *room)
{
	t_list	*way;
	t_list	*edges;

	if (!room)
		return (NULL);
	way = NULL;
	edges = room->edges;
	while (edges)
	{
		if (room->type == end_room || \
((t_edge *)edges->content)->flow == 1)
		{
			if (!(ft_add_way_stop(&way, room)))
				return (NULL);
			if (room->type == end_room)
				break ;
			room = ((t_edge *)edges->content)->leads_to;
			edges = room->edges;
		}
		edges = edges->next;
	}
	return (way);
}

static int		ft_add_direction(t_list **directions, \
t_edge *edge, t_graph *world)
{
	t_direction	direction;
	t_list		*new_direction;

	if (!edge || !world)
		return (0);
	if (!(direction.way = ft_find_way(edge->leads_to)))
		return (0);
	direction.len = ft_lstlen(direction.way);
	direction.active = 1;
	if (!(new_direction = ft_lstnew(&direction, sizeof(t_direction))))
	{
		ft_lstdel(&direction.way, ft_contentdel);
		return (0);
	}
	ft_lstadd_back(directions, new_direction);
	return (1);
}

static int		ft_sort_directions(t_list *current, t_list *next)
{
	t_direction	*first;
	t_direction	*second;

	first = current->content;
	second = next->content;
	if (first->len > second->len)
		return (1);
	return (0);
}

t_list			*ft_find_directions(t_graph *world)
{
	t_list	*directions;
	t_list	*edges;

	edges = ((t_room *)world->start_room->content)->edges;
	directions = NULL;
	while (edges)
	{
		if (((t_edge *)edges->content)->flow == 1)
		{
			if (!ft_add_direction(&directions, edges->content, world))
			{
				ft_lstdel(&directions, ft_contentdel);
				return (NULL);
			}
		}
		edges = edges->next;
	}
	ft_lstsort(&directions, ft_sort_directions);
	return (directions);
}
