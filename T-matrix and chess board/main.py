def print_matrix(matrix):
    [print(*matrix[i]) for i in range(len(matrix))]


def back_trans_matrix(matrix):
    n = matrix.__len__
    for i in range(len(matrix) // 2):
        for j in range((len(matrix) + 1) // 2):
            pr = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[i][j]
            matrix[i][j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = pr


def set_knight(matrix, cord):
    r, c = ord(cord[0]) - ord('a'), int(cord[1]) - 1
    matrix[r][c] = 'N'
    for i in range(len(matrix)):
        for j in range(matrix[0].__len__()):
            if abs(r - i) + abs(c - j) == 3 and max(abs(r - i), abs(c - j)) == 2:
                matrix[i][j] = '*'


def check_values(matrix, value):
    n = matrix.__len__
    length = len(matrix)
    is_good = sum([True for i in range(length) if sum(matrix[i]) == value]) == length
    is_good += sum([matrix[i][i] for i in range(length)]) == value and \
               sum([matrix[i][n - 1 - i] for i in range(length)]) == value
    return is_good == 2


def check_numbers(matrix):
    count = 0
    for i in range(1, len(matrix)*len(matrix) + 1):
        count += any([[True for j in nested if j == i] for nested in matrix])
    return count == len(matrix) * len(matrix)


