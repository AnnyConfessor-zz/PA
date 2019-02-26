/*Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e
dois números reais. O programa deve retornar o resultado da operação recebida
sobre estes dois números. Este funcionamento deve ser repetido até que o símbolo
seja algo que não corresponda a nenhuma das quatro operações reconhecidas. 
*/

/*ajeitar / terminar / refazer esse exercício*/
#include <iostream>
using namespace std;
int main(){
    char a;
    float b;
    float c;
    
    cout << "Número real: ";
    cin >> b;

    cout << "Número real";
    cin >> c;

    cout << "Operação entre os números ('+','-','/'.'*'): ";
    cin >> a;    
    } 
}

int operacao(char a,float b,float c){
    int result;

    if(a=='+'){
        result = b + c;
    } else if(a=='-'){
        result = b - c;
    } else if(a=='/'){
        result = b / c;
    } else if(a=='*'){
        result = b * c;
    } else if(a!='+' || a!='-' || a!='/' || a!='*'){
        break;
    }

    return result;
}

