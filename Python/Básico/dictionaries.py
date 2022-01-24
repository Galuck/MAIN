#Jan -> January
#Mar -> March

monthConversion = {
    "Jan": "January",
    1: "January",
    "Feb": "February",
    2: "February",
    "Mar": "March",
    3: "March",
    "Apr": "April",
    4: "April",
    "May": "May",
    5: "May",
    "Jun": "June",
    6: "June",
    "Jul": "July",
    7: "July",
    "Aug": "August",
    8: "August",
    "Sep": "September",
    9: "September",
    "Oct": "October",
    10: "October",
    "Nov": "November",
    11: "November",
    "Dec": "December",
    12: "December"
}

print (monthConversion["Nov"])
##ou 
print (monthConversion.get("Dec"))

##Se não estiver no dicionario, vai printar "None"
print (monthConversion.get("Random"))

## Fazendo o mesmo, é possível adicionar um valor default
print (monthConversion.get("Random", "Not a valid Key"))