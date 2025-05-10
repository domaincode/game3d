
#include "parsing/parsing.h"

#include "parsing/parsing.h"

void cleanup(t_map *map)
{
    int i;

    // Free each texture map
    // for (i = 0; i < 5; i++)
    // {
    //     if (map->textures[i].map)
    //     {
    //         free(map->textures[i].map);
    //         map->textures[i].map = NULL; 
    //     }
    // }

    // Free the directions
    // if (map->directions)
    // {
    //     if (map->directions->no)
    //     {
    //         free(map->directions->no);
    //         map->directions->no = NULL;
    //     }
    //     if (map->directions->so)
    //     {
    //         free(map->directions->so);
    //         map->directions->so = NULL;
    //     }
    //     if (map->directions->we)
    //     {
    //         free(map->directions->we);
    //         map->directions->we = NULL;
    //     }
    //     if (map->directions->ea)
    //     {
    //         free(map->directions->ea);
    //         map->directions->ea = NULL;
    //     }

    //     // Free the directions structure itself (only if dynamically allocated)
    //     free(map->directions);
    //     map->directions = NULL;
    // }

    // Free the map array
    if (map->map)
    {
        for (i = 0; map->map[i]; i++)
        {
            free(map->map[i]);
            map->map[i] = NULL;
        }
        free(map->map);
        map->map = NULL;
    }

    write(1, "Cleanup completed.\n", 19);
}

void print_debug_info(t_map *map)
{
    int i;

    printf("Map:\n");
    if (map->map)
    {
        for (i = 0; map->map[i]; i++)
            printf("%s\n", map->map[i]);
    }
    else
    {
        printf("Map is NULL.\n");
    }

    printf("\nTextures:\n");
    if (map->directions)
    {
        printf("NO: %s\n", map->directions->no ? map->directions->no : "NULL");
        printf("SO: %s\n", map->directions->so ? map->directions->so : "NULL");
        printf("WE: %s\n", map->directions->we ? map->directions->we : "NULL");
        printf("EA: %s\n", map->directions->ea ? map->directions->ea : "NULL");
    }
    else
    {
        printf("Directions are NULL.\n");
    }

    printf("\nColors:\n");
    if (map->directions)
    {
        printf("Floor (F): %lld\n", map->directions->f);
        printf("Ceiling (C): %lld\n", map->directions->c);
    }
    else
    {
        printf("Directions are NULL.\n");
    }
}



int	main(int ac, char **av)
{
	int				i;
	t_map			map;
	t_directions	directions;
	t_textures		textures[5];

	i = 5;
	if (ac != 2)
		put_error("INVALID NUMBER OF ARGUMENTS");
	while (i--)
		textures[i].map = &map;
	map.textures = textures;
	directions.map = &map;
	map.directions = &directions;
	parsing(&map, av);
	print_debug_info(&map);
	//cleanup(&map);
    //free_map(map);
    return 0;
}
