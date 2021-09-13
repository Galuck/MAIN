
#Faça um Programa que converta metros para centímetros.             


meter=float(input("Enter the length in meter:"))   
#convert meter to cm  
centimeter  = 100 * meter;    
print("The length in centimetre is",round(centimeter,2))  #Demorei pra descobrir que precisava usar 'round'
#Parecia ser um exercício fácil mas passei quase meia hora pesquisando para ver o erro,
#python já recebe tudo automaticamente em string nos inputs aparentemente, o que me obriga a fazer casting toda santa vez
#Posso estar enganado, espero encontrar uma outra forma logo



