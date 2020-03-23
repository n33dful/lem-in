
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

static t_list	*ft_last_active_way(t_list *ways_list)
{
	t_list	*prev_node;

	prev_node = NULL;
    if (!ways_list)
		return (NULL);
    while (ways_list)
	{
		if (!((t_direction *)ways_list->content)->active)
			break ;
        prev_node = ways_list;
        ways_list = ways_list->next;
    }
	return (prev_node);
}

static int	ft_active_ways_count(t_list *ways_list)
{
	t_direction	*way;
	int			count;

	count = 0;
	while (ways_list)
	{
		way = ways_list->content;
		if (way->active)
			count++;
		ways_list = ways_list->next;
	}
	return (count);
}

int				ft_keep_best_directions(t_list *ways_list, int total_ants)
{
	t_direction	*road;
	int			count;

	count = 0;
	if (ways_list)
	{
		while (1)
		{
			if ((count = ft_active_ways_count(ways_list)) == 1)
				break ;
			road = ft_last_active_way(ways_list)->content;
			if (ft_sumofprelastroads(ways_list, road->len) < total_ants)
				break ;
			else
				road->active = 0;
		}
	}
	return (count);
}
