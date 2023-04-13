par = []
impar = []
zeros = []
n = 0

while n >= 0:
    n = int(input('Digite um valor: '))
    if n < 0:
        break
    elif n == 0:
        zeros.append(n)
    elif n%2 == 0:
        par.append(n)
    else:
        impar.append(n)

par.sort()
impar.sort()

print(par + zeros + impar)
