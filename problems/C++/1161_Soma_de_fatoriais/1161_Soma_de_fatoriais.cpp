/*
	author: Ot�vio Augusto - OAMP
	problem_name: Soma de Fatoriais
	problem_number: 1161
	category: Matem�tica
	difficulty_level: 6
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1161
*/

#include <iostream>  // entrada e sa�da padr�o

using namespace std;
using ull = unsigned long long;  // novo nome p/ unsigned long long

// fun��o recusiva de cauda, valor passado p/ refer�ncia
inline void fact(ull& val, int mult) { 
    if (val < 2) val = 1;  // menor que 2? retorna 1
    if (mult > 1) fact(val *= mult, mult - 1);  // chama func. com novos valores
}  // fim da fun��o

int main() {
    ull m, n;  // vari�veis p/ c�lculo
    
    while (cin >> m >> n) {  // entrada at� EOF
        fact(m, m - 1);  // chamada da fun��o
        fact(n, n - 1);  // chamada da fun��o
        cout << m + n << endl;  // cout da soma
    }  // fim enquanto
    return 0;  // fim do programa
}