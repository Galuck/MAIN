##Altura da trajetória da bala é dada pela função  H(x)= ax^2 + bx + c
# x é a quantidade de tempo após o tiro.
# ler a b c de



#considere um prisma trapezional, você deve solicitar ao usuário as informações necessárias
# e o programa deve retornar o valor da área da base desse prisma, o perímetro da base e o volume do prisma 
# V= A x H
# A= 
alturaTrapezio = float(input("Digite a altura h do TRAPÉZIO do prisma trapezoidal: \n"))
b1= float(input("Digite o lado maior da base 1: \n"))
b2= float(input("Digite o lado maior da base 2: \n"))

areaPrisma= ((b1+b2)*alturaTrapezio)/2

print("A área do prisma é", str(areaPrisma))

alturaPrisma = float(input("Digite a altura H do PRISMA do prisma trapezoidal: \n"))

volume = alturaPrisma*areaPrisma

print("O volume do prisma é", str(volume))









a = float(input("Digite um valor para A: \n"))
b = float(input("Digite um valor para B: \n"))
c = float(input("Digite um valor para C: \n"))
tempoTiro= int(input("Digite quantos segundos o tiro levou para acertar o alvo: \n"))
x=0
h=0
alturaMaxima = 0
xMaximo=0

for x in range(tempoTiro+1):
    h= (a*(pow(x,2))) + (b*x) + c
    if h>alturaMaxima:
        alturaMaxima=h
        xMaximo=x

print ("A altura máxima ocorre no tempo", xMaximo, " na altura", alturaMaxima)




