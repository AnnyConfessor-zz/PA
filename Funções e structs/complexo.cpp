#include <iostream>
#include <cmath>

using namespace std;

// Tipo Complexo
struct Complexo
{
    double real, imag;
};

// As funcoes
void ler(Complexo &C)
{
    cout << "R? ";
    cin >> C.real;
    cout << "I? ";
    cin >> C.imag;
}

void imprimir(Complexo C)
{
    cout << C.real << (C.imag<0.0 ? '-' : '+') << 'j' << abs(C.imag);
}

Complexo soma(Complexo C1, Complexo C2)
{
    Complexo prov;
    prov.real = C1.real+C2.real;
    prov.imag = C1.imag+C2.imag;
    return prov;
}

Complexo produto(Complexo C1, Complexo C2)
{
    Complexo prov;
    prov.real = C1.real*C2.real - C1.imag*C2.imag;
    prov.imag = C1.real*C2.imag + C2.real*C1.imag;
    return prov;
}

// O programa principal

int main(void)
{
  Complexo C1, C2, S, P;

  cout << "Digite o primeiro numero complexo (C1):\n";
  ler(C1);

  cout << "Digite o segundo numero complexo (C2):\n";
  ler(C2);

  S = soma(C1,C2);
  P = produto(C1,C2);

  cout << "Soma = ";
  imprimir(S);
  cout << endl;

  cout << "Produto = ";
  imprimir(P);
  cout << endl;
}

