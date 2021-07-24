char = [chr(x) for x in range(65, 65 + 26)]


text = str(input())                     # for print
text_s = [x for x in text.split(' ')]   # for spaces
word_l = []                             # for step
for i in range(text_s.__len__()):
    count = 0
    for a in text_s[i]:
        if a.isalpha():
            count += 1
    word_l.append(count)

iterator = 0
for c in text:
    if c == ' ':
        iterator += 1
    if c.upper() not in char:
        print(c, end='')
    else:
        temp = char[(char.index(c.upper()) + word_l[iterator]) % len(char)]
        if c.islower():
            temp = temp.lower()
        print(temp, end='')
