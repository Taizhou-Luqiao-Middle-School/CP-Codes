a = input()
a1 = 0
for i in a:
    if i == '1':
        a1 += 1
if a == '0':
    print(0)
elif a1 % 2 == 0:
    print(a[0: len(a) - 2], end='')
    print(0)
else:
    print(a[0: len(a) - 2], end='')
    print(1)
