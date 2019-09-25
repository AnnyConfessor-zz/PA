/*
O objetivo eh fazer um programa que solicite ao usuario que
digite uma sequencia de numeros reais nao nulos. Quando o
usuario digitar zero, entende-se que ele concluiu a entrada
dos dados.
Apos a entrada dos dados, o programa deve calcular e imprimir
as seguintes informacoes:
1) A media aritmetica dos numeros digitados (sem incluir o
zero final).
2) Quantos dos numeros estao acima e abaixo da media (sem
contar com o zero final.
*/

#include <iostream>

using namespace std;

int main()
{
  float *arr = NULL;  // Array dinamico de floats; inicialmente aponta para nada
  unsigned N=0;       // Dimensao do array; inicialmente igual a zero
  float Num;          // O numero digitado
  unsigned int i;     // Um contador

  do
  {
    cout << "Digite um numero [0.0 para parar]: ";
    cin >> Num;
    if (Num != 0.0)
    {
      // Aloca uma nova area de memoria para N+1 floats
      float *prov = new float[N+1];
      // Copia todos os elementos do array atual para a nova area
      for (i=0; i<N; i++) prov[i] = arr[i];
      // Armazena o valor digitado na ultima posicao da nova area
      prov[N] = Num;
      // Libera a area de memoria antiga
      if (arr != NULL) delete[] arr;
      // Faz o array apontar para a nova area
      arr = prov;
      // Incrementa a dimensao do array
      N++;
    }
  } while (Num != 0.0);

  if (N==0)
  {
    cout << "Voce nao digitou nenhum numero!!!\n";
    return 0;
  }

  float soma = 0.0, media;
  unsigned num_acima=0, num_abaixo=0;

  for (i=0; i<N; i++) soma += arr[i];
  media = soma/N;
  for (i=0; i<N; i++)
  {
    if (arr[i] > media) num_acima++;
    if (arr[i] < media) num_abaixo++;
  }

  cout << "Os numeros digitados:";
  for (i=0; i<N; i++) cout << ' ' << arr[i];
  cout << endl;
  cout << "A media eh: " << media << endl;
  cout << "Acima da media: " << num_acima << endl;
  cout << "Abaixo da media: " << num_abaixo << endl;

  // Libera a area de memoria
  if (arr != NULL) delete[] arr;

  return 0;
}
