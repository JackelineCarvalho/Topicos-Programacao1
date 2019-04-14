#include <iostream>
#include <math.h>

/**
 * UFRJ   - Universidade Federal do Rio de Janeiro
 * DMA/IM - Departamento de Matematica Aplicada do Instituto de Matematica
 *
 * Top. Mat. Aplicada A - Programacao I
 * Módulo Março: Introdução à Programação Estruturada
 *
 *          ED01 - Primeiro Estudo Dirigido
 *
 * Aluna: JACKELINE SOUZA DE CARVALHO - DRE: 116043481
 *
*/

//Calculadora Vetorial Simples


using namespace std;
//delaclaracao de variaveis:
int DIM = 3;

void Apresenta_Menu(void)
{
    cout << " -------------------------- MENU DE OPCOES: --------------------------- " << endl;
    cout << "                  1) Soma de Dois Vetores" << endl;
    cout << "                  2) Multiplicao por escalar" << endl;
    cout << "                  3) Combinacao linear de dois vetores" << endl;
    cout << "                  4) Produto Interno" << endl;
    cout << "                  5) Norma vetorial (modulo)" << endl;
    cout << "                  6) Distancia entre dois vetores" << endl;
    cout << "                  7) Angulo entre vetores" << endl;
    cout << "                  8) Alterar dimensao dos vetores" << endl;
    cout << "                  9) Sair do Programa" << endl;
    cout << " ---------------------------------------------------------------------- " << endl;
    cout << "Digite uma opcao: " << endl;
}

void Entra_Coordenadas(float v[])
{
    int i;
    float valor;

    for (i = 0; i< DIM; i++)
    {
        cout << "Entre com a coordenada " << i+1 << " do vetor: " << endl;
        cin >> valor;
        v[i] = (valor);
    }
}
//opcao1:
void Soma_Vetores(float v[], float u[], float result[])
{
    int i;
    float Soma[DIM];
    for(i = 0; i< DIM; i++)
    {
        Soma[i] = (v[i] + u[i]);
        result[i] = Soma[i];
    }
}
//opcao2:
void Multiplica_vetor(float lmbd, float v[], float result[])
{
    int i;
    for (i = 0; i < DIM; i++)
    {
        result[i] = lmbd*v[i];
    }
}
//opcao3:
void Comb_Linear(float c1, float c2, float v1[], float v2[], float result[])
{
    float c1v1[DIM], c2v2[DIM];
    Multiplica_vetor(c1,v1,c1v1);
    Multiplica_vetor(c2,v2,c2v2);
    Soma_Vetores(c1v1,c2v2,result);
}
//opcao4:
float Produto_Interno(float v1[], float v2[])
{
    float soma = 0;
    int i;
    for (i = 0; i<DIM; i++)
    {
        soma = soma + v1[i]*v2[i];
    }
    return soma;
}
//opcao5:
float Norma(float v1[])
{
    float prod_int_v1v1, norma;
    prod_int_v1v1 = Produto_Interno(v1, v1);
    norma = sqrt(prod_int_v1v1);
    return norma;
}
//opcao6:
float Distancia(float v1[], float v2[])
{
    float dist, v2_[DIM],soma[DIM];
    Multiplica_vetor(-1, v2, v2_);
    Soma_Vetores(v1, v2_, soma);
    dist = Norma(soma);
    return dist;
}
//opcao7:
double Angulo(float v1[], float v2[])
{
    double teta;
    teta =acos((Produto_Interno(v1, v2))/(Norma(v1)*Norma(v2)));
    return teta;
}

int main()
{
    float resultado[DIM];
    while(1)
    {
        int i;
        Apresenta_Menu();
        int opcao;
        cin >> opcao;
        if (opcao == 9)
        {
            return 0;
        }

        if (opcao == 1)
        {
            float v1[DIM];
            float v2[DIM];
            cout << "Vetor 1: \n" << endl;
            Entra_Coordenadas(v1);
            cout << "Vetor 2: \n" << endl;
            Entra_Coordenadas(v2);
            Soma_Vetores(v1, v2, resultado);
            cout << "[";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }
            }
            cout << "] + [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v2[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v2[i];
                }
            }
            cout << "] = [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << resultado[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << resultado[i];
                }
            }
            cout << "]\n\n" << endl;
        }

        if (opcao == 2)
        {
            float lmbd;
            float v1[DIM];
            cout << "Entre com a constante multiplicativa: " << endl;
            cin >> lmbd;
            Entra_Coordenadas(v1);
            Multiplica_vetor(lmbd, v1, resultado);
            cout << lmbd << " * [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }

            }
            cout << "] = [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << resultado[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << resultado[i];
                }
            }
            cout << "]\n\n" << endl;
        }

        if (opcao == 3)
        {
            float c1, c2;
            float v1[DIM], v2[DIM];
            cout << "Entre com a costante multiplicativa do primeiro vetor" << endl;
            cin >> c1;
            cout << "Entre com a costante multiplicativa do segundo vetor" << endl;
            cin >> c2;
            cout << "Digite as coordenadas do vetor 1: \n" << endl;
            Entra_Coordenadas(v1);
            cout << "Digite as coordenadas do vetor 2: \n" << endl;
            Entra_Coordenadas(v2);
            Comb_Linear(c1, c2, v1, v2, resultado);
            cout << c1<<" * [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }
            }
            cout << "] + "<<c2<<" * [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v2[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v2[i];
                }
            }
            cout << "] = [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << resultado[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << resultado[i];
                }
            }
            cout << "]\n\n" << endl;
        }

        if (opcao == 4)
        {
            float v1[DIM], v2[DIM];
            cout << "Vetor 1:" << endl;
            Entra_Coordenadas(v1);
            cout << "Vetor 2:" << endl;
            Entra_Coordenadas(v2);
            cout <<"<[";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }
            }
            cout << "] , [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v2[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v2[i];
                }
            }
            cout << "]> = " << Produto_Interno(v1, v2);
            cout << "\n\n";
        }

        if (opcao == 5)
        {
            float v1[DIM];
            float Norm;
            Entra_Coordenadas(v1);
            Norm = Norma(v1);
            cout <<"|[";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }
            }
            cout << "]| = " << Norm << endl;
        }

        if (opcao == 6)
        {
            float v1[DIM], v2[DIM];
            float D;
            cout << "Entre com as coordenadas do primeiro vetor:" << endl;
            Entra_Coordenadas(v1);
            cout << "Entre com as coordenadas do segundo vetor:" << endl;
            Entra_Coordenadas(v2);
            D = Distancia(v1, v2);
            cout <<" Distancia entre [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }
            }
            cout << "] e [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v2[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v2[i];
                }
            }
            cout << "] = " << D << endl;
        }

        if (opcao == 7)
        {
            float v1[DIM], v2[DIM];
            double teta;
            cout << "Entre com as coordenadas do primeiro vetor:" << endl;
            Entra_Coordenadas(v1);
            cout << "Entre com as coordenadas do segundo vetor:" << endl;
            Entra_Coordenadas(v2);
            teta = Angulo(v1, v2);
            cout <<" Angulo entre [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v1[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v1[i];
                }
            }
            cout << "] e [";
            for (i=0; i< DIM; i++)
            {
                if(i<DIM-1)
                {
                    cout << v2[i] << ", ";
                }
                if(i==DIM-1)
                {
                    cout << v2[i];
                }
            }
            cout << "] = " << teta << " Radianos" << endl;
        }

        if (opcao == 8)
        {
            cout << "Digite a dimensao desejada: " << endl;
            cin >> DIM;
        }

        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4  && opcao != 5 && opcao != 6  && opcao != 7 && opcao != 8 && opcao != 9)
        {
            cout << "Opcao Invalida.\n" << endl;
        }
    }
    return 0;
}
