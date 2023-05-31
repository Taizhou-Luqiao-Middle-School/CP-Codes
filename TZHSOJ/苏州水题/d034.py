a,b,c=input().split()
a=float(a)
b=float(b)
c=float(c)
p = float((a+b+c)/2.0)
if a+b<=c or a+c<=b or b+c<=a:
    print("Data Error!")
else:
    s = (p*(p-a)*(p-b)*(p-c))**0.5
    print("%.2f"%s)