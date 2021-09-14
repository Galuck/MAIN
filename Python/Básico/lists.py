lista= ["Kevin", 2, 5.5, True, False]
#         0      1   2     3     4     INDEX
print (lista)#vai printar tudo na lista

print(lista[3], "  #vai printar apenas o terceiro elemento, true")
print(lista[4])
print(lista[2])
print(lista[0], "  #como em basicamente toda linguagem, começa no zero")

print(lista[-1], "  #com sinal negativo, printa de trás pra frente")
print(lista[-2])

print(lista[2:], "  #vai printar tudo do2 pra frete")
print(lista[0:3])#printa só do 0 ao 2, até o 3, mas n inclui o 3

lista[0]="Mike Wazowski"
print(lista[0])
################################################################

#lists functions

#   extend

numeros=[8,5,6,4,3,22,4]

lista.extend(numeros)   # extend adiciona listas

print(lista)

#append

lista.append("Mais um") #adiciona mais um elemento no fim da lista em questão

print(lista)

#insert
###        index       elemento
lista.insert(3, "Inserido no meio")#vai inserir no index dito, e vai mover todo o resto para o lado 
print(lista)

#remove

lista.remove(False)#meio obvio
print(lista)

#clear

lista.clear()   #vai deletar tudo na lista
print(lista)

lista=["Jonathan", "Mike", "Hugo"]

#pop

lista.pop() #Hugo vai sair da lista
print(lista)#faz todo o papel do pop de c, remove o ultimo elemento da lista

#index 

print(lista.index("Mike"))#vai printar o index dessa variavel em específico (precisa do print)

#count

lista.append("Geralt")
lista.append("Geralt")

print(lista, " is the new list!\n")
print(lista.count("Geralt"))    #vai retornar a qtd de elementos com essa característica


#sort


lista= ["Geralt", "Abby", "Joel", "Queelana", "Amy", "Jake"]
print(lista, "-> lista antes de organizar \n")
lista.sort()
print(lista, "-> lista organizada")

lista= [30,45,2.5, 3,1,8,567,1.4,6,13,89,47,21,0]
print(lista, "-> lista antes de organizar \n")
lista.sort() 
print(lista, "-> lista organizada\n")

#basicamente elimina a necessidade de Estrutura de Dados KKKK

#reverse

lista.reverse()
print(lista, "-> lista invertida")  
#a mesma coisa que o sort só que invertido (resultado fica até mudar, não só no print)


#copy 

lista2 = lista.copy()
print(lista2)

