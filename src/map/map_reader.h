#ifndef MAP_READER_H
#define MAP_READER_H

#define LINE_MAX_LENGTH     64
#define NAME_MAX_LENGTH     32
#define MAX_NUMBER_OF_NODES 128

/** @brief The node structure
  * TODO: see if we can add a z coordinate */
typedef struct _node_t
{
    char name[NAME_MAX_LENGTH];
    float x;
    float y;
} node_t;

/** @brief The chained list representing an adjacency list */
typedef struct _adjacency_list_t adjacency_list_t;
struct _adjacency_list_t
{
    node_t *node;
    adjacency_list_t *next;
};

/** @brief The graph structure */
typedef struct _graph_t
{
    /** The nodes */
    node_t nodes[MAX_NUMBER_OF_NODES];

    /** The neighbours for each node (i.e. the neighbours of nodes[i] are
      * in the edges[i] chained list) */
    adjacency_list_t *edges[MAX_NUMBER_OF_NODES];

    /** The number of known nodes */
    int numberOfNodes;
} graph_t;

/** @brief  Create a graph structure from the given file
  * @return A pointer to the graph structure or NULL if the given file is invalid */
graph_t *createGraph(FILE* csvMap);

/** @brief Free a graph structure
  * @param graph A pointer to the graph structure to free */
void freeGraph(graph_t *graph);

/** @brief Display information on the graph (no graphical display yet)
  * @param graph A pointer to the graph structure to display */
void printGraph(const graph_t *graph);

#endif // MAP_READER_H
