#include <iostream>

using namespace std;

typedef unsigned char Pixel;

class Imagem
{
private:
  unsigned NLin, NCol;
  Pixel **x;
  void criar(unsigned numL, unsigned numC);
  void copiar(const Imagem &N);
  void limpar();
public:
  inline Imagem(): NLin(0), NCol(0), x(NULL) {}  // Default
  inline Imagem(unsigned numL, unsigned numC) {criar(numL, numC);}  // Espec�fico
  inline Imagem(const Imagem &N) {copiar(N);}  // Copia
  inline ~Imagem() {limpar();}
  inline void operator=(const Imagem &N) {if (this!=&N) {limpar(); copiar(N);}}

  Pixel getPixel(unsigned i, unsigned j) const;
  void setPixel(unsigned i, unsigned j, Pixel Cor);

  void paintRectangle(unsigned imin, unsigned jmin,
                      unsigned imax, unsigned jmax, Pixel Cor);
};

void Imagem::criar(unsigned numL, unsigned numC)
{
  // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
  // Por exemplo, em um construtor.
  // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
  if (numL==0 || numC==0)
  {
    NLin = NCol = 0;
    x = NULL;
    return;
  }
  NLin = numL;
  NCol = numC;
  x = new Pixel*[NLin];
  for (unsigned i=0; i<NLin; i++) x[i] = new Pixel[NCol];
}

void Imagem::copiar(const Imagem &N)
{
  // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
  // Por exemplo, em um construtor.
  // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
  criar(N.NLin, N.NCol);
  for (unsigned i=0; i<NLin; i++)
  {
    for (unsigned j=0; j<NCol; j++) x[i][j] = N.x[i][j];
  }
}

void Imagem::limpar()
{
  if (x!=NULL)
  {
    for (unsigned i=0; i<NLin; i++) delete[] x[i];
    delete[] x;
  }
  NLin = NCol = 0;
  x = NULL;
}

Pixel Imagem::getPixel(unsigned i, unsigned j) const
{
  if (i>=NLin || j>=NCol)
  {
    cerr << "Indices incompativeis\n";
    return 0;
  }
  return x[i][j];
}

void Imagem::setPixel(unsigned i, unsigned j, Pixel Cor)
{
  if (i>=NLin || j>=NCol)
  {
    cerr << "Indices incompativeis\n";
    return;
  }
  x[i][j] = Cor;
}

void Imagem::paintRectangle(unsigned imin, unsigned jmin,
                            unsigned imax, unsigned jmax, Pixel Cor)
{
  if (imin>=imax || jmin>=jmax || imax>=NLin || jmax>=NCol)
  {
    cerr << "Indices incompativeis\n";
    return;
  }
  for (unsigned i=imin; i<=imax; i++) for (unsigned j=jmin; j<=jmax; j++)
  {
    x[i][j] = Cor;
  }
}

int main(void)
{
  Imagem I(240,320);

  // Desenha o fundo cinza
  I.paintRectangle(0,0,239,319, 127);
  // Desenha o retangulo preto
  I.paintRectangle(20,20,170,170, 0);
  // Desenha o retangulo branco
  I.paintRectangle(70,150,220,300, 255);

  cout << "imagem gerada\n";
}

