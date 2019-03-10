/*
	author: zeller
	problem_name: Colorindo
	problem_number: 2405
	category: Ad-Hoc
	difficulty_level: 2
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2405
*/

#include <stdio.h>
#include <utility>
#include <stack>
#include <iostream>

#define VAZIO false
#define CHEIO true
using namespace std;

typedef pair<int, int> P;
int main()
{
	int linha, coluna, linhaEntrada, colunaEntrada, quantidadeCheios, linhaCheio, colunaCheio, contador = 0, i, j;
    cin >> linha >> coluna >> linhaEntrada >> colunaEntrada >> quantidadeCheios;
	bool figura[linha][coluna];
	bool auxPilha[linha][coluna];
	P pixels;
	stack <P> pilha;
	for(i = 0; i < linha; i++)
	{
		for(j = 0; j < coluna; j++)
		{
			figura[i][j] = VAZIO;
			auxPilha[i][j] = VAZIO;
		}
	}
	for(i = 0; i < quantidadeCheios; i++)
	{
		cin >> linhaCheio >> colunaCheio;
		figura[linha - linhaCheio][colunaCheio - 1] = CHEIO;
	}
	pilha.push({linha - linhaEntrada, colunaEntrada - 1});
	auxPilha[linha - linhaEntrada][colunaEntrada - 1] = CHEIO;
	while(!pilha.empty())
	{
		pixels = pilha.top();
		pilha.pop();
		contador++;
		// Cima
		if((pixels.first - 1 >= 0) && (!figura[pixels.first - 1][pixels.second]) &&
		!auxPilha[pixels.first - 1][pixels.second])
		{
			pilha.push({pixels.first - 1, pixels.second});
			auxPilha[pixels.first - 1][pixels.second] = CHEIO;
		}
		// Cima - esquerda
		if((pixels.first - 1 >= 0 && pixels.second - 1 >= 0) && (!figura[pixels.first - 1][pixels.second - 1]) &&
		!auxPilha[pixels.first - 1][pixels.second - 1])
		{
			pilha.push({pixels.first - 1, pixels.second - 1});
			auxPilha[pixels.first - 1][pixels.second - 1] = CHEIO;
		}
		// Cima - direita
		if((pixels.first - 1 >= 0 && pixels.second + 1 < coluna) && (!figura[pixels.first - 1][pixels.second + 1]) &&
		!auxPilha[pixels.first - 1][pixels.second + 1])
		{
			pilha.push({pixels.first - 1, pixels.second + 1});
			auxPilha[pixels.first - 1][pixels.second + 1] = CHEIO;
		}
		// Baixo
		if((pixels.first + 1 < linha) && (!figura[pixels.first + 1][pixels.second]) &&
		!auxPilha[pixels.first + 1][pixels.second])
		{
			pilha.push({pixels.first + 1, pixels.second});
			auxPilha[pixels.first + 1][pixels.second] = CHEIO;
		}
		// Baixo - esquerda
		if((pixels.first + 1 < linha && pixels.second - 1 >= 0) && (!figura[pixels.first + 1][pixels.second - 1]) &&
		!auxPilha[pixels.first + 1][pixels.second - 1])
		{
			pilha.push({pixels.first + 1, pixels.second - 1});
			auxPilha[pixels.first + 1][pixels.second - 1] = CHEIO;
		}
		// Baixo - direita
		if((pixels.first + 1 < linha && pixels.second + 1 < coluna) && (!figura[pixels.first + 1][pixels.second + 1]) &&
		!auxPilha[pixels.first + 1][pixels.second + 1])
		{
			pilha.push({pixels.first + 1, pixels.second + 1});
			auxPilha[pixels.first + 1][pixels.second + 1] = CHEIO;
		}
		// Direita
		if((pixels.second + 1 < coluna) && (!figura[pixels.first][pixels.second + 1]) &&
		!auxPilha[pixels.first][pixels.second + 1])
		{
			pilha.push({pixels.first, pixels.second + 1});
			auxPilha[pixels.first][pixels.second + 1] = CHEIO;
		}
		// Esquerda
		if((pixels.second - 1 >= 0 ) && (!figura[pixels.first][pixels.second - 1]) &&
		!auxPilha[pixels.first][pixels.second - 1])
		{
			pilha.push({pixels.first, pixels.second - 1});
			auxPilha[pixels.first][pixels.second - 1] = CHEIO;
		}
	}
	cout << contador << endl;
	return 0;
}