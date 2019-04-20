'''
	author: zeller
	problem_name: Fechem as Portas
	problem_number: 1371
	category: Matemática
	difficulty_level: 4
    link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1371
'''
while True:
    a, i = int(input()), 2
    if a == False: break
    j = i*i
    resposta = "1"
    while(j <= a):
        resposta += " " + str(j)
        i, j = i + 1, (i+1)*(i+1)
    print(resposta)