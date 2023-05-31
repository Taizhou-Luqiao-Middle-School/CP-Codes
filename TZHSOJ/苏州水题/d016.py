a,b,c=input().split()
a=float(a)
b=float(b)
c=float(c)
delta = b*b - 4*a*c
if delta<0:
    print("No answer!")
elif delta<0.005:
    delta=0
    r = (-b)/2/a
    print("%.2f"%r)
else :
    r1 = (-b+delta**0.5)/2/a
    r2 = (-b-delta**0.5)/2/a
    print("%.2f"%r1)
    if r2!=r1:
        print("%.2f"%r2)