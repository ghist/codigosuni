import random
i = 0
l = 0
n = 0
count = 0

l = int(input('Informe o limite: '))
n = int(input('Informe qts numeros: '))

lista = []
while n > 0:
    x = random.randint(i, l)
    if x not in lista:
        lista.append(x)
        n = n - 1

print(lista)