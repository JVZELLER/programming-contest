/*
	author: Ot�vio Augusto - OAMP
	problem_name: Abracadabra
	problem_number: 2484
	category: Strings
	difficulty_level: 5
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2484
*/

#include <iostream>  // entrada e sa�da padr�o
#include <string>  // uso de strings

using namespace std;

int main() {
  int i, j, k, aux;  // iteradores e vari�vel aux
  string str, vStr, esp;  // str p/ captura, vStr p/ string, esp p/ char ' '

  while (cin >> str) {  // captura string at� ao EOF
    aux = str.size();  // atribui o tamanho do str p/ var. aux
    for (k = 0; k < aux; ++k) {  // loop at� o tamanho da str
      vStr = string(200, ' ');  // nova string com tam. 200 e char ' '
      esp = string(k, ' ');  // nova string com tam. k e char ' '
      for (i = 0, j = 0; j < str.size() - k; ++j, i += 2)  // loop p/ str - k
        vStr[i] = str[j];  // atribui ao char na pos str[j]
        
      vStr[i - 1] = '\n';  // atribui '\n'
      vStr[i] = '\0';  // atribui '\0'
      cout << esp << vStr.c_str();  // imprime linha atualizada
    }  // fim for k
    cout << "\n";  // imprime new line
  }  // fim enquanto
  return 0;  // fim do programa
}