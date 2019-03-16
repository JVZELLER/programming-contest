/*
	author: Ot�vio Augusto - OAMP
	problem_name: O Despertar da For�a
	problem_number: 2163
	category: Iniciante
	difficulty_level: 4
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2163
*/

#include <cstdio>  // Entrada e sa�da padr�o
#include <cstring>  // Utilizado p/ strtok
#include <cstdlib>  // Utilizado p/ atoi
#include <stack>  // Container

struct coord {int y = -1, x = -1;};  // Estrutura para coordenada

int main() {
  unsigned int n, m, count, posY;  // linha, coluna, contador e Pos. Y
  std::stack<coord> pilha ;  // Container de coordenada
  coord xy, stdXY;  // estrutura p/ resultado final e estrutura padr�o
  char* cPtr;  // ponteiro p/ strtok
  char str[7000];  // str p/ captura

  scanf("%d %d", &n, &m);  // atribui valores as vari�veis n e m
  getchar();  // limpa buffer
  count = n;  // atribui valor n ao contador
  int arr2d[n][m];  // dimensiona matriz de inteiros

  while (count--) {  // enquanto true?
    scanf("%[^\n]", str);  // atribui linha a vari�vel str
    getchar();  // limpa buffer
    posY = n - 1 - count;  // atribui a posi��o em Y
    cPtr = strtok(&str[0], " ");  // strtok p/ cada " "
    arr2d[posY][0] = atoi(cPtr);  //  atribui valor convertido do atoi
    for (int i = 1; i < m; ++i) {  // percorre toda a linha
      cPtr = strtok(NULL, " ");  // pr�ximo token
      arr2d[posY][i] = atoi(cPtr);  // atribui valor convertido do atoi
      if (arr2d[posY][i] == 42)  // valor � 42?
        if (posY < n - 1 & i < m - 1)  // � na ult. linha e � ult. coluna?
            pilha.push(coord{posY, i});  // empilha coordenada
    }  // fim do for
  }  // fim do while

  while (!pilha.empty()) {  // enquanto houver coordenada na pilha
    count &= 0;  // zera o contador
    xy = pilha.top(); pilha.pop();  // recebe coord. topo pilha e retira
    for (int i  = -1, iy = xy.y; i < 2; ++i) {  // loop p/ linhas
      for (int j = -1, jx = xy.x; j < 2; ++j) {  // loop p/ colunas
        if ((arr2d[iy + i][jx + j] == 7) |  // pos. == 7 ou pos (0,0) == 42?
            (arr2d[iy + i][jx + j] == 42 & i  == 0 & j == 0)) count++;
        else {  // condi��o acima n�o atendida?
            count &= 0;  // zera o contador
            break; // quebra o loop j
        }
      }  // fim do for j
      if (!(count)) break;  // contador == 0 ? quebra o loop i
    }  // fim do for i
    if (count == 9) break;  // contador == 9 ? quebra loop while
    xy = stdXY;  // atribui valores da coordenada padr�o
  }  // fim do while
  printf("%d %d\n", xy.y + 1, xy.x + 1);  // print das coordenadas
  return 0;  // fim do programa
}