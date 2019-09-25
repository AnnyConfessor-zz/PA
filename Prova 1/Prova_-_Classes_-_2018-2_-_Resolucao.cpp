#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

class Poly
{
private:
  unsigned n; // n = grau
  double *a;  // a[i] = coeficiente de x^i

  void alocar (unsigned Grau);
  void desalocar();
public:
  explicit Poly(unsigned Grau=0);
  Poly(const Poly &P);
  inline ~Poly() {desalocar();}
  Poly operator=(const Poly &P);

  friend istream& operator>>(istream &I, Poly &P);
  friend ostream& operator<<(ostream &O, const Poly &P);

  inline int grau() const {return n;}
  double operator()(double x) const;
  const Poly operator+(const Poly &P) const;
  const Poly operator*(const Poly &P) const;
};

void Poly::alocar(unsigned Grau)
{
  n = Grau;
  a = new double[n+1];
}

void Poly::desalocar()
{
  if (a != NULL) delete[] a;
}

Poly::Poly(unsigned Grau)
{
  alocar(Grau);
  if (n==0)
  {
    a[0] = 0.0;
  }
  else for (unsigned i=0; i<=n; i++)
  {
    a[i] = (i==n ? 1.0 : 0.0);
  }
}

Poly::Poly(const Poly &P)
{
  alocar(P.n);
  for (unsigned i=0; i<=n; i++) a[i] = P.a[i];
}

Poly Poly::operator=(const Poly &P)
{
  if (this != &P)
  {
    if (n != P.n)
    {
      desalocar();
      alocar(P.n);
    }
    for (unsigned i=0; i<=n; i++) a[i] = P.a[i];
  }
  return *this;
}

istream& operator>>(istream &I, Poly &P)
{
  unsigned N;
  cout << "Grau: ";
  I >> N;
  if (N!=P.n)
  {
    P.desalocar();
    P.alocar(N);
  }
  for (unsigned i=0; i<=P.n; i++)
  {
    do
    {
      cout << "x^" << i << ": ";
      I >> P.a[i];
    } while (i==P.n && P.a[i]==0.0);
  }
  return I;
}

ostream& operator<<(ostream &O, const Poly &P)
{
  for (unsigned i=0; i<=P.n; i++)
  {
    // Soh imprime o termo se o coeficiente nao for nulo
    // Exceto no caso de polinomio de grau zero
    if (P.a[i]!=0.0 || (i==0 && P.n==0))
    {
      if (i>0) O << ' ';
      O << (P.a[i]<0.0 ? '-' : '+');
      O << fabs(P.a[i]);
      if (i>=1) O << "*x";
      if (i>=2) O << '^' << i;
    }
  }
  return O;
}

double Poly::operator()(double x) const
{
  double powx = 1.0, result = 0.0;
  for (unsigned i=0; i<=n; i++)
  {
    result += a[i]*powx;
    powx *= x;
  }
  return result;
}

const Poly Poly::operator+(const Poly &P) const
{
  Poly prov(max(n,P.n));
  for (unsigned i=0; i<=prov.n; i++)
  {
    prov.a[i] = (i<=n ? a[i] : 0.0) + (i<=P.n ? P.a[i] : 0.0);
  }
  // Reduz o grau caso o ultimo coeficiente sejh nulo
  while (prov.a[prov.n]==0.0 && prov.n>0)
  {
    prov.n--;
  }
  return prov;
}

const Poly Poly::operator*(const Poly &P) const
{
  Poly prov(n+P.n);
  for (unsigned i=0; i<=prov.n; i++) prov.a[i] = 0.0;
  for (unsigned i=0; i<=n; i++)
  {
    for (unsigned j=0; j<=P.n; j++)
    {
      prov.a[i+j] += a[i]*P.a[j];
    }
  }
  return prov;
}

int main(void)
{
  Poly Q1, Q2, S, P;

  cout << "Primeiro polinomio: ";
  cin >> Q1;
  cout << "Segundo polinomio: ";
  cin >> Q2;

  S = Q1+Q2;
  P = Q1*Q2;

  cout << "Q1 = " << Q1 << endl;
  cout << "Q2 = " << Q2 << endl;
  cout << "Soma = " << S << '\t' << "S(-3.0)=" << S(-3.0) << endl;
  cout << "Produto = " << P << '\t' << "P(1.0)=" << P(1.0) << endl;
}

