
#include "lem_in.h"

int	ft_add_ants(t_graph *world, char *line, int *step)
{
	if (is_number(line) == 0)
		return (0);
	if (ft_atoi_status(&line, &(world->number_of_ants)) == 0)
		return (0);
	while (ft_isspace((int)(*line)) != 0)
		line++;
	if (*line != '\0')
		return (0);
	*step = 1;
	return (1);
}
