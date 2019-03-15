/*
	author: Bruno Holanda
	problem_name: Familia de Troia
	problem_number: 2440
	category: Grafos
	difficulty_level: 5
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2440
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

	int troiano,
		relacao,
		i, j;

	cin >> troiano >> relacao;

	vector<int> *adjacencia = new vector<int>[troiano];
	int *componentes = new int[troiano];

	for (i = 0; i < troiano; i++)
	{
		componentes[i] = 0;
	}

	int	pontoA,
		pontoB;
	
	for (i = 0; i < relacao; i++)
	{
		cin >> pontoA >> pontoB;
		adjacencia[pontoA - 1].push_back(pontoB - 1);
		adjacencia[pontoB - 1].push_back(pontoA - 1);
	}

	stack<int> pilha;
	int membro;
	int	familias = 0;
	for (i = 0; i < troiano; i++){
		if (componentes[i] == 0){
			pilha.push(i);
			familias++;
			while (!pilha.empty()){
				membro = pilha.top();
				pilha.pop();
				for (int j = 0; j < adjacencia[membro].size(); j++){
					if (componentes[adjacencia[membro][j]] == 0){
						componentes[adjacencia[membro][j]] = 1;
						pilha.push(adjacencia[membro][j]);
					}				
				}
			}
		}
	}
	cout << familias << endl;
	system("pause");
	return 0;
}