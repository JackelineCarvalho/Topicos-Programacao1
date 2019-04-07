#include <iostream>
#include <vector>

using namespace std;

/*
Q5) Desenvolva um programa que apresenta um “Menu de Opções” ao seu usuário.
 O menu de opções deve conter as seguintes opções:
1) Soma de dois vetores: w = v + u
2) Subtração de dois vetores: w = v - u
3) Sair do programa
Enquanto o usuário não selecionar a última opção, o programa, após realizar a operação escolhida,
deverá apresentará novamente o menu de opções.


*/

int DIM;


void Apresenta_Menu(void)
{
    cout << "Menu de Opcoes:" << endl;
    cout << "1) Soma de Dois Vetores: w = v + u " << endl;
    cout << "2) Subtracao de Dois Vetores: w = v - u" << endl;
    cout << "3) Sair do Programa" << endl;
    cout << "Digite uma das opcoes: " << endl;
}

void Entra_Coordenadas(float v[], float u[])
{
    int i;
    float valor1, valor2;

    for (i = 0; i< DIM; i++)
    {
        cout << "Entre com a coordenada " << i+1 << " do vetor v: " << endl;
        cin >> valor1;
        v[i] = (valor1);
    }
    for (i = 0; i< DIM; i++)
    {
        cout << "Agora entre com a coordenada " << i+1 << " do vetor u: " << endl;
        cin >> valor2;
        u[i] = (valor2);
    }
}


void Soma_Vetores(float v[], float u[])
{
    int i;
    float Soma[DIM];
    for(i = 0; i< DIM; i++)
    {
        Soma[i] = (v[i] + u[i]);
    }
    cout << "[";
    for (i=0; i< DIM; i++)
    {
        if(i<DIM-1)
        {
            cout << v[i] << ", ";
        }
        if(i==DIM-1)
        {
            cout << v[i];
        }

    }
    cout << "] + [";
    for (i=0; i< DIM; i++)
    {
        if(i<DIM-1)
        {
            cout << u[i] << ", ";
        }
        if(i==DIM-1)
        {
            cout << u[i];
        }
    }
    cout << "] = [";
    for (i=0; i< DIM; i++)
    {
        if(i<DIM-1)
        {
            cout << Soma[i] << ", ";
        }
        if(i==DIM-1)
        {
            cout << Soma[i];
        }
    }
    cout << "]\n\n" << endl;

}


void Subtrai_Vetores(float v[], float u[])
{
    int i;
    float Dif[DIM];
    for(i = 0; i< DIM; i++)
    {
        Dif[i] = (v[i] - u[i]);
    }
    cout << "[";
    for (i=0; i< DIM; i++)
    {
        if(i<DIM-1)
        {
            cout << v[i] << ", ";
        }
        if(i==DIM-1)
        {
            cout << v[i];
        }
    }
    cout << "] - [";
    for (i=0; i< DIM; i++)
    {
        if(i<DIM-1)
        {
            cout << u[i] << ", ";
        }
        if(i==DIM-1)
        {
            cout << u[i];
        }
    }
    cout << "] = [";
    for (i=0; i< DIM; i++)
    {
        if(i<DIM-1)
        {
            cout << Dif[i] << ", ";
        }
        if(i==DIM-1)
        {
            cout << Dif[i];
        };
    }
    cout << "]\n\n" << endl;

}


int main()
{

    while(1)
    {
        Apresenta_Menu();
        int opcao;
        cin >> opcao;
        if (opcao == 3)
        {
            return 0;
        }
        cout << "Entre com a dimensao: " <<endl;
        cin >> DIM;
        float v1[DIM], v2[DIM];
        Entra_Coordenadas(v1, v2);


        if (opcao == 1)
        {
            Soma_Vetores(v1, v2);
        }
        if (opcao == 2)
        {
            Subtrai_Vetores(v1, v2);
        }
    }
    return 0;
}
