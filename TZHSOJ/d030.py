def gcd(a,b):
    if b>0 :
        return gcd(b,a%b)
    else :
        return a
    
n,m= input().split()
n = int(n)
m=int(m)
print(gcd(n,m))
