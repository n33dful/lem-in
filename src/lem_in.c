/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:21 by sroland           #+#    #+#             */
/*   Updated: 2020/03/15 23:12:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_print_world(t_list *list_elem)
{
	char	*str;

	str = list_elem->content;
	if (str)
		ft_putendl(str);
}

//static int	ft_parese_line(int *step, const char *line, t_graph *world)
//{
//	if (step == 0 && get_ants(world, line, &step) != 1)
//		return (0);
//	else if (step == 1 && get_next_room(world, &line, &step) != 1)
//		return (0);
//	if (step == 2 &&
//	(!world->start_room || !world->end_room || get_edges(world, line) != 1))
//		return (0);
//	return (1);
//}

t_list		*parse_input(t_graph *world)
{
	t_list	*list_of_map;
	t_list	*new;
	int		step;
	char	*line;

	step = 0;
	list_of_map = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(new = ft_lstnew(line, ft_strlen(line) + 1)))
		{
			ft_lstdel(&list_of_map, ft_lstdel_func);
			return (NULL);
		}
		ft_lstadd_back(&list_of_map, new);
		if (step == 0)
		{
			if (get_ants(world, line, &step) != 1)
				return (0);
		}
		else if (step == 1)
		{
			if (get_next_room(world, &line, &step) != 1)
				return (0);
			if (!ft_strequ((char *)ft_lstlast(list_of_map)->content, line))
			{
				if (!(new = ft_lstnew(line, ft_strlen(line) + 1)))
				{
					ft_lstdel(&list_of_map, ft_lstdel_func);
					return (NULL);
				}
				ft_lstadd_back(&list_of_map, new);
			}
		}
		else if (step == 2 &&
		(!world->start_room || !world->end_room || get_edges(world, line) != 1))
			return (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (list_of_map);
}

int			init_world(t_graph *world)
{
	world->end_room = NULL;
	world->start_room = NULL;
	world->number_of_ants = 0;
	world->rooms = NULL;
	return (0);
}

static t_bandwidth	*ft_find_best_option(t_list *list_of_options)
{
	t_bandwidth	*min_option;
	int			min_turns;

	min_turns = ((t_bandwidth *)list_of_options->content)->turns;
	min_option = list_of_options->content;
	while (list_of_options)
	{
		if (((t_bandwidth *)list_of_options->content)->turns < min_turns)
		{
			min_option = list_of_options->content;
			min_turns = ((t_bandwidth *)list_of_options->content)->turns;
		}
		list_of_options = list_of_options->next;
	}
	return (min_option);
}

static int	ft_error()
{
	write(2, "Error\n", 6);
	return (0);
}

int			main(int argc, char **argv)
{
	t_list		*list_of_map;
	t_list		*list_of_options;
	t_graph		world;

	argv = NULL;
	init_world(&world);
	if (argc > 1)
		return (ft_error());
	if (!(list_of_map = parse_input(&world)))
		return (ft_error());
	if (!(list_of_options = ford_falkerson(&world)))
		return (ft_error());
	ft_lstiter(list_of_map, ft_print_world);
	ft_putchar('\n');
	if (!(ft_push_ants(ft_find_best_option(list_of_options), &world)))
		return (ft_error());
	ft_graphdel(&world);
	ft_lstdel(&list_of_map, ft_lstdel_func);
	ft_lstdel(&list_of_options, ft_lstdel_func);
	return (0);
}
