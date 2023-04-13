def iszero(n):
    if n == 0:
        return True
    else:
        return False

def ispar(n):
    if n % 2 == 0 and n != 0:
        return True
    else:
        return False

def isimpar(n):
    if n % 2 == 1 and n != 0:
        return True
    else:
        return False

lista = []

while True:
    n = int(input('Digite um valor: '))
    if n < 0:
        break
    else:
        lista.append(n)

par = list(filter(ispar, lista))
impar = list(filter(isimpar, lista))
zeros = list(filter(iszero, lista))

par.sort()
impar.sort()

print(par + zeros + impar)