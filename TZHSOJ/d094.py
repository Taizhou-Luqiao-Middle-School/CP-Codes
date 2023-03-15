n = int(input())
f = [i for i in range(n + 1)]
k = 1
t = 0
cnt = 0
while n > 1:
    if not(1 <= t + k <= n):
        k =- k
    t = t + k
    cnt += 1
    if cnt % 3 == 0:
        print("%d " %f[t], end='')
        f.pop(t)
        if n == 3:
            print()
        if k == 1:         
            cnt = 1
            if t == n:
                t = n - 1
        else:
            cnt = 0
            if t == n:
                t = n - 1
                cnt = 1
            elif t == 1:
                cnt = 1
        n -= 1
print()
