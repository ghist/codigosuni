def ispar(n):
    return n%2 == 0 and n != 0

numeros = [0, 1, 2, 3, 4]

pares = filter(ispar, numeros)
for x in pares:
    print(x)