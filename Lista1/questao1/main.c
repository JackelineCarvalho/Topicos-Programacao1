#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

/*
Q1) Desenvolva uma calculadora de equa��es do 2o grau.
O programa dever� solicitar ao usu�rio os coeficientes da equa��o e,
em seguida, o programa dever� verificar se � de fato uma equa��o do 2o grau.
Sendo, deve ent�o calcular as ra�zes em qualquer das tr�s possibilidades,
apresent�-las com os dizeres correspondentes � classifica��o das ra�zes entre,
�complexas conjugadas�, �reais e iguais� e �reais e distintas�.
*/
float delta, x1, x2, a, b, c;
_Complex float x,y;

int ResolveFuncao2grau(float a, float b, float c)
{
    delta = (b*b)-(4*a*c);
    if (a == 0)
    {
        printf("N�o e uma equacao do segundo grau. \n\n");
        return 0;
    }

    else if (delta < 0)
    {
        x = (-b - (_Complex_I*sqrt(-delta) ))/(2*a);
        y = (-b + (_Complex_I*sqrt(-delta) ))/(2*a);
        printf("raizes complexas conjugadas x1 = %f %fi  e  x2 = %f %fi \n\n", creal(x), cimag(x), creal(y), cimag(y));
    }

    else if (delta == 0)
    {
        x1 = -b/(2*a);
        x2 = x1;
        printf("Raizes reais e iguais: x1 =  %f e x2 = %f \n\n", x1, x2);
    }

    else if (delta > 0)
    {
        x1 = (-b-(sqrt(delta)))/(2*a);
        x2 = (-b+(sqrt(delta)))/(2*a);
        printf("Raizes reais e distintas: x1 =  %f e x2 = %f \n\n", x1, x2);
    }
    return 0;
}





int main()
{

    while(1)
    {
    printf("Digite os coeficiente quadratico, coeficiente linear e o termo independente da equacao do 2 grau: \n");

    scanf("%f %f %f", &a, &b, &c);

    ResolveFuncao2grau(a, b, c);
    }
    return 0;

}
