#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "haar_wavelet.h"

void main()
{
	float* S_in  = NULL;
	float* S_out = NULL;
	int size = 8;
	int i;

	S_in  = malloc(size * sizeof(float));
	S_out = malloc(size * sizeof(float));
	if(S_in == NULL || S_out == NULL)
	{
		printf("Erreur : exit(-1)\n");
    	exit(-1);
	}

	S_in[0] = -48.0;
	S_in[1] = -16.0;
	S_in[2] = 48.0;
	S_in[3] = 16.0;
	S_in[4] = -16.0;
	S_in[5] = -48.0;
	S_in[6] = -32.0;
	S_in[7] = -16.0;
	/*S_in[8] = 0.0;
	S_in[9] = 16.0;
	S_in[10] = 0.0;
	S_in[11] = 0.0;
	S_in[12] = 16.0;
	S_in[13] = 16.0;
	S_in[14] = 16.0;
	S_in[15] = 0.0;
	/*S_in[16] = -48.0;
	S_in[17] = -16.0;
	S_in[18] = 48.0;
	S_in[19] = 16.0;
	S_in[20] = -16.0;
	S_in[21] = -48.0;
	S_in[22] = -32.0;
	S_in[23] = -16.0;
	S_in[24] = 0.0;
	S_in[25] = 16.0;
	S_in[26] = 0.0;
	S_in[27] = 0.0;
	S_in[28] = 16.0;
	S_in[29] = 16.0;
	S_in[30] = 16.0;
	S_in[31] = 0.0;*/


	printf("Valeur contenues dans S_in = [ ");
	for( i=0 ; i<size ; ++i)
	{
		printf("%f, ", S_in[i]);
	}
	printf("] \n");

	Haar_wavelet(S_in,S_out,size,8);

	printf("Valeur contenues dans S_out = [ ");
	for( i=0 ; i<size ; ++i)
	{
		printf("%f, ", S_out[i]);
	}
	printf("] \n");

	free(S_in);
	printf("free(S_in)\n");
	free(S_out);
	printf("free(S)\n");
} 