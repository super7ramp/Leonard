#include <stdio.h>
#include <stdlib.h>
#include "../shortest_path.h"

node_t * create_node (float x, float y);
element_t * create_neighbour (node_t * node, int weight);

int main ()
{
	node_t ** map;

	map = malloc(sizeof(node_t*)*NBR_NODE);

	node_t ** path;

	//path = malloc(sizeof(node_t*)*NBR_NODE);

	node_t * node1;
	node_t * node2;
	node_t * node3;
	node_t * node4;
	node_t * node5;

	element_t * voisin1_1;
	element_t * voisin1_2;

	element_t * voisin2_1;
	element_t * voisin2_2;
	element_t * voisin2_3;
	element_t * voisin2_4;

	element_t * voisin3_1;
	element_t * voisin3_2;
	
	element_t * voisin4_1;
	element_t * voisin4_2;
	
	element_t * voisin5_1;
	element_t * voisin5_2;

	node1 = create_node(1, 2);
	node2 = create_node(2, 1);
	node3 = create_node(2, 3);
	node4 = create_node(3, 2);
	node5 = create_node(4, 1);

	voisin1_1 = create_neighbour(node2, 4);
	voisin1_2 = create_neighbour(node3, 1);

	voisin2_1 = create_neighbour(node1, 1);
	voisin2_2 = create_neighbour(node3, 1);
	voisin2_3 = create_neighbour(node4, 5);
	voisin2_4 = create_neighbour(node5, 1);

	voisin3_1 = create_neighbour(node1, 1);
	voisin3_2 = create_neighbour(node2, 4);

	voisin4_1 = create_neighbour(node2, 4);
	voisin4_2 = create_neighbour(node5, 1);

	voisin5_1 = create_neighbour(node2, 4);
	voisin5_2 = create_neighbour(node4, 5);

	//construction chaine voisin pour node1
	node1->neighbours = voisin1_1;
	voisin1_1->next_neighbour = voisin1_2;
	voisin1_2->next_neighbour = NULL;

	//construction chaine voisin pour node2
	node2->neighbours = voisin2_1;
	voisin2_1->next_neighbour = voisin2_2;
	voisin2_2->next_neighbour = voisin2_3;
	voisin2_3->next_neighbour = voisin2_4;
	voisin2_4->next_neighbour = NULL;

	//construction chaine voisin pour node3
	node3->neighbours = voisin3_1;
	voisin3_1->next_neighbour = voisin3_2;
	voisin3_2->next_neighbour = NULL;

	//construction chaine voisin pour node4
	node4->neighbours = voisin4_1;
	voisin4_1->next_neighbour = voisin4_2;
	voisin4_2->next_neighbour = NULL;

	//construction chaine voisin pour node5
	node5->neighbours = voisin5_1;
	voisin5_1->next_neighbour = voisin5_2;
	voisin5_2->next_neighbour = NULL;



	//affichage noeud avec carac et voisin
	/*printf("noeud 1 => 	coord: 	(%f,%f)\n"
			"			voisin1:	[(%f,%f) weight: %d]\n"
			"			voisin2:	[(%f,%f) weight: %d]\n",
			node1->x, node1->y, 
			voisin1_1->neighbour->x, voisin1_1->neighbour->y, voisin1_1->weight,
			voisin1_2->neighbour->x, voisin1_2->neighbour->y, voisin1_2->weight);
*/

	map[0]=node1;
	map[1]=node2;
	map[2]=node3;
	map[3]=node4;
	map[4]=node5;

	//printf("n1 (%f,%f)\nv1 (%f,%f)\nv2 (%f,%f)\n",map[0]->x,map[0]->y,map[0]->neighbours->neighbour->x,map[0]->neighbours->neighbour->y,map[0]->neighbours->next_neighbour->neighbour->x,map[0]->neighbours->next_neighbour->neighbour->y);
	
	path = dijkstra (4, 1, 2, 3, map);

	int i;
	for(i = 0 ; path[i] != NULL ; i++)
	{
		printf("path %d:\n",i);
		printf("(%f,%f)\n",path[i]->x, path[i]->y);
	}
		
	free(map);
	free(path);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(voisin1_1);
	free(voisin1_2);
	free(voisin2_1);
	free(voisin2_2);
	free(voisin2_3);
	free(voisin2_4);
	free(voisin3_1);
	free(voisin3_2);
	free(voisin4_1);
	free(voisin4_2);
	free(voisin5_1);
	free(voisin5_2);


	return 0;
}

node_t * create_node (float x, float y)
{
	node_t * node;
	node = malloc(sizeof(node_t));
	node->neighbours = malloc(sizeof(element_t));

	node->x = x;
	node->y = y;



	return node;
}

element_t * create_neighbour (node_t * node, int weight)
{
	element_t * element;
	element = malloc(sizeof(element_t));
	element->next_neighbour = malloc(sizeof(element_t));
	element->neighbour = malloc(sizeof(node_t));

	element->weight = weight;
	element->next_neighbour = NULL;
	element->neighbour = node;

	return element;

}

/*
			noeud 3 =>	coord: 	(%f,%f)\n
						voisin:	[(%f,%f) weight: %d]\n
						voisin:	[(%f,%f) weight: %d]\n
			noeud 4 =>	coord: 	(%f,%f)\n
						voisin:	[(%f,%f) weight: %d]\n
						voisin:	[(%f,%f) weight: %d]\n
			noeud 5 =>	coord: 	(%f,%f)\n
						voisin:	[(%f,%f) weight: %d]\n
						voisin:	[(%f,%f) weight: %d]\n
*/