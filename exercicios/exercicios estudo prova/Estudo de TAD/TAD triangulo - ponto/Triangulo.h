#include "Ponto.h"

//Criacao do tipo
typedef struct triangulo tTri;

//funcao que pega 3 tipos ponto e cria o tringulo
tTri * tri_cria(Ponto * ptA, Ponto * ptB, Ponto * ptC);

//calcula perimetro do triangulo
float tri_perimetro(tTri * triangulo);

//calcula area do triangulo
float tri_area(tTri * triangulo);