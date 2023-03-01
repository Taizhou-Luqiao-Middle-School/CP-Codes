n=int(input())
m=0
for i in range(0,n):
    x=int(input())
    if i==0:
        m=x
        continue
    if m<x:
        x=m
print (m)