N = int(input())
numeros = input().split(" ")

for x in range(N):
    numeros[x] = int(numeros[x])

d = []
for n in range(N):
    if numeros[n] == 0 or numeros[n] == 5:
        d.append((n, numeros[n]))

if len(d) == 0:
    print("-1")
    quit()

resultados_possiveis = []
for x in d:
    l = numeros[:]
    l[x[0]], l[N-1] = l[N-1], l[x[0]]
    resultados_possiveis.append(l)

maior = resultados_possiveis[0]
for n in range(len(resultados_possiveis)):
    if str(resultados_possiveis[n]) > str(maior):
        maior = resultados_possiveis[n]

resp = ""
for n in maior:
    resp += str(n) + " "

print(resp[:-1])
    
