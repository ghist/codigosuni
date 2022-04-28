class Caixa:
    def __init__(self, valor):
        self.valor = valor

    def get_valor(self):
        return self.valor

    def set_valor(self, valor):
        self.valor = valor
    def Sacar(self):
        notas = [100, 50, 20, 10, 5, 2, 1]
        notas_sacadas = []
        contador = 0
        while (True):
            if self.valor >= notas[contador]:
                self.valor -= notas[contador]
                notas_sacadas.append(notas[contador])
            else:
                contador += 1
            if contador == len(notas):
                break
        return notas_sacadas

valor = int(input("valor do cheque: "))

cheque = Caixa(valor)

print(cheque.Sacar())
