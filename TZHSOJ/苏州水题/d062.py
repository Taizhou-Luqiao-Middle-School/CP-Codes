a = int(input())
if a == 1:
    print(1)
while a != 1:
    for i in range(2, a + 1):
        if a % i == 0:
            a = a // i
            if a != 1:
                print(i, end="*")
            else:
                print(i)
            break
