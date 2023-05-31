s = input()
ABC = 0
abc = 0
num = 0
spa = 0
for i in s:
    if i.isupper():
        ABC += 1
    elif i.isalpha():
        abc += 1
    if i.isnumeric():
        num += 1
    if i.isspace():
        spa += 1
print(ABC)
print(abc)
print(num)
print(spa)
