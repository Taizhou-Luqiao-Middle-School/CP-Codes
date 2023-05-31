a = list(map(int, input().split()))
ans = 0
for i in range(0, len(a)):
    if a[i] <= 0:
        ans += a[i]
print(ans)
