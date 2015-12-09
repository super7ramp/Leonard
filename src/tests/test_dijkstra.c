#include <stdio.h>
#include <stdlib.h>
#include "../map/map_reader.h"
#include "../shortest_path.h"

// gcc -Wall -lm test_dijkstra.c ../map/map_common.c ../map/map_reader.c ../shortest_path.c -o test-dijsktra
// ./test-dijkstra map_adrien.csv

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Syntax: %s map.csv\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    graph_t *map = createGraph(file);
    fclose(file);

    //printGraph(map);
    node_t **path = dijkstra(4.0, 1.0, 2.0, 3.0, map);

    printf("The shortest path between (4.0, 1.0) and (2.0, 3.0) is:\n");
    printf("(In reverse order)\n");
    int i;
    for(i = 0; path && path[i]; i++)
        printf("%s (%f,%f)\n",path[i]->name, path[i]->x, path[i]->y);

    // Don't forget to free these when you're done
    free(path);
    freeGraph(map);

    return 0;
}
