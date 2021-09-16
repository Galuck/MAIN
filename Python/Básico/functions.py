#funçoes, como fazer uma?

#def para definir a função
def say_Hi():          
    #identar para ficar dentro da função
    name = input("Type your name!\n")
    print("Hi", name)

say_Hi()#chamar a função

#resto funciona quase igual ao C

def mostrar_soma(a,b):
    print(int(a)+int(b))

mostrar_soma(4,5)#printou 9


#return

def elevar_numero_ao_cubo(a):
    resultado= a*a*a
    return resultado #assim como no C, após o return ser chamado, a função fecha

resultado2=elevar_numero_ao_cubo(2)

print(resultado2)