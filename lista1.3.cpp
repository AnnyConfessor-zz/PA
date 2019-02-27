/*Fazer um programa que sorteie um número de 0 a 100 e que permita que o usuário
(sem conhecer o número sorteado) tente acertar. Caso não acerte, o programa deve 
imprimir uma mensagem informando se o número sorteado é maior ou menor
que a tentativa feita. Ao acertar o número, o programa deve imprimir a quantidade
de tentativas feitas. */

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "N:";
    cin >> n;
    switch (int n)
    {
        case n>numerosorteado:
            cout << "N é maior que o número sorteado";
            contanumero();
        case n<numerosorteado: 
            cout << "N é menor que o número sorteado";
            contanumero();
            break;
        case n==numerosorteado:
            cout << contanumero; /*como chamar só o retorno da função? acho que é assim */
    }
}
    
contanumero(){
    int cont;
    cont = 1;
    cout << "Entre com um novo número";
    cont++; 
    return cont;
}

sorteianumero(int n){
    int numerosorteado;
    numerosorteado = rand();
    return numerosorteado;
}
