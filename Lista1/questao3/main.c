#include <stdio.h>
#include <stdlib.h>


/*
Q3) Desenvolva uma rotina que solicita ao usuário a dimensão N (números de coordenadas, ou entradas) de vetores e,
 após isso, solicita dois vetores de N coordenadas e apresenta a soma vetorial deles.
*/

int main()
/* pedindo o numero  de coordenadas e os elementos dos vetores:*/
{
    int dim;
    float *v1, *v2;
    printf("Entre com  o  número de coordenadas dos vetores: \n");
    scanf("%d", &dim);
    if (dim <= 1)
        {
            printf("Entre com um numero de cordenadas valido");
        }
    else if (dim > 1)
    {
    v1 = (float*)malloc(sizeof(float)*dim);
    v2 = (float*)malloc(sizeof(float)*dim);
    int i, j;
    for (i=0; i<dim; i++)
    {
        printf("Entre com %d elemento do primeiro vetor: ", i+1);
        scanf("%f", &v1[i]);
    }
    for (j=0; j<dim; j++)
    {
        printf("Entre com %d elemento do segundo vetor: ", j+1);
        scanf("%f", &v2[j]);
    }
    /* funcao SomaVetorial sendo chamada no main: */
    SomaVetorial(dim, v1, v2);
    }
    return 0;
}

/* Criando a função soma vetorial: */
int SomaVetorial(int dim, float *v1, float *v2)
{
    int k, l;
    float *vsoma = 0;
    vsoma = (float*)malloc(sizeof(float)*dim);
    for (k=0; k<dim; k++)
    {
        vsoma[k] = v1[k] + v2[k];
    }
    printf("Vetor Soma:");
    for (l = 0; l < dim; l++)
    {
        printf("%.2f ", vsoma[l]);
    }
    return 0;
}

