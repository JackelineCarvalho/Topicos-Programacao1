#include <iostream>

using namespace std;

/*
Q2) Cada novo termo na sequência de Fibonacci é gerado pela adição dos dois termos antecedentes.
Iniciando com os dois primeiros termos, 1 e 2, os primeiros 10 termos da sequência são: 1, 2, 3, 5, 8, 13, 21, 34, 55 e 89.
Faça uma rotina que some os termos ímpares da sequência de Fibonacci cujo valor não exceda o número X, onde X é pedido ao usuário.
Teste a sua rotina com número grande, por exemplo, X = quatro milhões.

*/

void SomaImparesFibo(long int x)
{
    long int x1 = 1, x2 = 2, x3 = 0, soma = 0;
    if (x == 1 || x == 2)
        cout << "soma = 1 ";

    x3 = x1 + x2;
    while (x3 <= x)
    {
        if (x3 %2 != 0)
        {
            soma += x3;
        }
        x1 = x2;
        x2 = x3;
        x3 = x1 + x2;
    }
       soma = soma + 1;
    cout << "A soma dos impares da sequencia de fibonacci cujo valor nao excede " << x << " e = " << soma << "\n\n";
}


int main()
{
    while(1)
    {
        long int x;
        cout << "Entre com um numero inteiro:\n";
        cin >> x;
        SomaImparesFibo(x);
    }
    return 0;
}

