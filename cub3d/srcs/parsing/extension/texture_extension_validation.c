#include "../includes/container.h"

// validating texture file extention (.xpm)

#include "../includes/container.h"

// validating the file extension (.xpm)
int	is_valid_xpm_file(const char *filename)
{
	int		len;
	char	**parts;
	char	*base;
	int		i;

	if (!filename)
		return (0);
	parts = NULL;
	base = (char *)filename;
	if (ft_strchr(filename, '/'))
	{
		parts = ft_split(filename, '/');
		if (!parts)
			return (0);
		i = 0;
		while (parts[i])
			i++;
		if (i == 0)
			return (free_str(parts), 0);
		base = parts[i - 1];
	}
	len = ft_strlen(base);
	if (len < 5 || ft_strncmp(base + len - 4, ".xpm", 4) != 0)
		return (free_str(parts), 0);
	return (free_str(parts), 1);
}
