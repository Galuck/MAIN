#considere um prisma trapezional, você deve solicitar ao usuário as informações necessárias
# e o programa deve retornar o valor da área da base desse prisma, o perímetro da base e o volume do prisma 
# V= A x H
# A= 1/2(b1+b2)h
alturaTrapezio = float(input("Digite a altura h do TRAPÉZIO do prisma trapezoidal: \n"))#recebendo os valores como float
b1= float(input("Digite o lado maior da base 1: \n"))
b2= float(input("Digite o lado maior da base 2: \n"))#converte para float (decimal), para caso o numero desejado seja decimal

areaPrisma= ((b1+b2)*alturaTrapezio)/2  # A= 1/2(b1+b2)h
areaBaseMaior= b2*alturaTrapezio   #calculo da area da base 

print("A área do prisma é:", str(areaPrisma))#converter para string para o valor ficar mais bonitinho e ter menos chance de dar erro
print("A área da base é:", str(areaBaseMaior))#mostrando a area do prisma e a área da base

alturaPrisma = float(input("Digite a altura H do PRISMA do prisma trapezoidal: \n")) #recebendo a altura do prisma pelo input do usuário

volume = alturaPrisma*areaPrisma #calculo do volume   V= A x H

print("O volume do prisma é:", str(volume))#mostrando o volume calculado

perimetro = (2*b1) + (2*b2) + (4*alturaPrisma)  #perimetro do prisma trapezoidal
print("\nO perimetro do prisma é:", str(perimetro)) #mostrando o perimetro calculado



