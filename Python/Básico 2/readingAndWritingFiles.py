

####
##como o txt está na mesma pasta, não precisa especificar
#open("testesDeTexto.txt")

#para ler, usar o modo read "r" ou "w" para write   ou "a" para append (add) 
#para ler e escrever, usar "r+"
#é bom guardar o valor numa variável
arquivo_de_texto = open("testesDeTexto.txt", "r")

print

#depois de abrir, TEM que fechar 
arquivo_de_texto.close()






open("testesDeTexto.txt", "r+")