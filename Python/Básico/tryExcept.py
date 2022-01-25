
def translator(phrase):
    translation = ""
    for letter in phrase:
        if letter in "AEIOUaeiou":
            translation = translation + "g"
        else:
            translation = translation + letter
    return translation
try:
    print (translator(input("\nEnter a phrase: ")))
except:
    print("Invalid Input")

