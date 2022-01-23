is_male = True ## True, com T maiusculo


if is_male:
    print("You are a male.")


if is_male==False:
    print("male = Falso")
else:
    print("Male=True")


if is_male or is_male==False:
    print("Entered with 'or'")

isTall=True

if is_male and isTall==False:
    print("entrou no AND")
elif is_male and not isTall: ## else if = elif 
    print("print")
elif not is_male or is_male==False:
    print("x")


#################
print ("\nMais if statements")

def max_num(num1, num2, num3):
    if num1  >= num2 and num1 >= num3:
        return num1
    elif num2 >= num1 and num2  >= num3:
        return num2
    else:
        return num3

print(max_num(2,3,4),"é o maio valor")
print(max_num(8,5,3),"é o maio valor")
print(max_num(24,30,6),"é o maio valor")