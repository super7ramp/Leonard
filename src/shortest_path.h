#ifndef __SHORTEST_PATH_H
#define __SHORTEST_PATH_H

#define NBR_NODE	5
#define INFINITE	999
#define ERROR_COORD	0.3

typedef struct node node_t;
typedef struct element element_t;

struct element {
	node_t * neighbour;
	int weight;
	element_t * next_neighbour;
};

struct node {
	float x;
	float y;
	element_t * neighbours; 
};

node_t ** dijkstra (float current_x, float current_y, float dest_x, float dest_y, node_t ** map);
int find_point (node_t ** map, float other_x, float other_y);
int find_index_map (node_t ** map, int other_x, int other_y);
int check_flag (int * flag);

#endif
