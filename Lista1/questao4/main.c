#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Q4) Desenvolva uma programa que possua uma lista de 10 a 20 pontos bidimensionais,
dados por duplas de n�meros decimais (xi,yi), e que pe�a ao usu�rio um ponto de localiza��o (xu,yu)
e uma dist�ncia X em unidades de dist�ncia. Ent�o, o programa deve calcular quais pontos (xi,yi)
encontram-se no raio de X unidades de dist�ncia do ponto central (xu,yu) dado.
N�o esque�a de avisar quando n�o h� nenhum ponto dentro do raio de dist�ncia dado.

*/



float v[18][2] = {{1,6}, {4,8},{-15.8, 7}, {20,20}, {0,0}, {1,13}, {22,4}, {19,94}, {-15,6}, {25,18}, {-3,-7}, {-9,-50}, {7,-23.5}, {-5.4,56}, {104,65}, {44, 13}, {2,1}, {1,1}};
int main()
{
while(1)
{
    float x, y, d, d_, difx, dify;
    printf("digite a coordenada x do ponto: \n");
    scanf("%f", &x);
    printf("digite a coordenada y do ponto: \n");
    scanf("%f", &y);
    printf("digite a distancia: \n");
    scanf("%f", &d);

    int linha, coluna, cont;
    cont = 0;
    printf(" Os pontos no raio de %.1f unidades de (%.1f,%.1f) sao: \n", d, x, y );
    for (linha = 0; linha<18; linha++)
    {
        for (coluna = 0; coluna<2; coluna++)
        {


            if (coluna == 0)
            {
                difx = x-v[linha][0];
            }
            if (coluna == 1)
            {
                dify = y-v[linha][1];
            }
        }
        d_ = sqrt(((difx)*(difx))+((dify)*(dify)));
        if (d_<=d)
        {
            printf("(%.1f %.1f)\n", v[linha][0], v[linha][1]);
            cont = cont+1;
        }
    }
    printf("\n");
    if (cont == 0)
    {
        printf("N�o existem pontos no raio de %f unidades de distancia do ponto dado\n\n", d);
    }
}
    return 0;
}

