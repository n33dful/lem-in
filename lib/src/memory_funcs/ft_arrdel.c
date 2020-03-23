
#include "libft.h"

void	ft_arrdel(void ***array)
{
	size_t	i;

	i = 0;
	if ((*array))
	{
		while ((*array)[i])
			ft_memdel(&((*array)[i++]));
		free((*array));
		(*array) = NULL;
	}
}
