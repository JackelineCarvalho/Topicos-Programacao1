#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

/*
Q1) O n�mero 2**15 = 32768 e a soma dos seus d�gitos �: 3 + 2 + 7 + 6 + 8 = 26.
Fa�a uma rotina que some os d�gitos do n�mero 2^X, onde X � pedido ao usu�rio.
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
