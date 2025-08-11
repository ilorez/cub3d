#include "../includes/container.h"

// this would ignore the  spaces after a wall , for effective max width .
int get_effective_line_width(char *line)
{
    int len;
    
    len = ft_strlen(line);
    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'))
        len--;
    return len;
}

static void calculate_map_dimensions(t_map *map)
{
    int i;
    int current_width;

    if (!map || !map->arr)
        return;

    i = 0;
    map->width = 0;
    while (map->arr[i])
    {
        current_width = get_effective_line_width(map->arr[i]);
        if (current_width > map->width)
            map->width = current_width;
        i++;
    }
    map->rows = i;
}

int parse_map_lines(t_cub_data *data, int fd, char *first_line)
{
    t_str    *map_str;
    char     *line;
    char     *r_trimed;
    char     **map_arr;

    if (!first_line || !*first_line)
        return (0);
    data->map_found = 1;
    r_trimed = ft_rtrim(first_line);
    if (!r_trimed)
        return (0);
    map_str = str_new(r_trimed);
    free(r_trimed);
    if (!map_str)
        return (0);
    while ((line = get_next_line(fd)))
    {
        if (is_empty_line(line))
        {
            free(line);
            return 0;
        }
        r_trimed =  ft_rtrim(line);
        free(line);
        line = r_trimed;
        if (!str_append_list(map_str, line))
        {
            free(line);
            str_free(map_str);
            return (0);
        }
        free(line);
    }
    map_arr = ft_split(map_str->value, '\n');
    str_free(map_str);

    if (!map_arr)
        return (0);

    data->map.arr = map_arr;

    calculate_map_dimensions(&data->map);

    if (data->map.rows == 0)
    {
        free_str(data->map.arr);
        data->map.arr = NULL;
        return (0);
    }
    return (1);
}
