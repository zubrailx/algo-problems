def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in matrix[i]:
            print(str(j), end=' ')
        print()


def multiply_matrix(matrix1, matrix2):
    matrix3 = [[0 for _ in range(len(matrix2[-1]))] for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[-1])):
            for k in range(len(matrix2)):
                matrix3[i][j] += (matrix1[i][k] * matrix2[k][j])
    return matrix3


def is_symmetrical_to_the_side_diagonal(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(0, n - 1 - i):
            if matrix[i][j] != matrix[n - 1 - j][n - 1 - i]:
                return False
    return True


def is_latin_square(matrix: list):
    n = len(matrix)

    # cuz i dont want to repeat the code
    def check_by_rows():
        for i in range(n):
            c = 1
            while c != n + 1:
                if matrix[i].count(c) == 1:
                    c += 1
                else:
                    return False
        return True

    # check the matrix
    if not check_by_rows():
        return False
    matrix = transpose_matrix(matrix)
    return check_by_rows()


def transpose_matrix(matrix: list):
    n = len(matrix)
    new_matrix = [[-1 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            new_matrix[j][n - 1 - i] = matrix[i][j]
    return new_matrix


def matrix_turn_90_counterclockwise(matrix):
    n = len(matrix)
    for i in range(len(matrix) // 2):
        for j in range((len(matrix) + 1) // 2):
            pr = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[i][j]
            matrix[i][j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = pr


def set_queen(matrix, cord):
    n = len(matrix)
    r, c = ord(cord[0]) - ord('a'), int(cord[1]) - 1
    crr = '*'
    matrix[r][c] = 'Q'
    for i in range(n):
        for j in range(n):
            if abs(i - r) + abs(j - c) != 0 and (abs(i - r) == abs(j - c) or abs(i - r) == 0 or abs(j - c) == 0):
                matrix[i][j] = crr
