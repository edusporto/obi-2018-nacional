bolas = input().split(" ")

for n in range(len(bolas)):
    bolas[n] = int(bolas[n])

possivel = True
tamanho = len(bolas)
for n in range(tamanho):
    if n != tamanho-1:
        if bolas[n] == bolas[n + 1]:
            conseguiu = False
            for x in range(len(bolas)):
                if bolas[n] != bolas[x]:
                    if x == 0:
                        if bolas[n] != bolas[x+1]:
                            bolas[x], bolas[n] = bolas[n], bolas[x]
                            conseguiu = True
                    elif x == n:
                        if bolas[n] != bolas[x-1]:
                            bolas[x], bolas[n] = bolas[n], bolas[x]
                            conseguiu = True
                    else:
                        if bolas[n] != bolas[x-1]:
                            if bolas[n] != bolas[x+1]:
                                bolas[x], bolas[n] = bolas[n], bolas[x]
                                conseguiu = True
            if not conseguiu: possivel = False
            
if possivel:
    print("S")
else:
    print("N")
                

