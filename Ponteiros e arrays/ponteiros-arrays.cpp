#include <iostream>

/*
Neste programa, sao realizadas operacoes com ponteiros e arrays
Demonstra-se que a aritmetica de ponteiros e a desreferenciacao podem ser usadas com arrays
Da mesma forma, o operador de indice, ou seja, o [], pode ser usado com ponteiros
*/

using namespace std;

int main(void)
{
  float ar[10];
  float *pt;

  /// Faz o ponteiro apontar para o array
  pt = ar;

  /// Atribui usando a notacao de indices com o array
  for (int i=0; i<10; i++) ar[i] =  1.0/(i+1);
  /// Imprime usando a notacao de desreferenciacao com o ponteiro
  for (int i=0; i<10; i++) cout << *(pt+i) << ' ';
  cout << endl;

  /// Atribui usando a notacao de desreferenciacao com o array
  for (int i=0; i<10; i++) *(ar+i) =  2.0/(i+1);
  /// Imprime usando a notacao de indices com o ponteiro
  for (int i=0; i<10; i++) cout << pt[i] << ' ';
  cout << endl;

  /// Atribui usando a notacao de indices com o ponteiro
  for (int i=0; i<10; i++) pt[i] =  3.0/(i+1);
  /// Imprime usando a notacao de indices com o array
  for (int i=0; i<10; i++) cout << ar[i] << ' ';
  cout << endl;

  /// Atribui usando a notacao de desreferenciacao com o ponteiro
  for (int i=0; i<10; i++) *(pt+i) =  4.0/(i+1);
  /// Imprime usando a notacao de desreferenciacao com o array
  for (int i=0; i<10; i++) cout << *(ar+i) << ' ';
  cout << endl;

  return 0;
}
