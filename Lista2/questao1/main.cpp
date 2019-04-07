#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

/*
Q1) O número 2**15 = 32768 e a soma dos seus dígitos é: 3 + 2 + 7 + 6 + 8 = 26.
Faça uma rotina que some os dígitos do número 2^X, onde X é pedido ao usuário.
 Teste a sua rotina com valores para X grandes, por exemplo X = 1001.
*/

int main()
{
    while(1)
    {
        long int x, n, _n, s;
        cout << "Digite um numero inteiro\n";
        cin >> x;
        n = pow(2, x);
        _n = n;
        s = 0;
        while (n >0)
        {
            s += (n%10);
            n = n/10;
        }
        cout << "A soma dos digitos do numero " << _n << " e = " << s << "\n\n";
    }
        return 0;
}
