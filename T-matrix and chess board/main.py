from matrix import *

n = int(input())
matrix = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for j in range(i):
        matrix[i][j] = matrix[n - 1 - i][n - 1 - j] = abs(i - j)
print_matrix(matrix)