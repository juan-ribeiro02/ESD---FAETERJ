#include <stdio.h>
#include <stdlib.h>
#include "Triangulo.h"
#include "Ponto.h"

int main()
{
    Ponto *pt1, *pt2, *pt3;
    float perimetro, area;
    tTri *t;
    
    pt1 = pto_cria(2, 2);
    pt2 = pto_cria(5, 5);
    pt3 = pto_cria(5, 2);
    
    t = tri_cria(pt1, pt2, pt3);
    
    perimetro = tri_perimetro(t);
    area = tri_area(t);
    
    printf("%.3f", perimetro);
    printf("\n%.3f", area);

    return 0;
}