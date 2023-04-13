import math

class Ponto:
    def __init__(self,x,y):
        self.x = x
        self.y = y
class Distancia:
    def __init__(self,p1,p2):
        self.p1 = p1
        self.p2 = p2
    def calcular(self):
        return math.sqrt(math.pow((self.p1.x - self.p2.x),2) + math.pow((self.p1.y - self.p2.y),2))

pon = []

cont = 0

while(cont < 10):
    ponto = input().split()
    pon.append(Ponto(float(ponto[0]),float(ponto[1])))
    cont += 1
cont = 1
while(cont < 10):
    distancia = Distancia(pon[0],pon[cont])
    if cont == 1:
        menor = "a menor distancia é entre o primeiro ponto é " + str(distancia.calcular()) + " que é em relação ao ponto " + str(cont)
        valor = distancia.calcular() 
    elif distancia.calcular() < valor:
        menor = "a menor distancia é entre o primeiro ponto é " + str(distancia.calcular()) + " que é em relação ao ponto " + str(cont) 
    cont += 1
print(menor)