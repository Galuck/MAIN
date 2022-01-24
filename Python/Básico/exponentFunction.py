##diferente das outras linguagens

print(2**3)

#ou
num = 2
pow(num, 2)
print (num)

#ou (Exponent Function)

def raise_toPower(base_num, power_number):
    result=1
    for index in range(power_number):
        result = result * base_num
    return result

print(raise_toPower(3,3))