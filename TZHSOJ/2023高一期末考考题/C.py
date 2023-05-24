import math as m
 
a = float(input())
 
a = m.ceil(a)
 
if a <= 3:
    print(10)
else:
    print(10 + (a - 3) * 2)