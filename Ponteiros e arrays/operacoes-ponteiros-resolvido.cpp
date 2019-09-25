#include <iostream>

/*
Neste programa, sao apresentadas algumas operacoes basicas envolvendo ponteiros.
Existem erros em 8 linhas do programa. Tente encontra-los antes de compilar.
Alem disso, apos eliminar os erros, tente prever o que serah impresso antes de executar.
*/

using namespace std;

int main(void)
{
  int vi;
  float vf;

  int *pi;
  void *pv;

  /// Atribuicao de valores
  vi = 666;
  vf = 3.1416;

  //pi = pv;  // ptr para int nao pode receber um valor void*
  pv = pi;
  //pi = &vf;  // ptr para int nao pode receber um valor float*
  pv = &vf;

  //&vi = pi;  // o endereco de uma variavel eh constante, nao pode ser atribuido ou modificado

  //*pv = 777;  // ptr para void nao apontam para nada especifico, nao podem ser desreferenciados
  //*pi = 888;  // sintaxe correta, erro logico; pi contem lixo, nao pode ser desreferenciado

  pi = &vi;
  *pi = 999;

  vf = 2**pi;

  /// Impressao dos atributos

  cout << "=================\n";
  cout << pi << endl;
  cout << &pi << endl;
  cout << sizeof(pi) << endl;
  cout << *pi << endl;
  cout << "=================\n";

  cout << "=================\n";
  cout << pv << endl;
  cout << &pv << endl;
  cout << sizeof(pv) << endl;
  //cout << *pv << endl;  // ptr para void nao apontam para nada especifico, nao podem ser desreferenciados
  cout << "=================\n";

  cout << "=================\n";
  cout << vi << endl;
  cout << &vi << endl;
  cout << sizeof(vi) << endl;
  //cout << *vi << endl;  // soh ponteiros podem ser desreferenciados
  cout << "=================\n";

  cout << "=================\n";
  cout << vf << endl;
  cout << &vf << endl;
  cout << sizeof(vf) << endl;
  //cout << *vf << endl;    // soh ponteiros podem ser desreferenciados
  cout << "=================\n";

  return 0;
}
