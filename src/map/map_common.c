#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "map_common.h"

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
            printf("(weight = %f) ", currentNeighbour->weight);
            currentNeighbour = currentNeighbour->next;
        }
        printf("\n");
    }
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

void addAdjacentNode(node_t *node, node_t *neighbourNode, adjacency_list_t **neighbourList)
{
    // add at the beginning of the chained list
    adjacency_list_t *newNeighbour = malloc(sizeof(adjacency_list_t));
    newNeighbour->node = neighbourNode;
    newNeighbour->weight = computeWeight(*node,*neighbourNode); 
    newNeighbour->next = *neighbourList;
    *neighbourList = newNeighbour;
}

float computeWeight(node_t a, node_t b)
{
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
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

