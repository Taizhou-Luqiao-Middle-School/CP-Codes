n = int(input().strip())

for i in range(1, n+1):
    print(' ' * (n-i) + ''.join(str(j % 10) for j in range(1, i+1))[:-1] + ''.join(str(j % 10) for j in range(i, 0, -1)))

