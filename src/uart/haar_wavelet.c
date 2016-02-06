#include "haar_wavelet.h"

void wave_down(float S[40][20], float d[40][20], float* S_in, int size, int* index)
{
	int new_size = size/2;
	int i;
	*index = 0;

	for( i=0 ; i<new_size ; i++ )
	{
		S[*index][i] = (S_in[2*i] + S_in[(2*i)+1])/2;
		d[*index][i] = (S_in[2*i] - S_in[(2*i)+1])/2;
		//printf("[S[%d][%d]=%.1f, ", *index, i, S[*index][i]);
		//printf("[d[%d][%d]=%.1f, ", *index, i, d[*index][i]);
	}
	//printf("]\n");
	*index = *index -1;

	while( new_size != 1 ) 
	{
		new_size = new_size/2;
		*index = *index +1;
		for( i=0 ; i<new_size ; ++i )
		{
			S[*index+1][i] = (S[*index][2*i] + S[*index][(2*i)+1])/2;
			d[*index+1][i] = (S[*index][2*i] - S[*index][(2*i)+1])/2;
			//printf("[S[%d][%d]=%.1f, ", *index+1, i, S[*index+1][i]);
			//printf("[d[%d][%d]=%.1f, ", *index+1, i, d[*index+1][i]);
		}
		//printf("]\n");
	}
	*index = *index +1;
}
//array[ligne][colonnes]
void filter_wave(float S[40][20], float d[40][20], int size1, int size2, float Threshold)
{
	int i,j;
	//printf("size2 =%d\n", size2);
	for( i=0 ; i<size2 ; ++i )
	{
		for( j=0 ; j<size1 ; ++j )
		{
			if( abs(d[i][j]) <= Threshold )
			{
				//printf("Valeur à mettre à zéro d[%d][%d]=%.1f\n", i, j, d[i][j]);
				d[i][j] = 0.0;
			}
		}
	}
	if( S[size2-1][0] <= Threshold )
		S[size2-1][0] = 0.0;
	//printf("Valeur à mettre à zéro S[%d][%d]=%.1f\n", size2-1, 0, S[size2-1][0]);
}

void wave_up(float S[40][20], float d[40][20], float* S_out, int old_size, int* index)
{
	int new_size = 1;
	int i;
	//printf("S[%d][%d]=%.1f\n", *index, 0, S[*index][0]);
	while( new_size != old_size/2 )
	{
		for( i=0 ; i<new_size ;  ++i )
		{
			S[*index-1][2*i] = S[*index][i] + d[*index][i];
			//printf("S[%d][%d]=%.1f, ", (*index-1), 2*i, S[*index-1][2*i]);
			S[*index-1][(2*i)+1] = S[*index][i] - d[*index][i];
			//printf("S[%d][%d]=%.1f, ", (*index-1), (2*i)+1, S[*index-1][(2*i)+1]);
		}
		//printf("\n");
		new_size = new_size *2;
		*index = *index -1;
	}

	for ( i=0 ; i<(old_size/2) ; ++i)
	{
		S_out[2*i]     = S[0][i] + d[0][i];
		S_out[(2*i)+1] = S[0][i] - d[0][i];
	}
}

void Haar_wavelet(float* S_in, float* S_out, int size, int Threshold)
{
	int size_1 = size /2;
	int size_2 = (int)(log((double)size)/log(2.0));
	int index;
	//float** S = NULL;
	//float** d = NULL;
	float S[40][20];
	float d[40][20];
	int i,j;

	//printf("size_1=%d et size_2=%d\n et ", size_1, size_2);

	wave_down(S,d,S_in,size,&index);
	filter_wave(S,d,size_1,size_2,Threshold);
	wave_up(S,d,S_out,size,&index);
}
