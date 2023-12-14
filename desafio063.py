#Codigo para a realização de uma progressão aritmética
#Autor: Pedro Henrique Costa Dias
#Data de Ultima Alteração: 13/12/2023 as 22:28

#leitura do valor inicial e a razão de progressão a ser usada, além da inicialização de variáveis
Primeiro = int(input('Informe o primeiro termo: '))
Razao = int(input('Informe a razão da progressão '))
cnt = 0
additional = 1
final = 0
#Estrutura de repetição para as 10 primeiras progressões, usando uma variável de contagem cnt
while cnt != 10:
    print(Primeiro+(cnt*Razao), end=' ')
    cnt += 1
print('PAUSE')
#Se salva o ultimo numero da progressão acima, e se prepara para checar se o usuário deseja realizar progressões
#adicionais.
final = Primeiro + (cnt * Razao)
while additional != 0:
    cnt = 0
    additional = int(input('Quantos termos a mais quer mostrar? '))
    if additional != 0:
        while cnt != additional:
            print(final + (cnt * Razao), end=' ')
            cnt += 1
        final = final + (cnt * Razao)
        print('PAUSE')
    else:
        print('Fim do programa!')