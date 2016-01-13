#ifndef MAP_READER_H
#define MAP_READER_H

#include "map_common.h"

/** @brief  Create a graph structure from the given file
  * @return A pointer to the graph structure or NULL if the given file is invalid */
graph_t *createGraph(FILE* csvMap);

#endif // MAP_READER_H
