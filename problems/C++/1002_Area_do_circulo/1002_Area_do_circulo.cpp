/*
	author: Ot�vio Augusto - OAMP
	problem_name: �rea do c�rculo
	problem_number: 1002
	category: Iniciante
	difficulty_level: 5
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1002
*/

#include <iostream>  // entrada e sa�da padr�o
#include <iomanip>  // usado p/ fixed, setprecision
#define PI  3.14159  // valor de PI
using namespace std;
 
int main() {
    double raio = 0.0;  // raio do C�rculo
    
    cin >> raio;  // entrada de valor p/ raio
    // senten�a abaixo imprime valor da �rea calculado do c�rculo
    cout << "A=" << fixed << setprecision(4) << PI * raio * raio << endl;   
    return 0;  // fim do programa
}