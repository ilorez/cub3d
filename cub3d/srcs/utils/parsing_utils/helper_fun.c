#include "../../includes/container.h"

void	remove_newline(char *line)
{
	size_t	len;

	if (!line)
		return;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	is_empty_line(char *line)
{
    int	i;

    if (!line)
        return (1);
    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    return (line[i] == '\0' || line[i] == '\n');
}

int	is_valid_char(char c)
{
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	print_error_and_exit(const char *msg, t_cub_data *data, char *line, int fd)
{
    (void)data;
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	// free_all_data(data);
	ft_putstr_fd((char *)msg, 2);
	// exit(1);
}

