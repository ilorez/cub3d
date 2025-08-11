#include "../../includes/container.h"

// free data 
// void free_cud_data(t_cub_data *data)
// {

// }


// free **char str
void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}