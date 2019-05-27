#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>


/**
 * UFRJ   - Universidade Federal do Rio de Janeiro
 * DMA/IM - Departamento de Matematica Aplicada do Instituto de Matematica
 *
 * Top. Mat. Aplicada A - Programacao I
 * Módulo Março: Introdução à Programação Estruturada
 *
 *          ED02 - Segundo Estudo Dirigido
 *
 * Aluna: JACKELINE SOUZA DE CARVALHO - DRE: 116043481
 *
*/

/** Calculadora Matricial **/

using namespace std;

// Area de variaveis globais
vector< vector< vector<float> > > ListaDeMatrizes;
vector< vector< vector<float> > > ListaDeMatrizes_backup;
FILE *arq;
/** funcao que le o arquivo texto e transfere as matrizes do arquivo para uma lista de matrizes no programa **/
void LendoMatriz(ifstream &arq)
{
    int m,n;
    vector< vector<float> > mat;
    arq >> m >> n;
    for( int i = 0 ; i < m ; i++)
    {
        vector<float> linha;
        float elemento;
        //mat[i].resize(n);
        for(int j = 0; j < n ; j++)
        {
            arq >> elemento;
            linha.push_back(elemento);
        }
        mat.push_back(linha);
    }
    ListaDeMatrizes.push_back(mat);
}

/** funcao que printa uma matriz **/
void Print_Matriz(vector< vector<float> > mat)
{
    if(mat.size()>0)
    {
        int n_linhas = mat.size();

        int n_colunas = mat[0].size();
        cout << "A matriz possui " << n_linhas << " linhas e " << n_colunas << " Colunas" << endl;
        for(int i = 0 ; i < n_linhas ; i++)
        {
            for(int j = 0; j < n_colunas; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

/** printa um vetor "linha" de uma matriz passada como paramentro **/
void Print_vetor(vector<float> vetor) // printa apenas a linha desejada da matriz
{
    cout << "[";
    for(int i = 0; i < vetor.size(); i++)
    {
        if (i == vetor.size()-1)
        {
           cout << vetor[i] << "]" << endl;
        }
        else
        {
            cout << vetor[i] << ", ";
        }
    }
}

/** funcao que recebe um vetor e o printa como coluna de uma matriz **/
void Print_coluna(vector<float> vetor)
{
    for(int i = 0; i < vetor.size(); i++)
    {
        cout << "[" << vetor[i] << "]" << endl;
    }
}

/** Apresenta o menu principal **/
void Apresenta_Menu_Principal(void)
{
    cout << " -------------------------- MENU DE OPCOES: --------------------------- " << endl;
    cout << "                   1) Operacoes Matriciais" << endl;
    cout << "                   2) Manipular lista de matrizes" << endl;
    cout << "                   0) Gravar lista de matrizes no arquivo e sair" << endl;
    cout << " ---------------------------------------------------------------------- " << endl;
    cout << "Digite uma opcao: " << endl;
}

/** 1) Apresenta o menu de operacoes matriciais **/
void Menu_De_Operacoes(void)
{
    cout << " -------------- MENU DE OPCOES DE OPERACOES MATRICIAIS: --------------- " << endl;
    cout << "             3) Soma matricial: C = A + B" << endl;
    cout << "             4) Subtracao matricial: C = A - B" << endl;
    cout << "             5) Multiplicação por escalar: C = aA" << endl;
    cout << "             6) Multiplicação Matricial: C = A x B" << endl;
    cout << "             7) Transposição." << endl;
    cout << "             8) Permutar duas linhas de posiçao." << endl;
    cout << "             9) Permutar duas colunas de posição." << endl;
    cout << "             10) Somar a uma linha uma outra linha." << endl;
    cout << "             11) somar a uma coluna uma outra coluna." << endl;
    cout << "             12) Multiplicar uma única linha, por um escalar." << endl;
    cout << "             13) Multiplicar uma única coluna, por um escalar." << endl;
    cout << "             14) Inversão de matrizes quadradas 2x2." << endl;
    cout << " ---------------------------------------------------------------------- " << endl;
    cout << "Digite uma opcao: " << endl;
}

/** 2) Apresenta o menu de operacoes na lista de matrizes **/
void Menu_da_Lista_Matrizes(void)
{
    cout << " -------------------------- MENU DE OPCOES DA LISTA DE MATRIZES: --------------------------- " << endl;
    cout << "             15) Imprimir uma matriz da lista de matrizes." << endl;
    cout << "             16) Inserir uma nova matriz." << endl;
    cout << "             17) Inserir uma matriz identidade n x n." << endl;
    cout << "             18) Altera uma matriz da lista." << endl;
    cout << "             19) Remover uma matriz da lista." << endl;
    cout << "             20) Apresentar lista de matrizes." << endl;
    cout << "             21) Gravar lista com um nome diferente." << endl;
    cout << "             22) Ler uma outra lista de matrizes, acrescentando a lista existente." << endl;
    cout << "             23) zerar lista de matrizes." << endl;
    cout << " ---------------------------------------------------------------------- " << endl;
    cout << "Digite uma opcao: " << endl;
}

/** 3) Soma matricial: C = A + B **/
vector< vector<float> > Soma_matrizes(vector< vector<float> > mat1, vector< vector<float> > mat2)
{
    vector< vector<float> > vetsoma;
    if(mat1.size() == mat2.size() && mat1[0].size() == mat2[0].size())
    {
        for (int i=0; i < mat1.size(); i++)
        {
            vector<float> linhasoma;
            float soma;
            for (int j=0; j < mat1[0].size(); j++)
            {
                soma = mat1[i][j]+ mat2[i][j];
                linhasoma.push_back(soma);
            }
            vetsoma.push_back(linhasoma);
        }
    }
    else
    {
        cout << "Nao e possivel realizar essa operacao. Matrizes de dimensoes diferentes." << endl;
    }
    return vetsoma;
}

/** 4) Subtracao matricial: C = A - B **/
vector< vector<float> > Subtrai_matrizes(vector< vector<float> > mat1, vector< vector<float> > mat2)
{
    vector< vector<float> > vetsub;
    if(mat1.size() == mat2.size() && mat1[0].size() == mat2[0].size())
    {
        for (int i=0; i < mat1.size(); i++)
        {
            vector<float> linhasub;
            float sub;
            for (int j=0; j < mat1[0].size(); j++)
            {

                sub = mat1[i][j]- mat2[i][j];
                linhasub.push_back(sub);
            }
            vetsub.push_back(linhasub);
        }
    }
    else
    {
        cout << "Nao e possivel realizar essa operacao. Matrizes de dimensoes diferentes." << endl;
    }
    return vetsub;
}

/** 5) Multiplicação por escalar: C = aA **/
vector< vector<float> > Mult_Matriz_escalar(vector< vector<float> > mat, float lambda)
{
    vector< vector<float> > lambda_mat;
    for (int i=0; i < mat.size(); i++)
    {
        vector<float> linha;
        float elemento;
        for (int j=0; j < mat[0].size(); j++)
        {
            elemento = mat[i][j]*lambda;
            linha.push_back(elemento);
        }
        lambda_mat.push_back(linha);
    }
    return lambda_mat;
}

float produto_interno(vector<float> v1, vector<float> v2)
{
    float prod;
    if(v1.size() == v2.size())
    {
        for(int i = 0; i < v1.size(); i++)
        {
            prod += v1[i] * v2[i];
        }
    }
    return prod;
}
/** 7) Transposição. **/
vector< vector<float> > Transposta(vector< vector<float> > mat)
{
    int m_linhas = mat.size();
    int n_colunas = mat[0].size();
    vector< vector<float> > transp;
    float elemento;
    for (int i = 0; i < n_colunas; i++)
    {
        vector<float> linha;
        for(int j = 0; j < m_linhas; j++)
        {
           elemento = mat[j][i];
           linha.push_back(elemento);
        }
        transp.push_back(linha);
    }
    return transp;
}

/** 6) Multiplicação Matricial: C = A x B **/
vector< vector<float> > Multiplicacao_Matricial(vector< vector<float> > mat1, vector< vector<float> > mat2)
{
    vector< vector<float> > matriz;
    if(mat1[0].size() == mat2.size())
    {
        float elemento;
        for(int i = 0; i < mat1.size(); i++)
        {
            vector<float> linha;
            for(int j = 0; j < mat2[0].size(); j++)
            {
                elemento = produto_interno(mat1[i], Transposta(mat2)[j]);
                linha.push_back(elemento);
            }
        matriz.push_back(linha);
        }
    }
    else
    {
        cout << "Nao e possivel realizar essa operacao. numero de colunas e linhas diferentes" << endl;
    }
    return matriz;
}

/** 8) Permutar duas linhas de posiçao. **/
vector< vector<float> > permuta_linha(vector< vector<float> > mat, int linha1, int linha2)
{
    if (linha1 <= mat.size() || linha2<= mat.size())
    {
        float elemento;
        for(int i = 0; i<=mat.size(); i++)
        {
            elemento = mat[linha1-1][i];
            mat[linha1-1][i] = mat[linha2-1][i];
            mat[linha2-1][i] = elemento;
        }
    }
    else
    {
        cout << "Nao e possivel realizar essa operacao!" << endl;
    }
    return mat;
}

/** 9) Permutar duas colunas de posição. **/
vector< vector<float> > permuta_coluna(vector< vector<float> > mat, int col1, int col2)
{
    return Transposta(permuta_linha(Transposta(mat), col1, col2));
}

/** 10) Somar a uma linha uma outra linha. **/
vector<float> Soma_Linha(vector< vector<float> > mat, int linha1, int linha2)
{
    vector <float> linha_soma;
    float elemento;
    for(int i = 0; i < mat[0].size(); i++)
    {
        elemento = mat[linha1-1][i] + mat[linha2-1][i];
        linha_soma.push_back(elemento);
    }
    return linha_soma;
}

/** 11) somar a uma coluna uma outra coluna. **/
vector<float> Soma_coluna(vector< vector<float> > mat, int linha1, int linha2)
{
   return Soma_Linha(Transposta(mat), linha1, linha2);
}

/** 12) Multiplicar uma única linha, por um escalar. **/
vector<float> MultiplicaLinha(vector< vector<float> > mat, int linha, float lambda)
{
     vector<float> nova_linha;
     float elemento;
     for (int i =0; i<mat[0].size(); i++)
     {
        elemento = mat[linha-1][i]*lambda;
        nova_linha.push_back(elemento);
     }
     mat[linha-1] = nova_linha;
     return nova_linha;
}

/** 13) Multiplicar uma única coluna, por um escalar. **/
vector<float> MultiplicaColuna(vector< vector<float> > mat, int coluna, float lambda)
{
    return MultiplicaLinha(Transposta(mat), coluna, lambda);
}

/** 14) Inversão de matrizes quadradas 2x2. **/
vector< vector<float> > Inversao_Matriz_Quadrada(vector< vector<float> > mat)
{

}

/** 15) Imprimir uma matriz da lista. **/
void Printar_Uma_Matriz(int i)
{
    vector< vector<float> > mat;
    mat = ListaDeMatrizes[i-1];
    cout << " Matriz " << i << endl;
    Print_Matriz(mat);
}

/** 16) Inserir uma nova matriz.**/
void Insere_Matriz(void)
{
    int m, n;
    float elemento;
    cout << "Digite o numero de linhas da matriz: " << endl;
    cin >> m;
    cout << "Digite o numero de colunas da matriz: " << endl;
    cin >> n;
    vector< vector<float> > matriz;
    for(int i = 0; i < m; i++)
    {
        vector<float> linha;
        float elemento;
        for (int j = 0; j < n; j++)
        {
            cout << "Digite o elemento " << i+1 << j+1 << " da matriz" << endl;
            cin >> elemento;
            linha.push_back(elemento);
        }
        matriz.push_back(linha);
    }
    ListaDeMatrizes.push_back(matriz);
}

/** 17) Inserir uma matriz identidade n x n.**/
void Insere_Matriz_Identidade(void)
{
    int m, n;
    float elemento;
    cout << "Digite o numero de linhas da matriz: " << endl;
    cin >> m;
    cout << "Digite o numero de colunas da matriz: " << endl;
    cin >> n;
    vector< vector<float> > matriz;
    for(int i = 0; i< m; i++)
    {
        vector<float> linha;
        float elemento;
        for (int j = 0; j < n; j++)
        {
            if(i == j)
            {
                elemento = 1;
            }
            if(i != j)
            {
                elemento = 0;
            }
            linha.push_back(elemento);
        }
        matriz.push_back(linha);
    }
    ListaDeMatrizes.push_back(matriz);
}

/** 18) Alterar uma matriz da lista.**/
void Altera_Matriz(void)
{
    int i;
    cout << "Digite o numero da matriz que deseja alterar: " << endl;
    cin >> i;
    vector< vector<float> > matriz = ListaDeMatrizes[i-1];
    cout << "Matriz antiga: " << endl;
    Print_Matriz(matriz);
    int m = matriz.size();
    int n = matriz[0].size();
    for (int j = 0; j < m; j++)
    {
        float elemento;
        for(int k = 0; k < n; k++)
        {
            cout << "Digite o elemento " << j+1 << k+1 << " para altera-lo: " << endl;
            cin >> elemento;
            ListaDeMatrizes[i-1][j][k] = elemento;
        }
    }
    cout << "Matriz Atualizada: " << endl;
    Print_Matriz(ListaDeMatrizes[i-1]);
}

/** 19) Remover uma matriz da lista.**/
void Remove_Matriz(void)
{
    int i;
    cout << "Digite o numero da matriz que deseja remover da lista de matrizes: " << endl;
    cin >> i;
    ListaDeMatrizes.erase(ListaDeMatrizes.begin()+i-1);
}

/** 20) Apresentar lista de matrizes.**/
void Print_Lista_Matrizes(vector< vector< vector<float> > > Lista)
{
    int q = Lista.size();
    for(int i = 0; i < q; i++)
    {
        cout << "Matriz " << i+1 << endl;
        Print_Matriz(Lista[i]);
    }
    cout << "A lista de matrizes possui " << q << " matrizes." << endl;
}

/** 21) Gravar lista com um nome diferente. **/
void Gravar_Lista_backup(void)
{
    cout << "Realizando backup ... " << endl;
    ListaDeMatrizes_backup = ListaDeMatrizes;
    cout << " ... " << endl;
    cout << " ... " << endl;
    cout << "Backup realizado com sucesso!" << endl;
}

/** 22) Ler uma outra lista de matrizes, acrescentando a lista existente. **/
void Acrecenta_Novas_Matrizes(void)
{

}

/** 23) zerar lista de matrizes. **/
void Zera_Lista_Matrizes(void)
{
    int q = ListaDeMatrizes.size();
    for (int i = 0; i < q; i++)
    {
        ListaDeMatrizes.pop_back();
    }
}

/** 0) Salva a lista de matrizes no arquivo e sair do programa **/
void Salva_Matriz(vector< vector< vector<float> > > ListaDeMatrizes)
{
    ofstream arq("dados01.txt", std::ios::trunc);
    float elemento;
    for(int k = 0; k < ListaDeMatrizes.size(); k++)
    {
        int m = ListaDeMatrizes[k].size();
        int n = ListaDeMatrizes[k][0].size();
        arq << m << " " << n << "\n";
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                elemento = ListaDeMatrizes[k][i][j];
                arq << elemento << " ";
            }
            arq << "\n";
        }
        arq << "\n";
    }
    arq.close();
}
//**/

int main()
{
    cout << "Estudo Dirigido 2" << endl;

    ifstream arq("dados01.txt");

    while( ! arq.eof())
    {
        LendoMatriz(arq);

    }
    ListaDeMatrizes.pop_back();//Para exluir a matriz excedente
    cout << endl;
    while(1)
    {
        Apresenta_Menu_Principal();
        int opcao;
        cin >> opcao;
        cout << endl;

        if (opcao == 1)
        {
            Menu_De_Operacoes();
            cin >> opcao;
        }

        if (opcao == 2)
        {
            Menu_da_Lista_Matrizes();
            cin >> opcao;
        }

        if (opcao == 3)
        {
            int i, j;
            Print_Lista_Matrizes(ListaDeMatrizes);
            cout << "Selecione as matrizes da lista acima que desejar somar: " << endl;
            cin >> i >> j;
            vector< vector<float> > soma = Soma_matrizes(ListaDeMatrizes[i-1], ListaDeMatrizes[j-1]);
            Print_Matriz(soma);
            int s = 0;
            if(soma.size() > 0)
            {
                cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
                cout << "Se sim, digite 1. Se nao, digite 0" << endl;
                cin >> s;
                if (s ==1)
                {
                    ListaDeMatrizes.push_back(soma);
                }
            }
        }

        if (opcao == 4)
        {
            int i, j;
            Print_Lista_Matrizes(ListaDeMatrizes);
            cout << "Selecione as matrizes da lista acima que desejar subtrair: " << endl;
            cin >> i >> j;
            vector< vector<float> > dif = Subtrai_matrizes(ListaDeMatrizes[i-1], ListaDeMatrizes[j-1]);
            Print_Matriz(dif);
            int s = 0;
            if(dif.size() > 0)
            {
                cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
                cout << "Se sim, digite 1. Se nao, digite 0" << endl;
                cin >> s;
                if (s ==1)
                {
                    ListaDeMatrizes.push_back(dif);
                }
            }
        }

        if (opcao == 5)
        {
            int i;
            float lambda;
            Print_Lista_Matrizes(ListaDeMatrizes);
            cout << "Selecione a matriz da lista que deseja miltiplicsr pelo numero real: " << endl;
            cin >> i;
            cout << "Digite o numero real: " << endl;
            cin >> lambda;
            vector< vector<float> > matriz = Mult_Matriz_escalar(ListaDeMatrizes[i-1], lambda);
            Print_Matriz(matriz);
            int s = 0;
            cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
            cout << "Se sim, digite 1. Se nao, digite 0" << endl;
            cin >> s;
            if (s ==1)
            {
                ListaDeMatrizes.push_back(matriz);
            }
        }

        if (opcao == 6)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int m1, m2;
            cout << "digite os numeros das matrizes que deseja multiplicar: " << endl;
            cin >> m1 >> m2;
            vector< vector<float> > mult_matricial = Multiplicacao_Matricial(ListaDeMatrizes[m1-1], ListaDeMatrizes[m2-1]);
            Print_Matriz(mult_matricial);
            int s = 0;
            cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
            cout << "Se sim, digite 1. Se nao, digite 0" << endl;
            cin >> s;
            if (s ==1)
            {
                ListaDeMatrizes.push_back(mult_matricial);
            }
        }
        if (opcao == 7)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int i;
            cout << "Selecione a matriz da lista que deseja obter a transposta: " << endl;
            cin >> i;
            vector< vector<float> > transp = Transposta(ListaDeMatrizes[i-1]);
            Print_Matriz(transp);
            int s = 0;
            cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
            cout << "Se sim, digite 1. Se nao, digite 0" << endl;
            cin >> s;
            if (s ==1)
            {
                ListaDeMatrizes.push_back(transp);
            }
        }

        if (opcao == 8)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int numerodamatriz, n_linha1, n_linha2;
            cout << "Digite o numero da matriz e os numero das linhas que deseja permutar: " << endl;
            cin >> numerodamatriz >> n_linha1 >> n_linha2;
            vector< vector<float> > matriz = permuta_linha(ListaDeMatrizes[numerodamatriz-1], n_linha1, n_linha2);
            Print_Matriz(matriz);
            int s = 0;
            cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
            cout << "Se sim, digite 1. Se nao, digite 0" << endl;
            cin >> s;
            if (s ==1)
            {
                ListaDeMatrizes.push_back(matriz);
            }
        }

        if (opcao == 9)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int numerodamatriz, n_col1, n_col2;
            cout << "Digite o numero da matriz e os numero das colunas que deseja permutar: " << endl;
            cin >> numerodamatriz >> n_col1 >> n_col2;
            vector< vector<float> > matriz = permuta_coluna(ListaDeMatrizes[numerodamatriz-1], n_col1, n_col2);
            Print_Matriz(matriz);
            int s = 0;
            cout << "Deseja salvar  a matriz na lista de matrizes?" << endl;
            cout << "Se sim, digite 1. Se nao, digite 0" << endl;
            cin >> s;
            if (s ==1)
            {
                ListaDeMatrizes.push_back(matriz);
            }
        }

        if (opcao == 10)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int numerodamatriz, n_linha1, n_linha2;
            cout << "Digite o numero da matriz e os numero das linhas que deseja somar: " << endl;
            cin >> numerodamatriz >> n_linha1 >> n_linha2;
            Print_vetor(Soma_Linha(ListaDeMatrizes[numerodamatriz-1], n_linha1, n_linha2));
        }

        if (opcao == 11)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int numerodamatriz, n_col1, n_col2;
            cout << "Digite o numero da matriz e os numero das colunas que deseja subtrair: " << endl;
            cin >> numerodamatriz >> n_col1 >> n_col2;
            Print_coluna(Soma_coluna(ListaDeMatrizes[numerodamatriz-1], n_col1, n_col2));
        }

        if (opcao == 12)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int n_matriz, n_linha;
            float x;
            cout << "Digite o numero da matriz e o numero da linha que deseja multiplicar: " << endl;
            cin >> n_matriz >> n_linha;
            cout << "Digite o numero real para multiplicar a linha " << n_linha << " da matriz " << n_matriz << endl;
            cin >> x;
            vector<float> v = MultiplicaLinha(ListaDeMatrizes[n_matriz-1], n_linha, x);
            Print_vetor(v);
        }

        if (opcao == 13)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
            int n_matriz, n_coluna;
            float x;
            cout << "Digite o numero da matriz e o numero da coluna que deseja multiplicar: " << endl;
            cin >> n_matriz >> n_coluna;
            cout << "Digite o numero real para multiplicar a coluna " << n_coluna << " da matriz " << n_matriz << endl;
            cin >> x;
            vector<float> v = MultiplicaColuna(ListaDeMatrizes[n_matriz-1], n_coluna, x);
            Print_coluna(v);
        }

        if (opcao == 15)
        {
            int i;
            cout << "Digite o numero da matriz que deseja imprimir:" << endl;
            cin >> i;
            Printar_Uma_Matriz(i);
        }

        if (opcao == 16)
        {
            Insere_Matriz();
        }

        if (opcao == 17)
        {
            Insere_Matriz_Identidade();
        }

        if (opcao == 18)
        {
            Altera_Matriz();
        }

        if (opcao == 19)
        {
            Remove_Matriz();
        }

        if (opcao == 20)
        {
            Print_Lista_Matrizes(ListaDeMatrizes);
        }

        if (opcao == 21)
        {
            Gravar_Lista_backup();
        }

        if (opcao == 22)
        {
            Acrecenta_Novas_Matrizes();
        }

        if (opcao == 23)
        {
            Zera_Lista_Matrizes();
        }

        if (opcao!=0 && opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5 && opcao!=6 && opcao!=7 && opcao!=8 && opcao!=9 && opcao!=10 && opcao!=11 && opcao!=12 && opcao!=13 && opcao!=14 && opcao!=15 && opcao!=16 && opcao!=17 && opcao!=18 && opcao!=19 && opcao!=20 && opcao!=21 && opcao!=22 && opcao!=23)
        {
            cout << "Opcao Invalida.\n" << endl;
        }

        if (opcao == 0)
        {
            Salva_Matriz(ListaDeMatrizes);
            break;
        }
    }
    return 0;
}
