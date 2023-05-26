a, n = input().split()
a, n = int(a), int(n)

result = 0
for i in range(n):
    result += a * (10 ** i) * (n - i)

print(result)

