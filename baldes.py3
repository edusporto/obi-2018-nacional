def abs(n):
    if n < 0:
        return 0-n
    return n

def get_menor(l):
    menor = 1000001
    for x in l:
        if x < menor:
            menor = x
    return menor

def get_maior(l):
    maior = 0
    for x in l:
        if x > maior:
            maior = x
    return maior

linha = input().split(" ")
N = int(linha[0])
M = int(linha[1])

linha = input().split(" ")
baldes = []
for x in range(N):
    baldes.append([int(linha[x])])

operacoes = []
for x in range(M):
    linha = input().split()
    operacoes.append([int(linha[0]), int(linha[1]), int(linha[2])])

def tratar_operacao(operacao):
    # operacao 1
    if operacao[0] == 1:
        baldes[operacao[2] - 1].append(operacao[1])
    else: # operacao 2
        inicio = operacao[1] - 1
        fim = operacao[2]

        maior_diferenca = 0
        for n in range(inicio, fim):
            for m in range(n+1, fim):
                diferenca_atual = abs(get_maior(baldes[n]) - get_menor(baldes[m]))
                if diferenca_atual > maior_diferenca:
                    maior_diferenca = diferenca_atual
                    
                diferenca_atual = abs(get_menor(baldes[n]) - get_maior(baldes[m]))
                if diferenca_atual > maior_diferenca:
                    maior_diferenca = diferenca_atual
                    
        # a partir daqui, ja sabe a maior diferenca
        print(maior_diferenca)
 
for x in range(M):
    tratar_operacao(operacoes[x])
