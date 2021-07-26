def print_matrix(matrix):
    [print(*matrix[i]) for i in range(len(matrix))]


def back_trans_matrix(matrix):
    for i in range(len(matrix)//2):
        for j in range((len(matrix)+1)//2):
            pr = matrix[n-1-i][n - 1 - j]
            matrix[n-1-i][n-1-j] = matrix[n-1-j][i]
            matrix[n-1-j][i] = matrix[i][j]
            matrix[i][j] = matrix[j][n - 1 - i]
            matrix[j][n-1-i] = pr


def set_knight(matrix, cord):
    r, c = ord(cord[0]) - ord('a'), int(cord[1]) - 1
    matrix[r][c] = 'N'
    for i in range(len(matrix)):
        for j in range(matrix[0].__len__()):
            if abs(r - i) + abs(c - j) == 3 and max(abs(r - i), abs(c - j)) == 2:
                matrix[i][j] = '*'


n = 8
matrix = [['.' for i in range(n)] for j in range(n)]

cord = [x for x in input()]
set_knight(matrix, cord)
back_trans_matrix(matrix)
print_matrix(matrix)


