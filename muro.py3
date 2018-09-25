N = int(input())

if N == 0:
    print("1")
    quit()

if N == 1:
    print("1")
    quit()

def func(valor):
    if valor <= 0:
        return 1

    qtd = 0
    if valor-1 > 1:
        qtd += 1
        qtd += func(valor-1)
    if valor-2 >= 0:
        qtd += 1
        qtd += func(valor-2) * 4
    if valor-3 >= 0:
        qtd += 1
        qtd += func(valor-3) * 2

    return qtd

resp = func(N)

print(resp % (10**9 + 7))
