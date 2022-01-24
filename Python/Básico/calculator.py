
num1 = float (input("\nEnter the first number: "))
op =  input("\nEnter operator: ")
num2 = float (input("\nEnter the second number: "))

if (op == "+"):
    print (num1 + num2)
elif (op=="-"):
    print (num1 - num2)
elif (op=="/" ):
    print (num1/num2)
elif(op=="*" or op=="x"):
    print (num1*num2)
else:
    print("Invalid Operator")