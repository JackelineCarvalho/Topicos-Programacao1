#include <iostream>

using namespace std;
/*

Q3) Os fatores primos de 20553 s�o 3, 13, 17 e 31.
Desenvolva uma rotina que calcule o maior fator primo do n�mero 3852914583882.
*/
const long int num = 3852914583882;
//long int num;
int Maior_Fator(long int n)
{
    long int _n = n;
    int maior = 1, i;
    for (i = 2 ; i <= n; i++)
    {
        while(n%i == 0)
        {
            n = n/i;
            maior = i;
        }
    }
    cout << "O maior fator primo de " << _n << " e = " << maior;
    return 0;
}

int main()
{
    //cout << "Digite um numero inteiropara calcular o maior fator primo: \n";
    //cin >> num;
    Maior_Fator(num);
    return 0;
}
