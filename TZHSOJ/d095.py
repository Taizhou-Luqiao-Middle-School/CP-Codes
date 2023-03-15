s = input()
a = 0
b = 0
c = 0
for i in s:
    if 'a' <= i <= 'z' or 'A' <= i <= 'Z':
        a += 1
    elif  '0' <= i <= '9':
        b += 1
    elif i == '?':
        break
    else:
        c += 1
print('%d \n%d \n%d'%(a, b, c))
