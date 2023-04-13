dict_cpf = {}

dict_cpf['111'] = ['marcos', 22, 'masculino', 87]
dict_cpf['222'] = ['vinicius', 17, 'masculino', 75]
dict_cpf['333'] = ['julia', 18, 'feminino', 65]

maior = [dict_cpf[x] for x in dict_cpf.keys() if dict_cpf[x][1] >= 18]

print(maior)