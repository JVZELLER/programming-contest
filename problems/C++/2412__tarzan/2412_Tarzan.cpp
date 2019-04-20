/*
	author: Ot�vio Augusto - OAMP
	problem_name: Tarzan
	problem_number: 2412
	category: Ad-hoc
	difficulty_level: 8
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2412
*/

#include <cstdio>  // entrada e sa�da padr�o
#include <queue>  // estrutura FIFO

/* Struct p/ coordenadas x e y de uma �rvore
* dist indica se a �rvore � alcan�ada */
struct coord { int x, y; bool dist = false; };

int d;  // tam. m�x. do cip� - global p/ uso na fun��o abaixo

inline bool dist(coord& c1, coord& c2) {
  return ((c1.x - c2.x) * (c1.x - c2.x) +
            (c1.y - c2.y) * (c1.y - c2.y)) <= d*d;
}  // retorna true se dist�ncia entre as �rvores <= dist�ncia do cip�

int main() {
  coord vC[1000];  // array com tam. m�x de �rvores restantes
  std::queue<int> q({0});  // fila inicializada com {0}
  int n, i, j, cnt = 0;  // n qtd �rvores - i, j index - cnt �rvores alcan�adas

  scanf("%d %d", &n, &d);  // entrada qtd �rvores e tam. m�x. cip�
  for (i = 0; i < n; ++i)  // loop p/ qtd �rvores
    scanf("%d %d", &vC[i].x, &vC[i].y);  // entrada p/ coordenadas da �rvore

  while (!q.empty()) {  // enquanto fila n�o estiver vazia
    i = q.front(); q.pop();  // atrib. inicio da fila p/ i, remove item inicio
    for (j = 0; j < n; ++j) {  // loop p/ qtd �rvores restantes
      if (i == j) continue;  // posi��es das �rvores iguais ? pr�xima itera��o
      if (!vC[j].dist)  // posi��o n�o alcan�ada?
        if(dist(vC[j], vC[i])) {  // �rvore alcan�ada?
            vC[j].dist = true;  // indica que �rvore foi alcan�ada
            q.push(j);  // insere posi��o na fila
            ++cnt;  // +1 p/ contador de �rvores alcan�adas
        }  // fim if �rvore alcan�ada
    }  // fim for j
  }  // fim enquanto
  cnt == n ? printf("S\n") : printf("N\n");  // cnd == n ? imprime S se n�o N
  return 0;  // fim do programa
}