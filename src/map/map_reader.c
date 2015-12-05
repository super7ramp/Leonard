#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_reader.h"

//------- These functions are meant to be used only in this file --------//
void addNode(const char *buf, graph_t *graph);
void addEdges(const char *buf, graph_t *graph);
void addAdjacentNode(node_t *adjacentNode, adjacency_list_t **adjacencyList);
int indexOf(const char *nodeName, const graph_t *graph);
void freeAdjacencyList(adjacency_list_t *list);
//-----------------------------------------------------------------------//

graph_t *createGraph(FILE* csvMap)
{
    // Check if the file is valid
    if(!csvMap)
    {
        fprintf(stderr, "[%s:%d] Error: invalid map file descriptor\n", __FILE__, __LINE__);
        return NULL;
    }

    // Check if the map is empty
    char *buf = malloc(LINE_MAX_LENGTH*sizeof(char));
    if(!fgets(buf, LINE_MAX_LENGTH, csvMap))
    {
        fprintf(stderr, "[%s:%d] Error: empty map file\n", __FILE__, __LINE__);
        free(buf);
        return NULL;
    }

    // First line must be "nodes:"
    if (strcmp(buf,"nodes:\n"))
    {
        fprintf(stderr, "[%s:%d] Error: expected nodes identifier, read %s\n", __FILE__, __LINE__, buf);
        free(buf);
        return NULL;
    }

    // Our graph
    graph_t *graph = malloc(sizeof(graph_t));
    graph->numberOfNodes = 0;
    int i;
    for(i = 0; i < MAX_NUMBER_OF_NODES; i++)
        graph->edges[i] = NULL;

    // Parse nodes
    while(fgets(buf, LINE_MAX_LENGTH, csvMap) && strcmp(buf, "edges:\n"))
        addNode(buf,graph);

    // Parse edges
    while(fgets(buf, LINE_MAX_LENGTH, csvMap))
        addEdges(buf, graph);

    free(buf);
    return graph;
}

void freeGraph(graph_t *graph)
{
    if(!graph)
        return;

    int i;
    for(i = 0; i < graph->numberOfNodes; i++)
    {
        // We only need to clean the adjacency lists (chained lists)
        freeAdjacencyList(graph->edges[i]);
    }

    free(graph);
}

void printGraph(const graph_t *graph)
{
    if(!graph)
    {
        fprintf(stderr, "[%s:%d] Error: Invalid graph\n", __FILE__, __LINE__);
        return;
    }

    printf("Number of nodes: %d\n", graph->numberOfNodes);

    int i;
    for(i = 0; i < graph->numberOfNodes; i++)
    {
        printf("Node %d: %s\n", i+1, graph->nodes[i].name);
        printf("x = %f\n", graph->nodes[i].x);
        printf("y = %f\n", graph->nodes[i].y);

        printf("Neighbours: ");
        adjacency_list_t *currentNeighbour = graph->edges[i];
        while(currentNeighbour)
        {
            printf("%s ", currentNeighbour->node->name);
            currentNeighbour = currentNeighbour->next;
        }
        printf("\n");
    }
}

void addNode(const char *buf, graph_t *graph)
{
    if(graph->numberOfNodes >= MAX_NUMBER_OF_NODES)
    {
        fprintf(stderr, "[%s:%d] Error: Cannot add node, graph is full\n", __FILE__, __LINE__);
        return;
    }

    node_t newNode;
    char tmpLine[LINE_MAX_LENGTH];
    strncpy(tmpLine, buf, LINE_MAX_LENGTH);

    // buf should contains a node description, i.e. something like:
    // "myNode1, 33.5, 5.1"
    // TODO: add checks!
    strncpy(newNode.name, strtok(tmpLine, ",\n"), NAME_MAX_LENGTH);
    newNode.x = atof(strtok(NULL, ",\n"));
    newNode.y = atof(strtok(NULL, ",\n"));   

    graph->nodes[graph->numberOfNodes] = newNode;
    (graph->numberOfNodes)++;
}

void addEdges(const char *buf, graph_t *graph)
{
    char *field;
    char tmpLine[LINE_MAX_LENGTH];
    strncpy(tmpLine, buf, LINE_MAX_LENGTH);

    // buf should contains an adjacency list
    // "myNode, adjacentNode1, adjacentNode2, …"
    // Therefore, first token contains name of the concerned node
    field = strtok(tmpLine, ",\n");
    int nodeId = indexOf(field, graph);

    if(nodeId < 0)
    {
        fprintf(stderr, "[%s:%d] Warning: node %s has not been declared, ignoring\n", __FILE__, __LINE__, field);
        return;
    }

    // Parsing adjacent nodes
    int adjacentNodeId;
    field = strtok(NULL, ",\n");
    while(field)
    {
        adjacentNodeId = indexOf(field, graph);
        if (adjacentNodeId < 0)
            fprintf(stderr, "[%s:%d] Warning: node %s has not been declared, ignoring\n", __FILE__, __LINE__, field);
        else
        {
            // Add adjacentNode as a neighbour of node
            //printf("Before: %x\n", (void *)graph->edges[nodeId]);
            addAdjacentNode(&(graph->nodes[adjacentNodeId]), &(graph->edges[nodeId]));
            //printf("After: %x\n", (void *)graph->edges[nodeId]);
        }
        field = strtok(NULL, ",\n");
    }
}

/** @brief Basically, add a node to a chained list.
    @param node Node to add
    @param neighboursList Pointer to the list to add node to */
void addAdjacentNode(node_t *node, adjacency_list_t **neighbourList)
{
    // add at the beginning of the chained list
    adjacency_list_t *newNeighbour = malloc(sizeof(adjacency_list_t));
    newNeighbour->node = node;
    newNeighbour->next = *neighbourList;
    *neighbourList = newNeighbour;
}

int indexOf(const char *nodeName, const graph_t *graph)
{
    int i;

    // Not very efficient, a hash map would be better
    for (i = 0; i < graph->numberOfNodes; i++)
    {
        if(!strcmp(nodeName, graph->nodes[i].name))
            return i;
    }

    return -1;
}

void freeAdjacencyList(adjacency_list_t *adjacentNodes)
{
    if(adjacentNodes)
    {
        adjacency_list_t *cleaner = adjacentNodes->next;
        free(adjacentNodes);
        adjacentNodes = NULL;
        freeAdjacencyList(cleaner);
    }
}

