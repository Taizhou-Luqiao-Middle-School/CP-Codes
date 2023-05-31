def gcd (a,b):
    if b!=0:
        return gcd(b,a%b)
    else :
        return a
    
a,b=input().split()
a=int(a)
b=int(b)
print(int(a*b/gcd(a,b)))