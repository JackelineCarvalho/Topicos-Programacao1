#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

/*
Q1) Desenvolva uma calculadora de equações do 2o grau.
O programa deverá solicitar ao usuário os coeficientes da equação e,
em seguida, o programa deverá verificar se é de fato uma equação do 2o grau.
Sendo, deve então calcular as raízes em qualquer das três possibilidades,
apresentá-las com os dizeres correspondentes à classificação das raízes entre,
“complexas conjugadas”, “reais e iguais” e “reais e distintas”.
*/
float delta, x1, x2, a, b, c;
_Complex float x,y;

int ResolveFuncao2grau(float a, float b, float c)
{
    delta = (b*b)-(4*a*c);
    if (a == 0)
    {
        printf("Não e uma equacao do segundo grau. \n\n");
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
