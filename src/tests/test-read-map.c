#include <stdio.h>
#include <stdlib.h>
#include "../map/map_reader.h"

/** To compile this (since Makefile is not up-to-date):
  * gcc -Wall ../map/map_reader.c test-read-map.c -o test-read-map
  * To run this:
  * ./test-read-map map.csv
  */
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Syntax: %s map.csv\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    
    graph_t *myTestGraph = createGraph(file);
    printGraph(myTestGraph);
    freeGraph(myTestGraph);
    
    fclose(file);
    return 0;
}
