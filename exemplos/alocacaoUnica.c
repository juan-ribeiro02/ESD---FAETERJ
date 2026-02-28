//ALOCACAO UNICA

#include<stdlib.h>
#define LIN 6
#define COL 6

int main()
{
  int *mat;
  int i, j;
  
  //aloca um vetor com todos os elementos da matriz
  mat = malloc (LIN * COL * sizeof(int)); //linha vezes coluna (quantidade de espacos do vetor) vezes o tamanho de um inteiro
  
  for(i=0; i < LIN; i++)
  {
    for(j=0; j < COL; j++)
    {
      mat[(i*COL) + j] = 0; //calcula a posicao de cada elemento
    }
  }
  
  free(mat); //libera a memoria 
  
  return 0;
}