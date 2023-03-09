def f(a):
    s = 0
    for i in range(1,a):
        if a%i==0:
            s+=i
    if s==a:
        return 1
    else :
        return 0

a,b,c,d,e = input().split()
a= int(a)
b=int(b)
c=int(c)
d=int(d)
e=int(e)
ans = str(f(a)) + ' ' + str(f(b)) + ' ' + str(f(c)) + ' ' + str(f(d)) + ' ' + str(f(e))
print(ans)