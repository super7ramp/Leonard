#include "shortest_path.h"

#define FLOAT_COMPARISON_THRESHOLD 0.001

//------- These functions are meant to be used only in this file --------//

/** @brief Same thing than find_point, but without margin error
    @float other_x Searched point x coordinate
    @float other_y Searched point y coordinate
    @return Index of the searched point
    @return -1 if the point is not found in the map */
int find_index_map (const graph_t *map, float other_x, float other_y);

/** @brief Check if a node has already been visited
    @param flags The flag table
    @param size The size of the flag table */
int check_flag (const int *flags, int size);
//-----------------------------------------------------------------------//

node_t **dijkstra(float current_x, float current_y, float dest_x, float dest_y, graph_t *map)
{
    int flag[map->numberOfNodes];
    float cost[map->numberOfNodes];
    node_t **previous;
    node_t **path;
    int start_point;
    int end_point;
    int i;
    int cost_min = INFINITE;
    int aux;
    int index;
    int check;
    adjacency_list_t *current;

    previous = calloc(map->numberOfNodes, sizeof(node_t *));
    path = calloc(map->numberOfNodes, sizeof(node_t *));

    // Find departure point in map
    start_point = find_point(map, current_x, current_y);
    if(start_point < 0)
    {
        fprintf(stderr, "[%s:%d] Error: Starting point not found\n", __FILE__, __LINE__);
        free(previous);
        free(path);
        return NULL;
    }

    // Find arrival point in map
    end_point = find_point(map, dest_x, dest_y);
    if(end_point < 0)
    {
        fprintf(stderr, "[%s:%d] Error: Arrival point not found\n", __FILE__, __LINE__);
        free(previous);
        free(path);
        return NULL;
    }

    // Init
    cost[start_point] = 0;
    previous[start_point] = &(map->nodes[start_point]);
    flag[start_point] = 0;

    for(i = 0; i < map->numberOfNodes; i++)
    {
        if(i != start_point)
        {
            cost[i] = INFINITE;
            previous[i] = NULL;
            flag[i] = 0;
        }
    }

    // Iteration
    while((check = check_flag(flag, map->numberOfNodes)) != 0)
    {
        for(i = 0; i < map->numberOfNodes; i++)
        {
            if(flag[i] == 0 && cost[i] < cost_min)
            {
                cost_min = cost[i];
                aux = i;
            }
	}

        cost_min = INFINITE;
        flag[aux] = 1;

        // Update cost of next point
        for(current = map->neighbours[aux];
            current != NULL;
            current = current->next)
        {
            index = find_index_map(map, current->node->x, current->node->y);
            if((index != -1) &&
               (flag[index] == 0) &&
               (cost[aux] + current->weight < cost[index]))
            {
                cost[index] = cost[aux] + current->weight;
                previous[index] = &(map->nodes[aux]);
	    }
	}
    }

    i = 0;
    path[i] = &(map->nodes[end_point]);
    index = end_point;

    while(fabs(previous[index]->x - map->nodes[start_point].x) > FLOAT_COMPARISON_THRESHOLD ||
          fabs(previous[index]->y - map->nodes[start_point].y) > FLOAT_COMPARISON_THRESHOLD)
    {
        i++;
	index = find_index_map(map, previous[index]->x, previous[index]->y);
	path[i] = &(map->nodes[index]);
    }

    path[i+1] = &(map->nodes[start_point]);

    /*
    int j;
    for(j = 0; j < map->numberOfNodes; j++)
    {
        printf("cost %d: %d\n", j, cost[j]);
        printf("flag %d: %d\n", j, flag[j]);
    }
    */


    free(previous);
    return path;
}

int find_point(const graph_t *map, float other_x, float other_y)
{
    int i;
    float x, y;
    for(i = 0; i < map->numberOfNodes; i++)
    {
        x = map->nodes[i].x;
        y = map->nodes[i].y;
        if(sqrt(pow(x-other_x,2) + pow(y-other_y,2)) < ERROR_COORD)
            return i;
    }
    return -1;
}

int find_index_map(const graph_t *map, float other_x, float other_y)
{
    int i;
    for(i = 0; i < map->numberOfNodes; i++)
    {
        // We cannot really test an equality between two floats, we need a comparison with a threshold
        if( fabs(map->nodes[i].x - other_x) < FLOAT_COMPARISON_THRESHOLD &&
            fabs(map->nodes[i].y - other_y) < FLOAT_COMPARISON_THRESHOLD )
            return i;
    }
    return -1;
}

int check_flag(const int *flags, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(flags[i] == 0)
            return 1;
    }
    return 0;
}

