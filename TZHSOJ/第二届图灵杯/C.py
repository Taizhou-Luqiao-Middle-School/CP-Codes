n, x, y = map(int, input().split())

ans = 1e9

for i in range(0, n):
    a = i % y + (n - i) % x
    if i % y == 0 and (n - i) % x == 0:
        a += min(y, x)
    ans = min(ans, a)
    
print(ans)