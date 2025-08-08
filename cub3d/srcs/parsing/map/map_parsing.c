#include "../includes/container.h"


// 1) call get next line over again and we put all the line in a **grid ,
//  trim the line before we asigne it , actualy we dont need to trim the line
// 2) validate the map 
static void calculate_map_dimensions(t_map *map)
{
    int i;
    int current_width;

    // max width is calculated with spaces , should we skip them
    if (!map || !map->arr)
        return;
    i = 0;
    map->rows = 0;
    map->columns = 0;
    while (map->arr[i])
    {
        current_width = ft_strlen(map->arr[i]);
        if (current_width > map->columns)
            map->columns = current_width;
        i++;
    }
    map->rows = i;
}

int parse_map_lines(t_cub_data *data, int fd, char *first_line)
{
    t_str    *map_str;
    char     *line;
    char     **map_arr;

    if (!first_line || !*first_line)
        return (0);
    data->map_found = 1;
    map_str = str_new(first_line);
    if (!map_str)
        return (0);
    while ((line = get_next_line(fd)))
    {
        if (is_empty_line(line))
        {
            free(line);
            return 0;
        }
        if (!str_append_list(map_str, line))
        {
            free(line);
            str_free(map_str);
            return (0);
        }
        free(line);
    }

    // printf("----map befor split -> [%s]\n",map_str->value);
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

    // if (!validate_map(data))
    // {
    //     printf("INVALID MAP!\n");
    //     free_str(data->map.arr); 
    //     data->map.arr = NULL;
    //     return (0);
    // }

    return (1);
}
