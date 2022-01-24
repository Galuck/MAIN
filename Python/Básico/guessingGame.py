
##GUESSING GAME
##########
secret_word = "Dark Souls" ##depois mudar para aceitar com letras minúsculas 
guess = ""
guess_count = 5


while guess != secret_word:##ou pode usar "and" também
    guess= input("\nEnter guess: \n")
    if(guess != secret_word):
        guess_count-=1
        print("You have", guess_count, "tries left!")
        if(guess_count==0):
            break
        else:
            print("\nTry Again!")

    
if(guess_count!=0):
    print("YOU WON!!!") 
else:
    print("YOU LOSE!")