/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:47:33 by sroland           #+#    #+#             */
/*   Updated: 2020/03/01 20:18:54 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_ants(t_graph *world, char *line, int *step)
{
	if (is_number(line) == 0)
		return (0);
	if (ft_atoi_status(&line, world->number_of_ants) == 0)
		return (0);
	while (ft_isspace1((int)(*line)) != 0)
		line++;
	if (*line != '\0')
		return (0);
	*step = 1;
	return (1);
}

int				get_next_room(t_graph *world, char **line, int *step)
{
	int		flag;
	int		res;

	flag = 0;
	while (**line == '#')
	{
		if (ft_strequ(line, "##start") == 1)
			flag += 1;
		else if (ft_strequ(line, "##end") == 1)
			flag += 100;
		if (flag != 0 && flag != 100 && flag != 1)
			return (-1);
		free(*line);
		if (get_next_line(0, line) != 1)
			return (-1);
	}
	res = add_room(world, flag, *line);
	if (res == 0)
		*step = 2;
	if (res == -1)
		return (-1);
	return (1);
}

int				add_room(t_graph *world, int flag, char *line)
{
	char		*name;
	int			x;
	int			y;
	t_room		*new_room;

	new_room = NULL;
	name = NULL;
	if (is_room(line, &name, &x, &y) == 0)
		return (flag == 0 ? 0 : -1);
	if (*name == '\0' || *name == 'L' || find_room(world->rooms, name))
	{
		ft_strdel(&name);
		return (-1);
	}
	new_room = create_room(name, x, y);
	if (new_room == NULL)
		return (-1);
	ft_lstadd_back(world->rooms, new_room);
	return (1);
}

static t_room	*create_room(char *name, int *x, int *y)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new == NULL)
		return (new);
	new->x = *x;
	new->y = *y;
	new->edges = NULL;
	new->is_visited = 0;
	new->name = ft_strncpy(ft_strnew(ft_strlen(name)), name, ft_strlen(name));
	return (new);
}

static int		find_room(t_list *rooms, char *name)
{
	while (rooms != NULL)
	{
		if (ft_strequ(((t_room *)rooms->content)->name, name) == 1)
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

static int		space_count(char *line)
{
	int		count;

	count = 0;
	while (*line != '\0')
	{
		if (*line == ' ')
			count++;
		line++;
	}
	return (count);
}

static int		is_room(char *line, char **room_name, int *x, int *y)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = line;
	if (space_count(line) != 2)
		return (0);
	while (line[i] != ' ')
		i++;
	*room_name = ft_strncpy(ft_strnew(i), line, i);
	i++;
	line = line + i;
	if (is_number(line) != 1 || ft_atoi_status(&line, x) != 0)
	{
		free(*room_name);
		return (0);
	}
	if (is_number(line) != 1 || ft_atoi_status(&line, x) != 0)
	{
		free(*room_name);
		return (0);
	}
	return (1);
}
