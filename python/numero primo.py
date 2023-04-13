lista_numero = range(1, 100)

for num in lista_numero:
    divisiveis = [x for x in range(1, num+1) if num % x == 0]

    if len(divisiveis) == 2:
        print('É primo')
        
    else:
        print('Não é primo')
        
    print(divisiveis)