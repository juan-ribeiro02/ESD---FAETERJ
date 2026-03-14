#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Triangulo.h"

struct triangulo
{
    Ponto *pontoA, *pontoB, *pontoC;
    float ladoAB, ladoBC, ladoAC;
};

tTri *tri_cria(Ponto *ptA, Ponto *ptB, Ponto *ptC)
{
    tTri *tri_teste = (tTri *)malloc(sizeof(tTri));

    tri_teste->pontoA = ptA;
    tri_teste->pontoB = ptB;
    tri_teste->pontoC = ptC;

    tri_teste->ladoAB = pto_distancia(ptA, ptB);
    tri_teste->ladoBC = pto_distancia(ptB, ptC);
    tri_teste->ladoAC = pto_distancia(ptA, ptC);

    return tri_teste;
}

float tri_perimetro(tTri *triangulo)
{
    return triangulo->ladoAB + triangulo->ladoBC + triangulo->ladoAC;
}

float tri_area(tTri *triangulo)
{
    float semiPerimetro = tri_perimetro(triangulo) / 2;

    return sqrt(semiPerimetro * (semiPerimetro - triangulo->ladoAB) * (semiPerimetro - triangulo->ladoBC) * (semiPerimetro - triangulo->ladoAC));
}
