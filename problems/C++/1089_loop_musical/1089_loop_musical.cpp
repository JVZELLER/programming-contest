/*
	author: Ot�vio Augusto - OAMP
	problem_name: Loop Musical
	problem_number: 1089
	category: Ad-hoc
	difficulty_level: 3
	link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1089
*/


#include <cstdio>  // entrada e sa�da padr�o

int main () {
    bool flg;  // flg para inflex�o (sentido do pico)
    int n, i, picos, v[10001];  // variaveis da solu��o
    char bff[7000], *ptr = &bff[0];  // buffer p/ resultado
    
    while (scanf("%d", &n) && n) {  // entrada para qtde de valores
        for (i = 0; i < n; ++i)  // loop p/ entrada de valores
            scanf("%d", &v[i]);  // entrada de valores

        flg = (v[n - 1] < v[0]);  // atribui resultado da expr p/ flg
        for(picos = i = 0; i < n; ++i)  // loop p/ todos os valores
            if ((v[i] < v[(i + 1) % n]) != flg) {  // h� uma inflex�o?
                ++picos;  // acresce 1 ao contador de picos
                flg = !flg;  // inverte flg
            }
        ptr += sprintf(ptr, "%d\n", picos);  // concatena resp. no buffer
    }
    printf("%s", bff);  // imprime resultado
    return 0;  // fim do programa
}