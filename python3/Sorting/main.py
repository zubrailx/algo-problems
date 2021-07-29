# ------------------------ merge sort algorithm ---------------------------------- #

# функция merge_two_list должна объединить два списка
def merge_two_list(a, b):
    arr = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            arr.append(a[i])
            i += 1
        else:
            arr.append(b[j])
            j += 1
    arr += a[i:]
    arr += b[j:]
    return arr


# функция merge_sort должна выполнить сортировку
def merge_sort(s):
    if len(s) == 1:
        return s
    else:
        l = merge_sort(s[:len(s)//2])
        r = merge_sort(s[len(s)//2 :])
        return merge_two_list(l, r)


# ------------------------ quick sort algorithm ---------------------------------- #
# функция quick_sort должна выполнить сортировку
def quick_sort(s):
    if len(s) <= 1:
        return s
    else:
        sr = s[0]
        lo = list(filter(lambda x: x < sr, s))
        hi = list(filter(lambda x: x > sr, s))
        eq = list(filter(lambda x: x == sr, s))
        return quick_sort(lo) + eq + quick_sort(hi)

