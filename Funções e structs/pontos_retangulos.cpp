#include <iostream>
#include <cmath>

using namespace std;

/// Funcao auxiliar

inline double pow2(double x) {return x*x;}

/// Definicao dos tipos

struct Ponto
{
    double x;
    double y;
};

struct Retangulo
{
    Ponto vInf;
    Ponto vSup;
};

/// Declaracao das funcoes

void imprimirPonto(const Ponto& P);

double distPontos(const Ponto& P1, const Ponto& P2);

bool pontosIguais(const Ponto& P1, const Ponto& P2);

double areaRet(const Retangulo& R);

bool pontoDentroRet(const Ponto& P, const Retangulo& R);

bool retDentroRet(const Retangulo& R1, const Retangulo& R2);

/// Definicao (implementacao) das funcoes

void imprimirPonto(const Ponto& P)
{
    cout << '(' << P.x << ',' << P.y << ')';
}

double distPontos(const Ponto& P1, const Ponto& P2)
{
    return sqrt(pow2(P2.x-P1.x)+pow2(P2.y-P1.y));
}

bool pontosIguais(const Ponto& P1, const Ponto& P2)
{
    //return P1.x==P2.x && P1.y==P2.y;

    return (distPontos(P1,P2) <= 0.00001);
}

double areaRet(const Retangulo& R)
{
    double deltaX = R.vSup.x - R.vInf.x;
    double deltaY = R.vSup.y - R.vInf.y;
    return deltaX*deltaY;
}

bool pontoDentroRet(const Ponto& P, const Retangulo& R)
{
    /*
    if (P.x < R.vInf.x) return false;
    if (P.x > R.vSup.x) return false;
    if (P.y < R.vInf.y) return false;
    if (P.y > R.vSup.y) return false;
    return true;
    */
    return ( (P.x < R.vInf.x) &&
             (P.x > R.vSup.x) &&
             (P.y < R.vInf.y) &&
             (P.y > R.vSup.y) );
}

bool retDentroRet(const Retangulo& R1, const Retangulo& R2)
{
    return ( pontoDentroRet(R1.vInf, R2) &&
             pontoDentroRet(R1.vSup, R2));
}
