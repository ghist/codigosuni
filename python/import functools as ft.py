import functools as ft 

def soma(x,y):
    return x+y

numeros = [1,2,3,4,5,10]
n = ft.reduce(soma,numeros)

print(n)