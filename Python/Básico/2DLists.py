
##basicamente uma matriz
number_grid = [
    [1,2,3],
    [4,5,6],
    [7,8,9],
    [0]
]

##linha e coluna, x e y, nessa ordem apenas
print(number_grid[0][0])

for row in number_grid:
    print(row)

for row in number_grid:     ##mostrar elementos da matriz
    for column in row:
        print(column)