
#include "lem_in.h"

static int		ft_sumofprelastroads(t_list *options, int other)
{
	t_direction	*road;
	int		sum;

	sum = 0;
	while (options)
	{
		road = options->content;
		sum = sum + other - road->len + 1;
		if (options->next && !((t_direction *)options->next->content)->active)
			break ;
		options = options->next;
	}
	return (sum);
}

static t_list	*ft_last_active_direction(t_list *directions)
{
	t_list	*prev_node;

	prev_node = NULL;
    if (!directions)
		return (NULL);
    while (directions)
	{
		if (!((t_direction *)directions->content)->active)
			break ;
        prev_node = directions;
        directions = directions->next;
    }
	return (prev_node);
}

static int		ft_active_ways_count(t_list *directions)
{
	t_direction	*way;
	int			count;

	count = 0;
	while (directions)
	{
		way = directions->content;
		if (way->active)
			count++;
		directions = directions->next;
	}
	return (count);
}

int				ft_keep_optimal_directions(t_list *directions, int total_ants)
{
	t_direction	*road;
	int			count;

	count = 0;
	if (directions)
	{
		while (1)
		{
			if ((count = ft_active_ways_count(directions)) == 1)
				break ;
			road = ft_last_active_direction(directions)->content;
			if (ft_sumofprelastroads(directions, road->len) < total_ants)
				break ;
			else
				road->active = 0;
		}
	}
	return (count);
}
