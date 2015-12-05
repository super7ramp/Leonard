#include <stdio.h>
#include <stdlib.h>
#include "shortest_path.h"



node_t ** dijkstra (float current_x, float current_y, float dest_x, float dest_y, node_t ** map)
{
	int flag [NBR_NODE];
	int cost [NBR_NODE];
	node_t**  previous;
	node_t** path;
	int start_point;
	int end_point;
	int i;
	int cost_min = INFINITE;
	int aux;
	int index;
	int check;
	element_t * current;

	previous = malloc(sizeof(node_t*)*NBR_NODE);
	path = malloc(sizeof(node_t*)*NBR_NODE);

	//find departure point in map
	if((start_point = find_point(map, current_x, current_y)) == (-1))
	{
		printf("[FAIL] : starting point not found\n");
		return 0;
	}

	//find arrival point in map
	if((end_point = find_point(map, dest_x, dest_y)) == (-1))
	{
		printf("[FAIL] : arrival point not found\n");
		return 0;
	}

	//init
	cost[start_point] = 0;
	previous[start_point] = map[start_point];
	flag[start_point] = 0;

	for(i = 0 ; i < NBR_NODE ; i++)
	{
		if(i != start_point)
		{
			cost[i] = INFINITE;
			previous[i] = NULL;
			flag[i] = 0;
		}
	} 

	//iteration
	while((check = check_flag(flag)) != 0)
	{
		for(i = 0 ; i < NBR_NODE ; i++)
		{
			if(flag[i] != 0)
			{
			}
			else 
			{	
				if(cost[i] < cost_min)
				{
					cost_min = cost[i];
					aux = i;
				}
			}
		}
		cost_min = INFINITE;
		flag[aux] = 1;

		//update cost of next point
		for(current = map[aux]->neighbours ; current != NULL ; current = current->next_neighbour)
		{
			if((index = find_index_map (map, current->neighbour->x, current->neighbour->y)) != -1)
			{
				if(flag[index] == 0)
				{
					if((cost[aux] + current->weight) < cost[index])
					{
						cost[index] = cost[aux] + current->weight;
						previous[index] = map[aux];
					}
				}
			}
		}
	}

	i = 0;
	path[i] = map[end_point];
	index = find_index_map(map, dest_x, dest_y);
	while(((previous[index]->x) != (map[start_point]->x)) || ((previous[index]->y) != (map[start_point]->y)))
	{
		i++;
		index = find_index_map(map, previous[index]->x, previous[index]->y);
		path[i] = map[index];
	}
	path[i+1] = map[start_point];

/*	int j;
	for(j = 0 ; j < NBR_NODE ; j++)
	{
		printf("cost %d: %d\n", j, cost[j]);
		printf("flag %d: %d\n", j, flag[j]);
	}*/
	//return previous;
	return path;
}

int find_point (node_t ** map, float other_x, float other_y)
{
	int i;

	for(i = 0 ; i < NBR_NODE ; i++)
	{
		if((((other_x - ERROR_COORD) < map[i]->x) && ((other_x + ERROR_COORD) > map[i]->x)) && (((other_y - ERROR_COORD) < map[i]->y) && ((other_y + ERROR_COORD) > map[i]->y)))
			return i;
	}
	return -1;
}

int find_index_map (node_t ** map, int other_x, int other_y)
{
	int i;

	for(i = 0 ; i < NBR_NODE ; i++)
	{
		if((map[i]->x == other_x) && (map[i]->y == other_y))
			return i;
	}
	return -1;
}


int check_flag (int * flag)
{
	int i;

	for(i = 0 ; i < NBR_NODE ; i++)
	{
		if(flag[i] == 0)
			return 1;
	}
	return 0;
}

