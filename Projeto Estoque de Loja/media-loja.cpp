#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

/// Programa que calcula o preco medio
/// dos produtos de uma loja,
/// lidos de um arquivo no formato especificado

int main()
{
    double soma_precos(0.0);
    double preco;
    unsigned N_total(0);
    unsigned N;
    string cabecalho;
    char C;

    ifstream S("loja.loj");
    if (!S.is_open())
    {
        cerr << "Erro na abertura da stream\n";
        exit(1);
    }

    for (unsigned j=0; j<3; j++)
    {
        S >> cabecalho;
        if (cabecalho!="LISTALIVRO" &&
            cabecalho!="LISTACD" &&
            cabecalho!="LISTADVD")
        {
            cerr << "Arquivo corrompido\n";
            S.close();
            exit(1);
        }
        //S.ignore(numeric_limits<streamsize>::max(), ' ');
        S >> N;
        N_total += N;
        for (unsigned i=0; i<N; i++)
        {
            S >> C;
            cout << C << endl;
            if (C!='L' && C!='C' && C!='D')
            {
                cerr << "Arquivo corrompido\n";
                S.close();
                exit(1);
            }
            S.ignore(numeric_limits<streamsize>::max(), '$');
            S >> preco;
            soma_precos += preco;
            S.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    S.close();
    cout << "Preco medio = " << soma_precos/N_total << endl;
}
