#include "../includes/container.h"

int	is_map_start(char *line)
{
    int i;

    i = 0;
    if (line[i] == ' ' || line[i] == '\t')
        i++;
    return (line[i] == '1' || line[i] == '0');
}
