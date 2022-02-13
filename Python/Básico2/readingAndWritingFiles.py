
def mostrar_texto():
    arquivo_de_texto = open("testesDeTexto.txt", "r")
    daPraLer = arquivo_de_texto.readable()
    if(daPraLer==True):
        print(arquivo_de_texto.read())

        #le a primeira linha, depois, na segunda execução, le a próxima, e assim em diante
        #print(arquivo_de_texto.readline())
        #linha especifica:
        #print(arquivo_de_texto.readline()[1])

        #ou, para printar linha por linha
        #for frase in arquivo_de_texto.readlines():
        #    print(frase)

    arquivo_de_texto.close()

####
##como o txt está na mesma pasta, não precisa especificar
#open("testesDeTexto.txt")

#para ler, usar o modo read "r" ou "w" para write   ou "a" para append (add) 
#para ler e escrever, usar "r+"
#é bom guardar o valor numa variável
arquivo_de_texto = open("testesDeTexto.txt", "r")

#checar se da pra ler
daPraLer = arquivo_de_texto.readable()



arquivo_de_texto = open("testesDeTexto.txt", "a")

arquivo_de_texto.write("\nEssa linha foi adicionada no arquivo por codigo\n")

mostrar_texto()

#escreve mas apaga as linhas do código
arquivo_de_texto = open("testesDeTexto.txt", "w")
arquivo_de_texto.write("Essa linha foi adicionada ao apagar o resto das linha com overwrite\n")

#Quando o nome não existe, provavelmente vai criar um novo
#arquivo_de_texto = open("testesDeTextoNOVO.txt", "w")


#depois de abrir, TEM que fechar 
arquivo_de_texto.close()






