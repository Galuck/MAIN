

##Altura da trajetória da bala é dada pela função  H(x)= ax^2 + bx + c
# x é a quantidade de tempo após o tiro.
# ler a b c de

a = float(input("Digite um valor para A: \n")) #recebendo os valores de a, b, e c com INPUTS do usuário
b = float(input("Digite um valor para B: \n"))
c = float(input("Digite um valor para C: \n"))
tempoTiro= int(input("Digite quantos segundos o tiro levou para acertar o alvo: \n")) #exercício 1
x=0
h=0
alturaMaxima = 0 #tudo começando como 0
xMaximo=0

for x in range(tempoTiro+1):#for é uma repetição do código que estiver dentro dele até que uma condição seja atingida, no caso quando  o tempo digitado 

    h= (a*(pow(x,2))) + (b*x) + c   #Essa é a função para a altura máxima, no a * x^2 (usei a função pow, que vem de power do ingles, ou potência em portugues)
    #a função pow() recebe o valor para fazer a potencia primeiro e depois o valor da potencia em si (x,2)

    if h>alturaMaxima: #se a altura atual achar um valor maior que a altura máxima:
        alturaMaxima=h #a altura máxima vira a altura atual
        xMaximo=x # e xMaximo é para mostrar na tela o momento que a bala chegou na altura máxima


print ("A altura máxima ocorre no tempo", xMaximo, " na altura", alturaMaxima)#PS: a bala vai subir para sempre por causa da função original
#ou seja, o tempo máximo sempre vai ser o tempo digitado por causa disso


