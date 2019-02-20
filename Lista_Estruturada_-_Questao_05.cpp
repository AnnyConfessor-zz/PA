#include <iostream>

using namespace std;

bool bissexto(unsigned Y)
{
  return ( Y%400 == 0 || (Y%4==0 && Y%100!=0) );
}

unsigned numeroDeDias(unsigned D, unsigned M, unsigned A)
{
  unsigned num = 0;
  
  for (unsigned i=1; i<=M-1; i++) {
    switch(i) {
    case 2:
      num += 28;
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      num += 31;
      break;
    default:
      num += 30;
      break;
    }
  }
  num += D;
  if (bissexto(A) && M>=3) num++;
  return num;
}

int main()
{
  cout << "Programa para calcular o numero de dias de uma data\n";
  
  unsigned dia, mes, ano;
  unsigned ndias;
  
  cout << "Digite o ano: ";
  cin >> ano;
  
  cout << "Digite o mes: ";
  cin >> mes;
  
  cout << "Digite o dia: ";
  cin >> dia;

  ndias = numeroDeDias(dia,mes,ano);
  
  cout << "Numero de dias = " <<  ndias << endl;

  char tecla;
  cin >> tecla;
}
