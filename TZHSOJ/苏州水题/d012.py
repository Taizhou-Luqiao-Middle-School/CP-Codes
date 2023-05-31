i = float(input())
a=1000.0
b = i-1000.0
if b<0:
    b=0
    a=i
result = float(a*0.95+b*0.9)
print("%.2f"%result)