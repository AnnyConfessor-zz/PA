#include <iostream>

using namespace std;

void ordenar(double &n1, double &n2, double &n3);

double le_valor();

int main()
{
   double A, B, C;
   
   A = le_valor();
   B = le_valor();
   C = le_valor();
   
   // Colocar algo aqui para ordenar...
   ordenar(A,B,C);
  
   cout << "A = " << A << "\tB = " << B << "\tC = " << C << endl;
   
   char tecla;
   cin >> tecla;
}

double le_valor()
{
  double prov;
  cout << "Digite o valor: ";
  cin >> prov;
  return prov;
}

void ordenar(double &n1, double &n2, double &n3)
{
  double prov;
  if (n1>n2) {
     prov = n1;
     n1 = n2;
     n2 = prov;
  }
  if (n2>n3) {
     prov = n2;
     n2 = n3;
     n3 = prov;
  }
  if (n1>n2) {
     prov = n1;
     n1 = n2;
     n2 = prov;
  }
}
