#ifndef MAP_COMMON_H
#define MAP_COMMON_H

/** Common structures and functions shared by map_reader and shortest_path
    A lot of functions could be added, it's kind of minimal for now */

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
    node_t *node;           //< A neighbour
    float weight;           //< The weight (distance) between the two nodes
    adjacency_list_t *next; //< The next neighbour
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

/** @brief Display information on the graph (no graphical display yet)
  * @param graph A pointer to the graph structure to display */
void printGraph(const graph_t *graph);

/** @brief Free a graph structure
  * @param graph A pointer to the graph structure to free */
void freeGraph(graph_t *graph);

/** @brief Compute weight of the path between node a and node b
  * @param a First node
  * @param b Second node
  * @return The weight (basically, the distance) */
float computeWeight(node_t a, node_t b);

/** @brief Basically, add a neighbour node to the adjacency (chained) list
    @param node The concerned node (origin)
    @param neighbour The neighbour node to add (destination)
    @param The node's list to add node to */
void addAdjacentNode(node_t *originNode, node_t *adjacentNode, adjacency_list_t **adjacencyList);

/** @brief Index of a node according to its name
    @param nodeName Name of the node
    @param graph Graph in which is the node
    @return The index of node in the graph->nodes table
    @return -1 if node has not been found in graph->nodes */
int indexOf(const char *nodeName, const graph_t *graph);

/** @brief Free an adjacency (chained) list
    @param list The list to free */
void freeAdjacencyList(adjacency_list_t *list);

#endif // MAP_COMMON_H
