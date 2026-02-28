//ALOCACAO UNICA

#include<stdlib.h>
#define LIN 6
#define COL 6

int main() 
{
  int **mat;
  int i, j;
  
  //aloca um vetor de LIN ponteiros para a linha
  mat = malloc (LIN * sizeof(int*));
  
  for(i=0; i < LIN; i++)
  {
    mat[i] = malloc(COL * sizeof(int));
  }
  
  for(i=0; i < LIN; i++)
  {
    for(j=0; j < COL; j++)
    {
      mat[i][j] = 0;
    }
  }
  
  for(i=0; i < LIN; i++)
  {
    free(mat[i]);
  }
  
  free(mat);
  return 0;
}