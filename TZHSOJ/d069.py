s = input()
n = ord(s[0:1]) - 64
for i in range(1, 2*n):
    k1 = abs(i - n)
    for j in range(k1):
        print(" ", end="")
    k2 = n - k1
    for j in range(2 * k2 - 1):
        print(chr(64 + k2), end="")
    print()
    
