#include <iostream>
#include <stdio.h>
#include <bitset>
#include <math.h>


using namespace std;

/*
Q1) Elabore uma subrotina que imprima a tabela ASCII, com a formatação abaixo exemplificada.
Essa rotina deve receber três parâmetros. O primeiro e o segundo parâmetros especificam o início e fim da faixa de códigos ASCII
a serem impressos. O terceiro parâmetro especifica o número de linhas que devem ser impressas em cada 'página' da tabela
(como se fosse em uma impressora). No caso da omissão de algum desses valores, deve-se assumir os valores 32 e 127,
respectivamente, para o início e fim da faixa de códigos ASCII, e 25 para o tamanho da 'página'.
Também, para os dois primeiros parâmetros deve-se verificar se eles estão ordenados e estão na faixa de valores de
códigos 'imprimível' da tabela ASCII, ou seja, entre 32 a 127. Se forem menor ou maior do que esses valores limites,
eles devem ser ajustados para os respectivos limites.
*/

 void Imprime_TabelaASCII(int i, int f, int t)
{
    if (i < 32)
    {
        i = 32;
    }
    if (f >= 32 && f < i)
    {
        int aux;
        aux = i;
        i = f;
        f = aux;
    }
    if (f < 32 || f > 127)
    {
        f = 127;
    }
    if (t <= 0)
    {
        t = 25;
    }
    cout << "inicio: " << i << ", fim: " << f << ", tamanho da pagina: " << t << endl;

    int n = 0;
    double num_paginas = ceil(double(f-i+1)/t);
    int j = i;
    for (n; n < num_paginas; n++)
    {
        cout << "+-----------+-----+-----+-----+-----+" << endl;
        cout << "|  Binario  | Oct | Hex | Dec | Chr |" << endl;
        cout << "+-----------+-----+-----+-----+-----+" << endl;
        for (int k=0; k < t; k++)
        {
            if (j == f+1)
            {
                break;
            }
            cout << "| " << std::bitset<8>(j) << " | " << std::oct << j << " |  " << std::hex << j << " |  " << std::dec << j << " |  " << char(j) << "  |" << endl;
            j += 1;
        }
    }
}

int main()
{
    while(1)
    {
        int inicio, fim, tamanho;

        cout << "Entre com o inicio e fim da faixa de codigos ASCII a serem impressos e o tamanho da pagina: " << endl;
        cin >> inicio;
        cin >> fim;
        cin >> tamanho;
        cout << endl;

        Imprime_TabelaASCII(inicio, fim, tamanho);
    }
    return 0;
}
