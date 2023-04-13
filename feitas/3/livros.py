class Bib:

    livros = []
    
    def __init__(self, titulo, autor, data, preco_alvo):
        self._titulo = titulo
        self._autor = autor
        self._data_de_publicacao = data
        self._preco_alvo = preco_alvo
    
    def guarda(self):
      
        livro = {'titulo': self._titulo, 'autor': self._autor, 'data': self._data_de_publicacao, 'preco': self._preco_alvo}
        Bib.livros.append(livro)
      
    def exibir(self):
        print(Bib.livros)
        
    def busca(self, t):
        for i in Bib.livros:
            if i['titulo'] == t:
                print('Titulo: ', i['titulo'], "Autor: ",  i['autor'], "Data de publicação: ",  i['data'], "Preco: ",  i['preco'],)
       

i = 1
l = 0
limite = int(input("Livros para cadastrar: "))


while(i != 0):
    print('1- Cadastrar')
    print('2- Informações')
    print('3- Buscar')
    print('0- Sair')
    op = input("Opção: ")
    
    if op == '1':
        if l < limite:
            titulo = input('Titulo: ')
            autor = input('Autor: ')
            data = input('Data de publicação: ')
            preco = input('Preco: ')
            bb = Bib(titulo, autor, data, preco)
            bb.guarda()
            l+=1
        else:
            print("Limite atingido")                    
    elif op == '2':
        bb.exibir()
    elif op == '3':
        t = input("Titulo do Livro: ")
        bb.busca(t)
    elif op == '0':
        print("Programa finalizado")
        i = 0
        break
    else:
        print("Opção errada")