a = int(input())
for i in range(1, a + 1, 1):
        print(' ' * (a - i) + '*' * (2 * i - 1))
for i in range(1, a, 1):
        print(' ' * i + '*' * (2 * a - 1 - i * 2))
