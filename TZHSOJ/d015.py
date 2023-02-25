a,b,o=input().split()
a=float(a)
b=float(b)
r = 0.0
if o=='+':
    r=a+b
    print("%.2f"%r)
if o=='-':
    r=a-b
    print("%.2f"%r)
if o=='*':
    r=a*b
    print("%.2f"%r)
if o=='/':
    r=a/b
    print("%.2f"%r)