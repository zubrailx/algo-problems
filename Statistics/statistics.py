def dispersion(in_list: list):
    av = average(in_list)
    sk = 0
    for el in in_list:
        sk += (el - av) ** 2
    return sk / (len(in_list) - 1)


def average(in_list: list):
    return sum(in_list) / len(in_list)


def standard_deviation(in_list: list):
    return pow(dispersion(in_list), 0.5)


def standard_error(n: int, sd: float):
    return sd / pow(n, 0.5)


def confidence_interval_95(se: float, mean: float):
    return list([mean - se * 1.96, mean + se * 1.96])
