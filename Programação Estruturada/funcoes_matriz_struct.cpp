#include <iostream>

using namespace std;

/*
Exercício de utilização de funções em conjunto com arrays alocados dinamicamente (ponteiros)

Nesse exercicio, voce deve definir o novo tipo Matriz utilizando uma struct, que armazena
tanto o numero de linhas e de colunas de cada matriz quanto o ponteiro

A partir desse tipo Matriz, voce deve programar as funcoes necessarias para executar o programa
principal a seguir. A ideia eh permitir fazer as operacoes indicadas com matrizes de quaisquer
dimensoes, fornecidas pelo usuario no momento da execucao (e nao na compilacao).

*/

struct Matriz
{
  unsigned NL, NC;
  double **x;
};

// Alocacao e liberacao de memoria
Matriz novaMatriz(unsigned NumLin, unsigned NumCol);
void liberaMatriz(Matriz &M);

// Entrada e saida de dados (via teclado e tela)
void leMatriz(Matriz &M);
void imprimeMatriz(Matriz &M);

// Operacoes com matrizes
Matriz produtoMatrizes(const Matriz &M1, const Matriz &M2);

int main(void)
{
  // Declaracao das matrizes
  Matriz A, B, C;

  unsigned NLa, NCa, NLb, NCb;
  do {
    cout << "Linhas de A: ";
    cin >> NLa;
  } while (NLa <= 0);
  do {
    cout << "Colunas de A: ";
    cin >> NCa;
  } while (NCa <= 0);
  // Obs: NLb = NCa
  NLb = NCa;
  do {
    cout << "Colunas de B: ";
    cin >> NCb;
  } while (NCb <= 0);

  // Alocacao das matrizes
  A = novaMatriz(NLa,NCa);
  B = novaMatriz(NLb,NCb);

  // Leitura das matrizes A e B
  cout << "Matriz A:\n";
  leMatriz(A);
  cout << "Matriz B:\n";
  leMatriz(B);

  // produto das matrizes
  C = produtoMatrizes(A,B);

  // Impressao das matrizes
  cout << "Produto AxB:\n";
  imprimeMatriz(C);

  // Liberacao das memorias
  liberaMatriz(A);
  liberaMatriz(B);
  liberaMatriz(C);

  return  0;
}

Matriz novaMatriz(unsigned NumLin, unsigned NumCol)
{
  Matriz prov;

  if (NumLin==0 || NumCol==0)
  {
    cerr << "Matriz de dimensao nula!\n";
    prov.NL = prov.NC = 0;
    prov.x = NULL;
    return prov;
  }
  prov.NL = NumLin;
  prov.NC = NumCol;
  prov.x = new double*[NumLin];
  for (unsigned i=0; i<NumLin; i++)
  {
    prov.x[i] = new double[NumCol];
    for (unsigned j=0; j<NumCol; j++) prov.x[i][j] = 0.0;
  }
  return prov;
}

void liberaMatriz(Matriz &M)
{
  if (M.x != NULL)
  {
    for (unsigned i=0; i<M.NL; i++) delete[] M.x[i];
    delete[] M.x;
  }
  // Para garantir que o conteudo da matriz reflita o fato de que ela nao tem mais dados
  // Evita uma utilizacao futura dessa matriz
  M.NL = M.NC = 0;
  M.x = NULL;
}

void leMatriz(Matriz &M)
{
  if (M.NL==0 || M.NC==0 || M.x==NULL)
  {
    cerr << "Matriz nao tem espaco para dados. Nao pode ser lida.\n";
    return;
  }
  for (unsigned i=0; i<M.NL; i++)
  {
    for (unsigned j=0; j<M.NC; j++)
    {
      cout << '[' << i << ',' << j << "]: ";
      cin >> M.x[i][j];
    }
  }
}

void imprimeMatriz(Matriz &M)
{
  if (M.NL==0 || M.NC==0 || M.x==NULL)
  {
    cerr << "Matriz nao tem espaco para dados. Nao pode ser impressa.\n";
    return;
  }
  for (unsigned i=0; i<M.NL; i++)
  {
    for (unsigned j=0; j<M.NC; j++) cout << M.x[i][j] << ' ';
    cout << endl;
  }
}

Matriz produtoMatrizes(const Matriz &M1, const Matriz &M2)
{
  Matriz prov;
  if (M1.NL==0 || M1.NC==0 || M2.NL!=M1.NC || M2.NC==0)
  {
    cerr << "Matrizes de dimensoes invalidas. Nao podem ser multiplicadas.\n";
    prov.NL = prov.NC = 0;
    prov.x = NULL;
    return prov;
  }
  prov = novaMatriz(M1.NL,M2.NC);
  for (unsigned i=0; i<prov.NL; i++)
  {
    for (unsigned j=0; j<prov.NC; j++)
    {
      prov.x[i][j] = 0.0;
      for (unsigned k=0; k<M1.NC; k++)
      {
        prov.x[i][j] += M1.x[i][k]*M2.x[k][j];
      }
    }
  }
  return prov;
}

