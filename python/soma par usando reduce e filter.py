import functools as ft 

lista = []

'''
def ispar(n):
    return n%2 == 0

def soma(x, y):
    return x+y
'''

while True:
    n = int(input('digite um numero: '))
    if n < 0:
        break
    else:
        lista.append(n)

par = filter(lambda x: x%2==0, lista)

soma = ft.reduce(lambda x,y: x+y, par)

print(soma)