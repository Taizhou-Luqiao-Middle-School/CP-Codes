def j (n):
    s = 1
    for i in range(1,n+1):
        s *= i
    return s
e=1
n=int(input())
for i in range (1,n+1,1):
    e = e + 1 / j(i)
print("%.10f"%e)