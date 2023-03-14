def jc(a):
    if a==1:
        return 1
    elif a==0:
        return 1
    else:
        return a*jc(a-1)
a,b,c,d=input().split()
a=int(a)
b=int(b)
c=int(c)
d=int(d)
c1=jc(a)/(jc(b)*jc(a-b))
c2=jc(c)/(jc(d)*jc(c-d))
print(int(c1)+int(c2))
 
