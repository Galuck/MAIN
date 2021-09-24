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