def calculate(number, ss):
    result_alt = 0
    iter = 0
    while number > 0:
        ost = number % 10
        if ost >= ss:
            return None
        else:
            result_alt += ost * ss**iter
            iter += 1
            number //= 10
    return result_alt


result = 88
sum_arr = [32, 22, 16, 17]
ss = 0
hasFound = False
while not hasFound:
    ss += 1
    # convert the first value using ss
    result_alt = calculate(result, ss)
    if result_alt is None:
        continue
    # convert other values
    isOk = True
    sum_alt = 0
    for s in sum_arr:
        s_alt = calculate(s, ss)
        if s_alt is None:
            isOk = False
            break
        else:
            sum_alt += s_alt
    if not isOk:
        continue
    # find the result
    if sum_alt == result_alt:
        print(ss)
        hasFound = True
