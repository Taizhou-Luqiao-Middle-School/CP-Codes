b =input()

num = 0

a=b.replace("余洋","2B")
a=b.replace("YY","2B")
a=b.replace("yvyang","2B")


for i in range(0, len(a)):
    if '0' <= a[i] <= '9':
        num += int(a[i])

    elif 'A' <= a[i] <= 'F':
        num += int(ord(a[i]) - ord('A') + 10)

    else:
        num += int(ord(a[i]) - ord('a') + 10)

    num *= 16

num /= 16
print(int(num))
