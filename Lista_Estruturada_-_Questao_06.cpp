#include <iostream>
#include <string>

using namespace std;

string valorPorExtenso(unsigned int valor);

int main()
{
  unsigned int valor;
  string E;

  do {
    cout << "Digite o valor total em R$ (>0): ";
    cin >> valor;
  } while (valor==0);

  if (valor==1 || valor==3)
  {
      cerr << "Nao existem cedulas que permitam obter o valor de R$ " << valor << endl;
      return 0;
  }
  unsigned int N100, N50, N20, N10, N5, N2;
  string extenso;

  N100 = valor/100;
  valor = valor%100;

  N50 = valor/50;
  valor = valor%50;

  N20 = valor/20;
  valor = valor%20;

  N10 = valor/10;
  valor = valor%10;

  N5 = valor/5;
  valor = valor%5;

  N2 = valor/2;
  valor = valor%2;

  cout << "Cedulas de R$ 100: " << N100 << endl;
  cout << "Cedulas de R$ 50: " << N50 << endl;
  cout << "Cedulas de R$ 20: " << N20 << endl;
  cout << "Cedulas de R$ 10: " << N10 << endl;
  cout << "Cedulas de R$ 5: " << N5 << endl;
  cout << "Cedulas de R$ 2: " << N2 << endl;
  cout << "TOTAL: " << 100*N100 + 50*N50 + 20*N20 + 10*N10 + 5*N5 + 2*N2 << endl;

  if (valor!=0)
  {
      cerr << "Houve um problema com esse algoritmo!\n";
      cerr << "Veja que fica faltando R$ " << valor << " para completar o valor total!!\n";
      cerr << "Voce pode tentar encontrar e corrigir o erro?\n";
  }

}
