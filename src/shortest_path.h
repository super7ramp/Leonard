#ifndef __SHORTEST_PATH_H
#define __SHORTEST_PATH_H

#define INFINITE	999
#define ERROR_COORD	0.3

#include "map/map_common.h"

/** @brief Find the shortest path beteween two points, according to a map
    @param current_x Start point x coordinate
    @param current_y Start point y coordinate
    @param dest_x Destination point x coordinate
    @param dest_y Destination point y coordinate
    @param map The map
    @return The shortest path (a list of node)
    FIXME:
     - we shouldn't return a double pointer, rather return a pointer and
       a size
     - the pointed pointers (yes) are pointers to data from the graph,
       not copies. This means that we cannot free the graph until the
       end of the program. */
node_t **dijkstra (float current_x, float current_y, float dest_x, float dest_y, graph_t *map);

#endif
