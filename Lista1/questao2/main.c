#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, y, n;
int Multiplos(int x, int y, int n)
{
    int soma, i;
    soma = 0;
    if (x <= 0 || y <= 0)
    {
        printf("Digite numeros positivos");
         return 0;
    }
    for (i = 1; i < n; i++)
    {
        if (i%x == 0 || i%y == 0)
        {
        soma = soma + i;
        }
    }
    printf("A soma dos multiplos de %d e %d  ate %d e = %d \n\n", x, y, n, soma);
    return 0;
}


int main()
{
    while(1)
    {
        printf("Digite os numeros que quer saber os multiplos: \n");
        scanf("%d %d", &x, &y);
        printf("Digite o numero ate onde quer saber os multiplos: \n");
        scanf("%d", &n);
        Multiplos(x, y, n);
    }
    return 0;
}
